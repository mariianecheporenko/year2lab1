#include "Board.h"


Board::Board(int n) : n_(n) {
	if (n <= 0) throw std::invalid_argument("Board: n must be > 0");
}
