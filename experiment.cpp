#include "Experiment.h"
#include "RandomCell.h"
#include "Board.h"
#include <iostream>

using namespace std;

Experiment::Experiment(int n, int m) : n(n), m(m), stats(nullptr) {
     frequencies.assign(n * n, 0);
}

Experiment::~Experiment() {
    delete stats;
}

void Experiment::run() {
    Board board(n);
    RandomCell gen(n);

    for (int i = 0; i < m; ++i) {
        auto [row, col] = gen();
        size_t index = board.idx(row, col);
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

