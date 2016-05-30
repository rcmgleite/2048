#ifndef IBOARD_HPP
#define IBOARD_HPP

class iboard {
public:
	virtual int get(int x, int y) = 0;
	virtual void set(int x, int y, int value) = 0;
	virtual int size() = 0;
	virtual ~iboard() = default;
};

#endif
