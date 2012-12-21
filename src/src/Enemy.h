#ifndef ENEMY_H
#define ENEMY_H

#include "system.h"

class Bullet;
class Player;
class Camera;

struct EnemyInfo {
	D3DXVECTOR3 pos;

	int life;

	int etype;

	void reset(D3DXVECTOR3 off);

	float speed;
};

class Enemys {
	std::vector<EnemyInfo> einfo;

	Entity en;

	Texture tex[3];

	Player* p;

public:

	void init(Direct3D& d3d);

	void render(Direct3D& d3d);

	void update(float dt);

	void release();

	virtual void release_ext() { p = 0;}

	void check_bullets(Bullet& b, Camera& cam);

	void Player(Player* p) { this->p = p; }
};

#endif