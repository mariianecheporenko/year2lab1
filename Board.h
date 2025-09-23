#pragma once
#include <cstddef>
#include <stdexcept>


class Board {
public:
	explicit Board(int n);


	int n() const noexcept { return n_; }
	std::size_t cellCount() const noexcept { return static_cast<std::size_t>(n_) * static_cast<std::size_t>(n_); }


	bool isValid(int row, int col) const noexcept {
		return (row >= 0 && col >= 0 && row < n_ && col < n_);
	}


	std::size_t idx(int row, int col) const {
		if (!isValid(row, col)) throw std::out_of_range("row/col out of range");
		return static_cast<std::size_t>(row) * static_cast<std::size_t>(n_) + static_cast<std::size_t>(col);
	}


private:
	int n_;
};
