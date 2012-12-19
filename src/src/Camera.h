#ifndef CAMERA_H
#define CAMERA_H

#include "system.h"


class Camera {
	D3DXVECTOR3 pos;

public:

	void Pos(D3DXVECTOR3 pos) { this->pos = pos; }

	D3DXVECTOR3 Pos() { return this->pos; }

	void render(Direct3D& d3d);

};

#endif