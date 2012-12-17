#include "system.h"

int WINAPI WinMain(HINSTANCE hin, HINSTANCE hpin, LPSTR str, int cmd) {


	System sys;

	sys.init("Game Window", 640, 480, hin, cmd);

	sys.loop();

	sys.release();

	return 0;
}