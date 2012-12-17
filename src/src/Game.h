#ifndef GAME_H
#define GAME_H

#include "system.h"


class Game : public System {

public:

	virtual void init_game();

	virtual void render_game();

	virtual void update_game(float dt);

	virtual void release_game();

};

#endif