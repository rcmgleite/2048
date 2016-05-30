#ifndef GAME_EXCEPTION_HPP
#define GAME_EXCEPTION_HPP

#include<string>
#include<exception>

using std::string;

class game_exception : public std::exception {
public:
	game_exception(const string& err);
	~game_exception() = default;

	virtual const char* what() const throw();
	virtual game_exception* clone() const;
	virtual void raise();

private:
	string _err;

};

#endif
