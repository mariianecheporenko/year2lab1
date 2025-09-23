#include <iostream>
#include <vector>
#include <iomanip>
#include "RandomCell.h"
#include "Board.h"


int main() {
	try {
		std::cout << "Enter board size n (n>0) and number of picks m (m>0): ";
		int n; long long m;
		if (!(std::cin >> n >> m)) {
			std::cerr << "Invalid input format. Expected two integers.\n";
			return 1;
		}


		if (n <= 0) {
			std::cerr << "n must be positive\n";
			return 1;
		}
		if (m <= 0) {
			std::cerr << "m must be positive\n";
			return 1;
		}


		Board board(n);
		RandomCell generator(n);


		// we'll produce the frequency vector and print first few generated cells for verification
		std::vector<std::size_t> freq(board.cellCount(), 0);


		// If m is huge (e.g. > 1e9), warn but still attempt (but don't loop forever)
		const long long max_safe = 100000000; // 1e8 as a pragmatic cap for classroom runs
		if (m > max_safe) {
			std::cout << "Warning: large m (>1e8). This may be slow. Continuing anyway...\n";
		}


		const int preview = 10; // print first few generated cells
		std::cout << "Generating " << m << " random cells...\n";
		for (long long i = 0; i < m; ++i) {
			auto [r, c] = generator();
			freq[board.idx(r, c)]++;
			if (i < preview) {
				std::cout << "pick " << i << ": (" << r << "," << c << ")\n";
			}
		}


		// Save freq to stdout in a compact form so Student 2 can read it or parse it.
		// Format: first line contains n and m, next n*n lines contain freq per cell in row-major order.
		std::cout << "---FREQ BEGIN---\n";
		std::cout << n << ' ' << m << '\n';
		for (std::size_t i = 0; i < freq.size(); ++i) {
			std::cout << freq[i] << '\n';
		}
		std::cout << "---FREQ END---\n";


		std::cout << "Done. Frequency vector printed between markers. Give this output to Student 2.\n";
		return 0;
	}
	catch (const std::exception& ex) {
		std::cerr << "Error: " << ex.what() << '\n';
		return 1;
	}
}