#include "system.h"


void Entity::init(Direct3D& d3d) {


	mVlist.push_back(Vertex(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR2(0, 0)));
	mVlist.push_back(Vertex(D3DXVECTOR3(1.0f, 0.0f, 0.0f), D3DXVECTOR2(1, 0)));
	mVlist.push_back(Vertex(D3DXVECTOR3(0.0f, 1.0f, 0.0f), D3DXVECTOR2(0, 1)));
	mVlist.push_back(Vertex(D3DXVECTOR3(0.0f, 1.0f, 0.0f), D3DXVECTOR2(0, 1)));
	mVlist.push_back(Vertex(D3DXVECTOR3(1.0f, 1.0f, 0.0f), D3DXVECTOR2(1, 1)));
	mVlist.push_back(Vertex(D3DXVECTOR3(1.0f, 0.0f, 0.0f), D3DXVECTOR2(1, 0)));

	this->init_buffer();

	this->create_buffer(d3d);
	
	this->update_buffer();
}

void Entity::release() {

	if(mVB) {
		mVB->Release();
		mVB = 0;
	}

	mVlist.clear();
}

void Entity::render(Direct3D& d3d, Texture& t) {

	D3DXMATRIX W, T, S;

	D3DXMatrixTranslation(&T, pos.x, pos.y, pos.z);
	D3DXMatrixScaling(&S, size.x, size.y, size.z);

	W = S * T;

	d3d.Device()->SetFVF(VERTEX_FVF);

	d3d.Device()->SetTexture(0, t.Tex());

	d3d.Device()->SetTransform(D3DTS_WORLD, &W);

	d3d.Device()->SetStreamSource(0, mVB, 0, sizeof(Vertex));

	d3d.Device()->DrawPrimitive(D3DPT_TRIANGLELIST, 0, mVlist.size()/3);

}

void Entity::create_buffer(Direct3D& d3d) {

	d3d.Device()->CreateVertexBuffer(
		mVlist.size() * sizeof(Vertex),
		D3DUSAGE_WRITEONLY,
		VERTEX_FVF,
		D3DPOOL_DEFAULT,
		&mVB,
		0);

}

void Entity::update_buffer() {

	void* temp = 0;

	mVB->Lock(0, 0, (void**)&temp, 0);

	memcpy(temp, &mVlist[0], mVlist.size() * sizeof(Vertex));

	mVB->Unlock();
}
