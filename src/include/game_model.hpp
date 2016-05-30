#ifndef GAME_MODEL_HPP
#define GAME_MODEL_HPP

#include"board.hpp"

enum GAME_STATES {
	WON,
	LOST,
	CONTINUE
};

class game_model {
public:
	game_model();

	/*
	 *	Base move will be right->left
	 */
	void move_right();
	void move_left();
	void move_up();
	void move_down();
	void add_piece();

	/*
	 *	Getters
	 */
	int score();
	int state();
	iboard& board();

private:
	using board_t = class board;
	board_t _board;
	int _score;
	int _state;

	void insert_random();
	void shift_row_right(int row);
	void merge_row_right(int row);
	void update_state();
};

#endif
