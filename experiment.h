#ifndef EXPERIMENT_H
#define EXPERIMENT_H

#pragma once

#include <vector>
#include "Statistics.h"

using namespace std;

class Experiment {
public:
    Experiment(int n, int m);
    ~Experiment();

    void run();
    void printResults() const;

private:

    int n; // board size
    int m; // quantity of choosing
    vector<int> frequencies;
    Statistics* stats;
};

#endif
