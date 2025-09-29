// main.cpp
// Compiler: g++ (C++20)

#include <iostream>
#include "Experiment.h"

using namespace std;

int main() {
    try {
        int n, m;
        cout << "Enter board size n: ";
        cin >> n;
        cout << "Enter number of picks m: ";
        cin >> m;

        Experiment exp(n, m);
        exp.run();
        exp.printResults();
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << '\n';
        return 1;
    }



    return 0;
}
