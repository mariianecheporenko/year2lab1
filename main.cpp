// Compiler: g++ (C++20)

#include <iostream>
#include "Experiment.h"
#include "RandomCell.h" 
#include "Board.h"

using namespace std;

int input(const string& prompt) {
    int value;
    cout << prompt;
    cin >> value;
    if (cin.fail() || value <= 0) {
        throw runtime_error("Invalid input: should a be positive number");
    }
    return value;
}

int main() {
    try {

        int n = input("Enter board size n: ");
        int m = input("Enter number of picks m: ");

        cout << "RandomCell test\n";
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
        cerr << e.what() << '\n';
        return 1;
    }



    return 0;
}
