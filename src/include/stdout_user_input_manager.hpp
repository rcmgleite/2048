#ifndef STDOUT_USER_INPUT_MANAGER_HPP
#define STDOUT_USER_INPUT_MANAGER_HPP

#include "iuser_input_manager.hpp"
#include "game_model.hpp"

class stdout_user_input_manager : public iuser_input_manager {
public:
	stdout_user_input_manager(game_model& gm);
	void dispatch();
private:
	game_model& _gm;
};

#endif
