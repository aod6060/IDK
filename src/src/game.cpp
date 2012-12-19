#include "Game.h"


void Game::init_game() {

	d3d.Device()->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	d3d.Device()->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	d3d.Device()->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	d3d.Device()->SetRenderState(D3DRS_ALPHABLENDENABLE, true);

	D3DXMATRIX P, V;

	D3DXMatrixOrthoOffCenterLH(&P, 0, this->Width(), this->Height(), 0, -1.0f, 1.0f);

	D3DXMatrixIdentity(&V);

	d3d.Device()->SetTransform(D3DTS_PROJECTION, &P);
	d3d.Device()->SetTransform(D3DTS_VIEW, &V);

	d3d.Device()->SetRenderState(D3DRS_LIGHTING, false);
	d3d.Device()->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);

	p.init(d3d);

	p.Pos(D3DXVECTOR3(100.0f, 100.0f, 0.0f));
	p.Size(D3DXVECTOR3(32.0f, 48.0f, 0.0f));

	p.Input(&di);

	t.init(d3d, "data/player.jpg");

	b.init(d3d);

	ens.init(d3d);

	ens.Player(&p);

	bd.init(d3d);

	b.BD(&bd);

	p.Cam(&cam);

}

void Game::render_game() {
	d3d.Device()->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);

	d3d.Device()->BeginScene();

	cam.render(d3d);

	bd.render(d3d);

	p.render(d3d, t);

	ens.render(d3d);

	b.render(d3d);

	d3d.Device()->EndScene();

	d3d.Device()->Present(0, 0, 0, 0);

}

void Game::update_game(float dt) {
	// Do nothing

	if(di.key_down(DIK_ESCAPE)) {
		PostQuitMessage(0);

		OutputDebugString("Hello World\n");
	}

	bd.update(dt);

	p.update(dt);

	b.update(di, dt, p);

	ens.update(dt);

	ens.check_bullets(b, cam);
}

void Game::release_game() {

	bd.release();

	ens.release();

	b.release();
	
	p.release();
	
	t.release();

}