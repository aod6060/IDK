#include "ParticleSystem.h"

void ParticleSystem::init(Direct3D& d3d, int num) {

	this->num = num;

	this->parts = new Particle[this->num];

	d3d.Device()->CreateVertexBuffer(
		this->num * sizeof(ParticleVertex),
		D3DUSAGE_WRITEONLY,
		PARTICLE_FVF,
		D3DPOOL_DEFAULT,
		&vb,
		0);


}

void ParticleSystem::render(Direct3D& d3d) {

}

void ParticleSystem::update(float dt) {

}

void ParticleSystem::release() {

}