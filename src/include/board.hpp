#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>

#include "iboard.hpp"

using std::vector;

class board : public iboard {
public:
	/*
	 *	Constructors
	 */
	board(int size);

	/*
	 *	Virtuals
	 */
	~board() = default;
	int get(int x, int y);
	void set(int x, int y, int value);
	int size();

	/*
	 *	Helpers
	 */
	void rotate_90_clockwise();
	void print();

private:
	using board_t = vector<vector<int>>;

	board_t _board;
	int _board_size;

	bool valid_position(int x, int y);
};

#endif
