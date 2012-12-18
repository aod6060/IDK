#include "Bullet.h"
#include "player.h"
#include "Enemy.h"

void Bullet::init(Direct3D& d3d) {
	this->tex.init(d3d, "data/bullet.png");
	this->en.init(d3d);

	en.Size(D3DXVECTOR3(32.0f, 32.0f, 0.0f));

	this->fireDelay = 0.0f;
}

void Bullet::render(Direct3D& d3d) {

	std::vector<BulletInfo>::iterator i = this->bts.begin();

	while(i != bts.end()) {

		en.Pos(i->pos);

		en.render(d3d, tex);

		i++;
	}
}

void Bullet::update(DirectInput& di, float dt, Player& p) {

	fireDelay += dt;

	if(di.key_down(DIK_Z) && fireDelay > 0.2f) {
		BulletInfo temp;

		temp.pos = p.Pos();
		temp.time = 0.0f;

		if(p.face == Player::PF_LEFT) {
			temp.vel = D3DXVECTOR3(-1024.0f, 0.0f, 0.0f);
		} else if(p.face == Player::PF_RIGHT) {
			temp.vel = D3DXVECTOR3(1024.0f, 0.0f, 0.0f);
		} else if(p.face == Player::PF_UP) {
			temp.vel = D3DXVECTOR3(0.0f, -1024.0f, 0.0f);
		} else if(p.face == Player::PF_DOWN) {
			temp.vel = D3DXVECTOR3(0.0f, 1024.0f, 0.0f);
		}

		this->bts.push_back(temp);

		fireDelay = 0.0f;
	}

	std::vector<BulletInfo>::iterator i = bts.begin();

	while(i != bts.end()) {

		i->time += dt;

		if(i->time >= 0.5f) {
			i = bts.erase(i);
		} else {
			i->pos += i->vel * dt;
			i++;
		}
	}
}

void Bullet::release() {
	tex.release();
	en.release();
}

void Bullet::check_enemys(std::vector<EnemyInfo>& en) {

	for(unsigned int i = 0; i < en.size(); i++) {

		Rect er(en[i].pos, D3DXVECTOR3(32.0f, 48.0f, 0.0f));


		std::vector<BulletInfo>::iterator j = this->bts.begin();

		while(j != bts.end()) {

			Rect br(j->pos, D3DXVECTOR3(32.0f, 32.0f, 0.0f));


			if(er == br) {
				j = bts.erase(j);

				if(en[i].life <= 0) {

					en[i].reset();
					break;

				} else {
					en[i].life--;
					break;
				}
			}

			j++;
		}
	}
}
