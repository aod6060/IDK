#ifndef SYSTEM_H
#define SYSTEM_H


#include <string>
#include <Windows.h>
#include "Direct3D.h"

/*
	This is a wrapper for the window, direct3d9, and directinput8. I debating for sound fx I should use OpenAL or DirectSound just to
	keep it with in the same style
*/
class System {
protected:
	HWND mHwnd;
	HINSTANCE mHin;
	int mWidth;
	int mHeight;
	std::string cap;
	int cmd;

	Direct3D d3d;

	void init_window();
public:

	System() {}

	virtual ~System() {}

	void init(std::string cap, int width, int height, HINSTANCE hin, int cmd);

	void loop();

	void release();

	HWND Handler() { return mHwnd; } // Returns window handler
	HINSTANCE Instance() { return mHin; } // Returns window instance 

	int Width() { return mWidth; }
	int Height() { return mHeight; }

	// Virtuals functions for the class
	virtual void init_game() {}

	virtual void render_game() {}

	virtual void update_game(float dt) {}

	virtual void release_game() {}
};

#endif