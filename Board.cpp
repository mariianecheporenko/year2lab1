#include "Board.h"


Board::Board(int n) : n_(n) {
    if (n <= 0) throw std::invalid_argument(" n must be > 0");
}