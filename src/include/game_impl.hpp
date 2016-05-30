#ifndef GAME_IMPL_HPP
#define GAME_IMPL_HPP

#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>

#include "game_model.hpp"
#include "iuser_input_manager.hpp"
#include "irenderer.hpp"

using std::unique_ptr;
using std::thread;
using std::condition_variable;
using std::mutex;

class game_impl {
public:
	using renderer_t = unique_ptr<irenderer>;
	using user_input_manager_t = unique_ptr<iuser_input_manager>;
	
	game_impl();
	~game_impl() = default;

	void start();
	void finish();

private:
	game_model _gm;
	renderer_t _renderer;
	user_input_manager_t _input_manager;
	thread _user_input_thread;
	thread _renderer_thread;
	condition_variable _cv;
	mutex _mu;

	bool _finished;

	static const int _thread_sleep_interval;
};

#endif
