#include "irenderer.hpp"
#include "iboard.hpp"
#include "game_model.hpp"

class stdout_renderer : public irenderer {
public:
	stdout_renderer(game_model& board);
	void draw();
	virtual ~stdout_renderer() = default;

private:
	game_model& _gm;
};
