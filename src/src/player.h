#ifndef PLAYER_H
#define PLAYER_H

#include "system.h"

class Camera;

class Player : public Entity {

	DirectInput* pInput;

	Camera* cam;

public:

	enum PlayerFace {
		PF_LEFT = 1,
		PF_RIGHT = 2,
		PF_UP = 4,
		PF_DOWN = 8
	} face;

	int diag;

	Player() : face(Player::PF_LEFT), cam(0) {}
	
	void Input(DirectInput* in) { this->pInput = in; }

	virtual void update(float dt);

	virtual void release_ext();


	void Cam(Camera* cam) { this->cam = cam; }

	Camera* Cam() { return this->cam; }
};

#endif