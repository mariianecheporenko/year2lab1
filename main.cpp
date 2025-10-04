// main.cpp
// Compiler: g++ (C++20)

#include <iostream>
#include "Experiment.h"
#include "RandomCell.h" 
#include "Board.h"

using namespace std;

int main() {
    try {
        int n, m;
        cout << "Enter board size n: ";
        cin >> n;
        cout << "Enter number of picks m: ";
        cin >> m;

        cout << "RandomCell test";
        RandomCell generator(n);

        cout << "5 random cells on " << n << "x" << n << " board:\n";
        for (int i = 0; i < 5; i++) {
            auto cell = generator();
            cout << "(" << cell.first << ", " << cell.second << ")\n";
        }

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
