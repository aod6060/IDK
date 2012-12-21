#ifndef GAME_H
#define GAME_H

#include "system.h"
#include "player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Blood.h"
#include "Camera.h"
#include "ParticleSystem.h"

class Game : public System {

	Player p;

	Texture t;

	Bullet b;

	Enemys ens;

	BloodDecal bd;

	Camera cam;

	ParticleSystem ps;

public:

	virtual void init_game();

	virtual void render_game();

	virtual void update_game(float dt);

	virtual void release_game();

};

#endif