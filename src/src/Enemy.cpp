#include "Enemy.h"
#include "Bullet.h"
#include "player.h"

void EnemyInfo::reset() {
	pos.x = float(rand()%640);
	pos.y = float(rand()%480);

	if(pos.x < 320.0f) {
		pos.x -= 320.0f;

		pos.x -= 32.0f + float(rand()%64);
	} else if(pos.x >= 320.0f) {
		pos.x += 320.0f;

		pos.x += 32.0f + float(rand()%64);
	}
	
	if(pos.y < 240.0f) {
		pos.y -= 240.0f;
		pos.y -= 48.0f + float(rand()%64);
	} else if(pos.y >= 240.0f) {
		pos.y += 240.0f;
		pos.y += 48.0f + float(rand()%64);
	}

	pos.z = 0.0f;
}

void Enemys::init(Direct3D& d3d) {
	tex.init(d3d, "data/enemy.png");
	en.init(d3d);

	en.Size(D3DXVECTOR3(32.0f, 48.0f, 0.0f));

	// I'll need to make some enemys

	for(int i = 0; i < 20; i++) {
		EnemyInfo temp;

		temp.reset();

		//temp.pos = D3DXVECTOR3(0, 0, 0);

		einfo.push_back(temp);
	}
}

void Enemys::render(Direct3D& d3d) {
	std::vector<EnemyInfo>::iterator i = einfo.begin();

	while(i != einfo.end()) {

		en.Pos(i->pos);

		en.render(d3d, tex);

		i++;
	}
}

void Enemys::update(float dt) {
	// I'll worky about this later


	std::vector<EnemyInfo>::iterator i = einfo.begin();

	while(i != einfo.end()) {

		D3DXVECTOR3 p_pos = p->Pos();

		if(i->pos.x < p_pos.x) {
			i->pos.x += 16.0f * dt;
		} else if(i->pos.x > p_pos.x) {
			i->pos.x -= 16.0f * dt;
		}


		if(i->pos.y < p_pos.y) {
			i->pos.y += 16.0f * dt;
		} else if(i->pos.y > p_pos.y) {
			i->pos.y -= 16.0f * dt;
		}

		i++;
	}
}

void Enemys::release() {
	tex.release();
	en.release();
	einfo.clear();
}

void Enemys::check_bullets(Bullet& b) {
	b.check_enemys(this->einfo);
}