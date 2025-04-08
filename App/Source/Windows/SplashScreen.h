#pragma once

#include "../Global.h"

class SplashScreen : public WindowBase {
private:
	int frameCounter = 0;
	const int delayFrames = 180;

public:

	bool Render() override;
};
