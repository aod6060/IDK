#include "player.h"

void Player::update(float dt) {

	if(pInput->key_down(DIK_LEFT)) {
		pos.x -= 64 * dt;
	} else if(pInput->key_down(DIK_RIGHT)) {
		pos.x += 64.0f * dt;
	}

	if(pInput->key_down(DIK_UP)) {
		pos.y -= 64.0f * dt;
	} else if(pInput->key_down(DIK_DOWN)) {
		pos.y += 64.0f * dt;
	}
}

void Player::release_ext() {
	this->pInput = 0;
}