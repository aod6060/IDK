#ifndef BLOOD_H
#define BLOOD_H


#include "system.h"

class BloodDecal;

struct BloodInfo {
	D3DXVECTOR3 pos;
	float life;
	int type;
};


class BloodDecal {
	Entity en;
	Texture tex[3];

	std::vector<BloodInfo> binfo;


public:

	void init(Direct3D& d3d);

	void render(Direct3D& d3d);

	void update(float dt);

	void release();

	void addBlood(D3DXVECTOR3 pos);

};

#endif