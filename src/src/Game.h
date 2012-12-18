#ifndef GAME_H
#define GAME_H

#include "system.h"
#include "player.h"

class Game : public System {

	Player p;

	Texture t;

public:

	virtual void init_game();

	virtual void render_game();

	virtual void update_game(float dt);

	virtual void release_game();

};

#endif