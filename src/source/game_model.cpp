#include<random>

#include "game_model.hpp"

static const int BOARD_SIZE = 4;
static const int EMPTY_SLOT = 0;

game_model::game_model() : _board(BOARD_SIZE), _score(0), _state(CONTINUE) {
	insert_random();
	insert_random();
} 

/*
 *	Public interface
 */
void game_model::move_right() {
	for(int i = 0; i < BOARD_SIZE; i++) {
		shift_row_right(i);
		merge_row_right(i);
		shift_row_right(i);
	}
	update_state();
	insert_random();
}

void game_model::move_left() {
	_board.rotate_90_clockwise();
	_board.rotate_90_clockwise();
	move_right();
	_board.rotate_90_clockwise();
	_board.rotate_90_clockwise();
}

void game_model::move_up() {
	_board.rotate_90_clockwise();
	move_right();
	_board.rotate_90_clockwise();
	_board.rotate_90_clockwise();
	_board.rotate_90_clockwise();
}

void game_model::move_down() {
	_board.rotate_90_clockwise();
	_board.rotate_90_clockwise();
	_board.rotate_90_clockwise();
	move_right();
	_board.rotate_90_clockwise();
}

/*
 *	Randomly adds a new piece to the board.
 */
void game_model::add_piece() {

}

int game_model::score() {
	return _score;
}

int game_model::state() {
	return _state;
}

iboard& game_model::board() {
	return _board;
}

/*
 *	Private impl
 */

void game_model::insert_random() {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(0, 3);

	while(true) {
		int i = dist(mt);
		int j = dist(mt);
		if(_board.get(i, j) == 0) {
			_board.set(i, j, 2); //FIXME - insert 2 or 4 
			return;
		}
	}
}

void game_model::shift_row_right(int row) { // FIXME... too many branches
	int blank_flag = BOARD_SIZE - 1;
	
	while(blank_flag > 0) {

		/*
		 *	Finds the next empty slot
		 */
		while(blank_flag >= 0 && _board.get(row, blank_flag) != EMPTY_SLOT) {
			blank_flag--;
		}

		if(blank_flag <= 0)
			return;

		/*
		 *	From the empty slot on, try to find an item to be moved
		 */
		int walker = blank_flag - 1;
		while(_board.get(row, walker) == EMPTY_SLOT && walker > 0)
			walker--;

		_board.set(row, blank_flag, _board.get(row, walker));
		_board.set(row, walker, EMPTY_SLOT);

		if(walker == 0)
			return;

		blank_flag--;
	}
}

/*
 *	Function that merges each adj slot on a single row of the board
 */
void game_model::merge_row_right(int row) {
	for(int i = BOARD_SIZE - 1; i >= 1; i--) {
		if((_board.get(row, i) == _board.get(row, i - 1)) && _board.get(row, i) != EMPTY_SLOT) {
			int new_value = _board.get(row, i);
			_score += new_value;
			_board.set(row, i, new_value * 2);
			_board.set(row, i - 1, EMPTY_SLOT);
		}
	}
}

void game_model::update_state() {
	int counter = 0;
	for(int i = 0; i < BOARD_SIZE; i++) {
		for(int j = 0; j < BOARD_SIZE; j++) {
			auto elem = _board.get(i, j);
			if(elem != 0) {
				counter++;
				if(elem == 2048) {
					_state = WON;
					return;
				}
			}
		}
	}
	_state = (counter == BOARD_SIZE * BOARD_SIZE ? LOST : CONTINUE);
}

