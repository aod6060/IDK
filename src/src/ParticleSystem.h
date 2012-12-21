#ifndef PARTICLE_SYSTEM_H
#define PARTICLE_SYSTEM_H


#include "system.h"

struct Particle {
	D3DXVECTOR2 pos;
	D3DXVECTOR2 vel;
	D3DXVECTOR2 acc;

	float time;

	D3DXVECTOR3 origion;
};

struct ParticleVertex {
	D3DXVECTOR3 xyz;
};

#define PARTICLE_FVF (D3DFVF_XYZ)

class ParticleSystem {

	std::vector<Particle> particles;

	IDirect3DVertexBuffer9* vb; // this will hold 1000 particles
	// in total.


};

#endif