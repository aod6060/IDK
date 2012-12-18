#ifndef BULLET_H
#define BULLET_H


#include "system.h"
class Player;

struct BulletInfo {
	D3DXVECTOR3 pos;
	D3DXVECTOR3 vel;
	float time;
};

class Bullet {
	Entity en;

	Texture tex;

	std::vector<BulletInfo> bts;

	float fireDelay;

public:

	void init(Direct3D& d3d);

	void render(Direct3D& d3d);

	void update(DirectInput& di, float dt, Player& p);

	void release();

};

#endif