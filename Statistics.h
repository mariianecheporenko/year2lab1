#ifndef STATISTICS_H
#define STATISTICS_H

#include <vector>
using namespace std;

class Statistics {
    public:
    Statistics(const vector<int>& freqs);

    double averageCount() const;

    double averageCount();
    double medianCount();

    private:
    vector<int> frequencies;


};

#endif
