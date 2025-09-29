#include "Experiment.h"
#include <iostream>
#include <stdexcept>

using namespace std;

Experiment::Experiment(int n, int m) : n(n), m(m), stats(nullptr) {
    if (n <= 0) {
        throw invalid_argument("Board size must be positive");
    }
    if (m < 0) {
        throw invalid_argument("Number of picks m must be non-negative");
    }

    frequencies.assign(n * n, 0);
}

Experiment::~Experiment() {
    delete stats;
}

void Experiment::run() {
    RandomCell gen(n);

    for (int i = 0; i < m; ++i) {
        auto [row, col] = gen();
        size_t index = static_cast<size_t>(row) * static_cast<size_t>(n) + static_cast<size_t>(col);
        ++frequencies[index];
    }

    delete stats;
    stats = new Statistics(frequencies.begin(), frequencies.end());
}

void Experiment::printResults() const {
    if (!stats) {
        cerr << "Experiment not run yet!\n";
        return;
    }

    try {
        cout << "Mean: " << stats->average() << '\n';
        cout << "Median: " << stats->median() << '\n';
    } catch (const exception& e) {
        cerr << "Error calculating statistics: " << e.what() << '\n';
    }
}

