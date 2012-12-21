#ifndef HEALTH_H
#define HEALTH_H


#include "system.h"

class Health {
	ID3DXFont* font;

	int health;

public:

	void init(Direct3D& d3d);

	void render();

	void release();

	void dec(int health) { this->health -= health; }

	void inc(int health) { this->health += health; }

	int getHealth() { return this->health; }
};

#endif