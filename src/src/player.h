#ifndef PLAYER_H
#define PLAYER_H

#include "system.h"

class Player : public Entity {

	DirectInput* pInput;

public:

	enum PlayerFace {
		PF_LEFT = 1,
		PF_RIGHT = 2,
		PF_UP = 4,
		PF_DOWN = 8
	} face;

	int diag;

	Player() : face(Player::PF_LEFT) {}
	
	void Input(DirectInput* in) { this->pInput = in; }

	virtual void update(float dt);

	virtual void release_ext();

};

#endif