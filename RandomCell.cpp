#include <stdexcept>
#include <chrono>
#include "RandomCell.h"


RandomCell::RandomCell(int n)
	: n_(n),
	rng_(static_cast<std::uint32_t>(std::chrono::steady_clock::now().time_since_epoch().count() ^ std::random_device{}())),
	dist_(0, n - 1)
{
	if (n <= 0) {
		throw std::invalid_argument("RandomCell: board size n must be > 0");
	}
}


RandomCell::RandomCell(int n, std::uint32_t seed)
	: n_(n), rng_(seed), dist_(0, n - 1)
{
	if (n <= 0) {
		throw std::invalid_argument("RandomCell: board size n must be > 0");
	}
}


std::pair<int, int> RandomCell::operator()() {
	int flat = dist_(rng_) * n_ + dist_(rng_); 
	int row = dist_(rng_);
	int col = dist_(rng_);
	return { row, col };
}