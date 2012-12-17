#ifndef ENTITY_H
#define ENTITY_H


#include <vector>
#include "Direct3D.h"
#include "CustomVertex.h"
#include "Texture.h"

class Entity {
protected:
	IDirect3DVertexBuffer9* mVB;
	VertexList mVlist;

	D3DXVECTOR3 pos;
	D3DXVECTOR3 size;

public:

	Entity() : pos(0, 0, 0), size(1.0f, 1.0f, 0.0f) {}

	virtual ~Entity() {}

	void init(Direct3D& d3d);

	void release();

	void render(Direct3D& d3d, Texture& tex);

	void Pos(D3DXVECTOR3 pos) { this->pos = pos; }

	void Size(D3DXVECTOR3 size) { this->size = size; }

	D3DXVECTOR3 Pos() { return pos; }

	D3DXVECTOR3 Size() { return size; }

	virtual void update(float dt) {}

	virtual void init_buffer() {}

	void create_buffer(Direct3D& d3d);

	void update_buffer();

};

#endif