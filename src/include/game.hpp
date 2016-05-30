#ifndef GAME_HPP
#define GAME_HPP

#include "game_impl.hpp"
#include "game_model.hpp"

using std::unique_ptr;
using std::thread;

class game {
public:

	game();
	void start();
	void finish();

private:
	unique_ptr<game_impl> _game_impl;
};

#endif
