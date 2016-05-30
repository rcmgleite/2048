#include "stdout_user_input_manager.hpp"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

stdout_user_input_manager::stdout_user_input_manager(game_model& gm) : _gm(gm) {}

void stdout_user_input_manager::dispatch() {
	char input;
	cin >> input;

	switch(input) {
		case 'A':
		case 'a':
			_gm.move_left();
			break;

		case 'W':
		case 'w':
			_gm.move_up();
			break;

		case 'D':
		case 'd':
			_gm.move_right();
			break;

		case 'S':
		case 's':
			_gm.move_down();
			break;

		case 'Q':
		case 'q':
			cout << "[INFO] Exit key pressed" << endl;

		default:
			cout << "[ERROR] Input not handled!" << endl;
			break;

	}	
}
