#include "RandomCell.h"
#include <stdexcept>
#include <random> 

RandomCell::RandomCell(int n)
    : n_(n), dist_(0, n - 1)
{
    if (n <= 0) {
        throw std::invalid_argument("board size must be > 0");
    }
    std::random_device rd;
    rng_.seed(rd());
}

RandomCell::RandomCell(int n, std::uint32_t seed)
    : n_(n), rng_(seed), dist_(0, n - 1)
{
    if (n <= 0) {
        throw std::invalid_argument("board size must be > 0");
    }
}

std::pair<int, int> RandomCell::operator()() {
    return { dist_(rng_), dist_(rng_) };
}