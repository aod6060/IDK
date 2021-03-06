#include "Enemy.h"
#include "Bullet.h"
#include "player.h"
#include "Camera.h"

void EnemyInfo::reset(D3DXVECTOR3 off) {
	pos.x = float(rand()%640) + off.x;
	pos.y = float(rand()%480) + off.y;

	/*
	if(pos.x < 320.0f+off.x) {
		pos.x -= 320.0f;

		pos.x -= 32.0f + float(rand()%64);
	} else if(pos.x >= 320.0f+off.x) {
		pos.x += 320.0f;

		pos.x += 32.0f + float(rand()%64);
	}
	
	if(pos.y < 240.0f + off.y) {
		pos.y -= 240.0f;
		pos.y -= 48.0f + float(rand()%64);
	} else if(pos.y >= 240.0f + off.y) {
		pos.y += 240.0f;
		pos.y += 48.0f + float(rand()%64);
	}
	*/
	pos.z = 0.0f;

	life = rand()%3;

	this->etype = life;

	if(this->etype == 0) {
		this->speed = 64.0f;
	} else if(this->etype == 1) {
		this->speed = 32.0f;
	} else if(this->etype == 2) {
		this->speed = 16.0f;
	}
}

void Enemys::init(Direct3D& d3d) {
	tex[0].init(d3d, "data/enemy.png");
	tex[1].init(d3d, "data/enemy2.png");
	tex[2].init(d3d, "data/enemy3.png");

	en.init(d3d);

	en.Size(D3DXVECTOR3(32.0f, 48.0f, 0.0f));

	// I'll need to make some enemys

	for(int i = 0; i < 20; i++) {
		EnemyInfo temp;

		temp.reset(D3DXVECTOR3(0, 0, 0));

		//temp.pos = D3DXVECTOR3(0, 0, 0);

		einfo.push_back(temp);
	}
}

void Enemys::render(Direct3D& d3d) {
	std::vector<EnemyInfo>::iterator i = einfo.begin();

	while(i != einfo.end()) {

		en.Pos(i->pos);

		en.render(d3d, tex[i->etype]);

		i++;
	}
}

void Enemys::update(float dt) {
	// I'll worky about this later


	std::vector<EnemyInfo>::iterator i = einfo.begin();

	while(i != einfo.end()) {

		D3DXVECTOR3 p_pos = p->Pos();

		if(i->pos.x < p_pos.x) {
			i->pos.x += i->speed * dt;
		} else if(i->pos.x > p_pos.x) {
			i->pos.x -= i->speed * dt;
		}


		if(i->pos.y < p_pos.y) {
			i->pos.y += i->speed * dt;
		} else if(i->pos.y > p_pos.y) {
			i->pos.y -= i->speed * dt;
		}

		i++;
	}
}

void Enemys::release() {
	tex[0].release();
	tex[1].release();
	tex[2].release();
	en.release();
	einfo.clear();
}

void Enemys::check_bullets(Bullet& b, Camera& cam) {
	b.check_enemys(this->einfo, cam);
}