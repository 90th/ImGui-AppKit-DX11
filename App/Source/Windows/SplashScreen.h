#pragma once

#include "WindowBase.h"

class SplashScreen : public WindowBase {
private:
	int frame_counter_ = 0;
	const int kDelayFrames = 180;

public:
	SplashScreen() = default;
	bool Render() override;
};
