#include<thread>
#include<iostream>

#include "game.hpp"
#include "game_model.hpp"

game::game() :_game_impl(new game_impl()){}

void game::start() {
	_game_impl->start();
}

void game::finish() {
	_game_impl->finish();
}

