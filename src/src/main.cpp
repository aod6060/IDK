#include "Game.h"


int WINAPI WinMain(HINSTANCE hin, HINSTANCE hpin, LPSTR str, int cmd) {

	Game game;

	game.init("IDK Game", 640, 480, hin, cmd);

	game.loop();

	game.release();

	return 0;
}