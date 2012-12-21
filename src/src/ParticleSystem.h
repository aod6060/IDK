#ifndef PARTICLE_SYSTEM_H
#define PARTICLE_SYSTEM_H


#include "system.h"

struct Particle {
	D3DXVECTOR2 pos;
	D3DXVECTOR2 vel;
	D3DXVECTOR2 acc;
};

struct ParticleVertex {
	D3DXVECTOR3 xyz;
	DWORD dif;
};

#define PARTICLE_FVF (D3DFVF_XYZ | D3DFVF_DIFFUSE)

class ParticleSystem {

	Particle* parts;

	IDirect3DVertexBuffer9* vb;

	int num;
public:

	void init(Direct3D& d3d, int num);

	void render(Direct3D& d3d);

	void update(float dt);

	void release();

};

#endif