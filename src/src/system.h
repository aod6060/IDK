#ifndef SYSTEM_H
#define SYSTEM_H


#include <string>
#include <Windows.h>

class System {
protected:
	HWND mHwnd;
	HINSTANCE mHin;
	int mWidth;
	int mHeight;
	std::string cap;
	int cmd;

	void init_window();
public:

	System() {}

	virtual ~System() {}

	void init(std::string cap, int width, int height, HINSTANCE hin, int cmd);

	void loop();

	void release();

	// Virtuals functions for the class
	virtual void init_demo() {}

	virtual void render_demo() {}

	virtual void update_demo(float dt) {}

	virtual void release_demo() {}
};

#endif