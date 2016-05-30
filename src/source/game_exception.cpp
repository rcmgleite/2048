#include "game_exception.hpp"

game_exception::game_exception(const string& err) : _err(err) {}

const char* game_exception::what() const throw(){
	return _err.c_str();
}

game_exception* game_exception::clone() const {
	return new game_exception(*this);
}

void game_exception::raise() {
	throw *this;
}
