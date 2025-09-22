#pragma once
#include <utility>
#include <random>
#include <cstdint>


class RandomCell {
public:
	explicit RandomCell(int n);


	RandomCell(int n, std::uint32_t seed);


	std::pair<int, int> operator()();


	int size() const noexcept { return n_; }


	RandomCell(const RandomCell&) = delete;
	RandomCell& operator=(const RandomCell&) = delete;


	RandomCell(RandomCell&&) = default;
	RandomCell& operator=(RandomCell&&) = default;


private:
	int n_;
	std::mt19937 rng_;
	std::uniform_int_distribution<int> dist_;
};

