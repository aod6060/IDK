#include "Blood.h"

void BloodDecal::init(Direct3D& d3d) {
	en.init(d3d);

	tex[0].init(d3d, "data/blood1.png");
	tex[1].init(d3d, "data/blood2.png");
	tex[2].init(d3d, "data/blood3.png");

	en.Size(D3DXVECTOR3(32.0f, 32.0f, 0.0f));
}

void BloodDecal::render(Direct3D& d3d) {

	std::vector<BloodInfo>::iterator i = binfo.begin();

	while(i != binfo.end()) {

		en.Pos(i->pos);

		en.render(d3d, tex[i->type]);

		i++;
	}
}

void BloodDecal::update(float dt) {

	std::vector<BloodInfo>::iterator i = binfo.begin();

	while(i != binfo.end()) {

		i->life += dt;

		if(i->life >= 50.0f) {
			i = binfo.erase(i);
		} else {
			i++;
		}
	}
}

void BloodDecal::release() {

	for(int i = 0; i < 3; i++) {
		tex[i].release();
	}

	en.release();

	binfo.clear();
}

void BloodDecal::addBlood(D3DXVECTOR3 pos) {
	BloodInfo temp;

	temp.life = 0.0f;

	temp.pos = pos;

	temp.type = rand()%3;

	binfo.push_back(temp);
}