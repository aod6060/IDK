#include "player.h"
#include "Camera.h"

void Player::update(float dt) {

	diag = 0;

	if(pInput->key_down(DIK_LEFT)) {
		pos.x -= 128.0f * dt;
		face = Player::PF_LEFT;
	} else if(pInput->key_down(DIK_RIGHT)) {
		pos.x += 128.0f * dt;
		face = Player::PF_RIGHT;
	}
	
	if(pInput->key_down(DIK_UP)) {
		pos.y -= 128.0f * dt;
		face = Player::PF_UP;
	} else if(pInput->key_down(DIK_DOWN)) {
		pos.y += 128.0f * dt;
		face = Player::PF_DOWN;
	}


	if(cam) {
		cam->Pos(pos);
	}
}

void Player::release_ext() {
	this->pInput = 0;
	this->cam = 0;
}