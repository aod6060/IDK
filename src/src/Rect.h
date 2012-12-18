#ifndef RECT_H
#define RECT_H

#include "Direct3D.h"

struct Rect {
	D3DXVECTOR3 pos;
	D3DXVECTOR3 size;

	Rect() : pos(0, 0, 0), size(0, 0, 0) {}

	Rect(D3DXVECTOR3 pos, D3DXVECTOR3 size) : pos(pos), size(size) {}

	float left() { return pos.x; }

	float right() { return pos.x + size.x; }

	float up() { return pos.y; }

	float down() { return pos.y + size.y; }

	bool operator == (Rect& r) {
		if(left() > r.right()) {
			return false;
		} else if(right() < r.left()) {
			return false;
		} else if(up() > r.down()) {
			return false;
		} else if(down() < r.up()) {
			return false;
		}
		return true;
	}
};

#endif