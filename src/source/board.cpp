#include "board.hpp"
#include "game_exception.hpp"
#include "utils.hpp"

board::board(int size) : _board(size, vector<int>(size)), _board_size(size) {}

int board::get(int x, int y) {
	if(!valid_position(x, y)) {
		throw game_exception("[ERROR] Trying to access board at: (" + std::to_string(x) + ", " + std::to_string(y) + ")");		
	}

	return _board[x][y];
}

void board::set(int x, int y, int value) {
	if(!valid_position(x, y)) {
		throw game_exception("[ERROR] Trying to access board at: (" + std::to_string(x) + ", " + std::to_string(y) + ")");		
	}

	_board[x][y] = value;
}

int board::size() {
	return _board_size;
}

void board::print() {
	utils::print_matrix(_board);
}

void board::rotate_90_clockwise() {
	utils::rotate(_board);
}

bool board::valid_position(int x, int y) {
	return (x >= 0 && x < _board_size && y >= 0 && y < _board_size);
}
