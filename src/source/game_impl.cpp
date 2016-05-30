#include <chrono>
#include <memory>
#include <iostream>

#include "game_impl.hpp"
#include "stdout_renderer.hpp"
#include "stdout_user_input_manager.hpp"

using std::unique_ptr;
using std::thread;

const int game_impl::_thread_sleep_interval = 500;

/*
 *	FIXME - factory for input_manager and stdout_manager
 */
game_impl::game_impl() : 
	_gm(), _renderer(renderer_t(new stdout_renderer(_gm))), _input_manager(user_input_manager_t(new stdout_user_input_manager(_gm))), _finished(false)
{
}

void game_impl::start() {
	bool should_draw = false;

	_user_input_thread = thread([this, &should_draw]() {
		while(!_finished) {
			std::unique_lock<mutex> lk(_mu);
			if(_gm.state() == WON) {
				std::cout << "You Won!" << std::endl;
				_finished = true;
				lk.unlock();
				_cv.notify_one();

			} else if(_gm.state() == LOST) {
				std::cout << "You Lost!" << std::endl;
				_finished = true;
				lk.unlock();
				_cv.notify_one();
			
			} else {
				_input_manager->dispatch();	
				should_draw = true;
				lk.unlock();
				_cv.notify_one();
				std::this_thread::sleep_for(std::chrono::milliseconds(game_impl::_thread_sleep_interval));
			}
		}			
	});

	_renderer->draw();
	_renderer_thread = thread([this, &should_draw]() {
		while(!_finished) {
			std::unique_lock<mutex> lk(_mu);
			_cv.wait(lk, [this, &should_draw]{return should_draw;});
			_renderer->draw();
			should_draw = false;
		}
	});

	_renderer_thread.join();
	_user_input_thread.join();

}

void game_impl::finish() {
	_finished = true;
}
