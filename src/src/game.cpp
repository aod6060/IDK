#include "Game.h"


void Game::init_game() {

}

void Game::render_game() {
	d3d.Device()->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);

	d3d.Device()->BeginScene();


	d3d.Device()->EndScene();

	d3d.Device()->Present(0, 0, 0, 0);

}

void Game::update_game(float dt) {
	// Do nothing
}

void Game::release_game() {

}