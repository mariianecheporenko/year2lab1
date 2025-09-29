#ifndef EXPERIMENT_H
#define EXPERIMENT_H

#pragma once

#include <vector>
#include "Statistics.h"
#include "RandomCell.h"

using namespace std;

class Experiment {
public:
    Experiment(int n, int m);
    ~Experiment();

    void run();                 // запускає експеримент
    void printResults() const;  // виводить mean і median

private:

    int n; // board size
    int m; // quantity of choosing
    vector<int> frequencies;
    Statistics* stats;          // вказівник на Statistics
};

#endif
