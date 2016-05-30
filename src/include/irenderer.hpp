#ifndef IRENDERER_HPP
#define IRENDERER_HPP

class irenderer {
public:
	virtual void draw() = 0;
	virtual ~irenderer() = default;
};

#endif
