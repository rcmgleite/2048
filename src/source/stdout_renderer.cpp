#include <iostream>
#include <string>
#include <sstream>

#include "stdout_renderer.hpp"

using std::string;
using std::cout;
using std::endl;

stdout_renderer::stdout_renderer(game_model& gm) : _gm(gm) {}

static string format_width(int value) {
	std::stringstream ss;
	auto value_str = std::to_string(value);
	
	for(auto i = value_str.size(); i < 4; i++) {
		ss << " ";
	}
	ss << value_str;
	return ss.str();
}

void stdout_renderer::draw() {
	cout << "\e[1;1H\e[2J";
	cout << "Score: " << _gm.score() << endl;
	for(int i = 0; i < _gm.board().size(); i++) {
		for(int j = 0; j < _gm.board().size(); j++) {
			cout << format_width(_gm.board().get(i, j)) << " ";
		}
		cout << endl;
	}

}
