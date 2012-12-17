#include "Game.h"


void Game::init_game() {


	d3d.Device()->CreateVertexBuffer(
		6 * sizeof(Vertex),
		D3DUSAGE_WRITEONLY,
		VFVF,
		D3DPOOL_DEFAULT,
		&vb,
		0);


	Vertex* v;

	vb->Lock(0, 0, (void**)&v, 0);

	v[0] = Vertex(D3DXVECTOR3(0, 0, 0));
	v[1] = Vertex(D3DXVECTOR3(1, 0, 0));
	v[2] = Vertex(D3DXVECTOR3(0, 1, 0));

	v[3] = Vertex(D3DXVECTOR3(0, 1, 0));
	v[4] = Vertex(D3DXVECTOR3(1, 1, 0));
	v[5] = Vertex(D3DXVECTOR3(1, 0, 0));

	vb->Unlock();

	v = 0;


	D3DXMATRIX P, V;


	D3DXMatrixOrthoOffCenterLH(&P, 0, this->Width(), this->Height(), 0, -1.0f, 1.0f);

	D3DXMatrixIdentity(&V);

	d3d.Device()->SetTransform(D3DTS_PROJECTION, &P);
	d3d.Device()->SetTransform(D3DTS_VIEW, &V);

	d3d.Device()->SetRenderState(D3DRS_LIGHTING, false);
	d3d.Device()->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);


}

void Game::render_game() {
	d3d.Device()->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);

	d3d.Device()->BeginScene();


	D3DXMATRIX W, S, T;

	D3DXMatrixTranslation(&T, 100.0f, 100.0f, 0.0f);
	D3DXMatrixScaling(&S, 32.0f, 48.0f, 0.0f);

	W = S * T;

	d3d.Device()->SetFVF(VFVF);

	d3d.Device()->SetTransform(D3DTS_WORLD, &W);

	d3d.Device()->SetStreamSource(0, vb, 0, sizeof(Vertex));

	d3d.Device()->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 2);

	d3d.Device()->EndScene();

	d3d.Device()->Present(0, 0, 0, 0);

}

void Game::update_game(float dt) {
	// Do nothing
}

void Game::release_game() {

	if(vb) {
		vb->Release();
		vb = 0;
	}
}