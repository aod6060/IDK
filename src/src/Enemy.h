#ifndef ENEMY_H
#define ENEMY_H

#include "system.h"

class Bullet;
class Player;

struct EnemyInfo {
	D3DXVECTOR3 pos;

	void reset();
};

class Enemys {
	std::vector<EnemyInfo> einfo;

	Entity en;

	Texture tex;

	Player* p;

public:

	void init(Direct3D& d3d);

	void render(Direct3D& d3d);

	void update(float dt);

	void release();

	virtual void release_ext() { p = 0; }

	void check_bullets(Bullet& b);

	void Player(Player* p) { this->p = p; }

};

#endif