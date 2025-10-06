#ifndef STATISTICS_H
#define STATISTICS_H
#include <vector>
using namespace std;

class Statistics {
    public:
    template<typename Iter>
        Statistics(Iter begin, Iter end) : frequencies(begin, end) {}

    double average() const;
    double median();

    private:
    vector<int> frequencies;


};

#endif
