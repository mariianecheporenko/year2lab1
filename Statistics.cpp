#include "Statistics.h"

#include <algorithm>
using namespace std;

Statistics::Statistics(const vector<int>& freqs) : frequencies(freqs) {}

double Statistics::averageCount() const {

    long long sum = 0;
    for (int i = 0; i < frequencies.size(); i++) {
        sum+=frequencies[i];
    }
    return (double)sum / frequencies.size();
}

double Statistics::medianCount() {
    vector<int> sorted = frequencies;
    sort(sorted.begin(), sorted.end());

    int n = sorted.size();
    if (n % 2 == 0) {
        return sorted[n / 2];
    }
    return (sorted[n / 2 - 1] + sorted[n / 2]) / 2.0;
}
