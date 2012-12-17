#include "Game.h"


void Game::init_game() {
	
	D3DXMATRIX P, V;


	D3DXMatrixOrthoOffCenterLH(&P, 0, this->Width(), this->Height(), 0, -1.0f, 1.0f);

	D3DXMatrixIdentity(&V);

	d3d.Device()->SetTransform(D3DTS_PROJECTION, &P);
	d3d.Device()->SetTransform(D3DTS_VIEW, &V);

	d3d.Device()->SetRenderState(D3DRS_LIGHTING, false);
	d3d.Device()->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);

	en.init(d3d);

	en.Pos(D3DXVECTOR3(100.0f, 100.0f, 0.0f));
	en.Size(D3DXVECTOR3(32.0f, 48.0f, 0.0f));

	t.init(d3d, "data/player.jpg");

}

void Game::render_game() {
	d3d.Device()->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);

	d3d.Device()->BeginScene();


	en.render(d3d, t);

	d3d.Device()->EndScene();

	d3d.Device()->Present(0, 0, 0, 0);

}

void Game::update_game(float dt) {
	// Do nothing

	en.update(dt);

}

void Game::release_game() {

	en.release();
	t.release();

}