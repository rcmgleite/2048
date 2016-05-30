#ifndef IUSER_INPUT_MANAGER_HPP
#define IUSER_INPUT_MANAGER_HPP

class iuser_input_manager {
public:
	/*
	 *	Function that Gets the user input and dispatches it to the right handler
	 */
	virtual void dispatch() = 0;
	virtual ~iuser_input_manager() = default;
};

#endif
