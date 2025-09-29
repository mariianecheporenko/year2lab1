#include "Statistics.h"

#include <algorithm>
#include <numeric>
using namespace std;


double Statistics::average() const {
    if (frequencies.empty()) {
        throw runtime_error("Empty list");
    }
    long long sum = 0;
    sum = accumulate(frequencies.begin(), frequencies.end(), 0LL);
return static_cast<double>(sum) / static_cast<double>(frequencies.size());
}

double Statistics::median() {
    if (frequencies.empty()) {
        throw runtime_error("Empty list");
    }

    auto sorted = frequencies;
    sort(sorted.begin(), sorted.end());

    const auto n = sorted.size();
    if (n % 2 == 1) {
        return sorted[n / 2];
    }
    return (sorted[n / 2 - 1] + sorted[n / 2]) / 2.0;
}
