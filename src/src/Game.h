#ifndef GAME_H
#define GAME_H

#include "system.h"

struct Vertex {
	D3DXVECTOR3 xyz;

	Vertex() : xyz(0, 0, 0) {}

	Vertex(D3DXVECTOR3 xyz) : xyz(xyz) {}

};


#define VFVF (D3DFVF_XYZ)

class Game : public System {

	IDirect3DVertexBuffer9* vb;


public:

	virtual void init_game();

	virtual void render_game();

	virtual void update_game(float dt);

	virtual void release_game();

};

#endif