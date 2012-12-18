#ifndef PLAYER_H
#define PLAYER_H

#include "system.h"

class Player : public Entity {

	DirectInput* pInput;

public:

	void Input(DirectInput* in) { this->pInput = in; }

	virtual void update(float dt);

	virtual void release_ext();

};

#endif