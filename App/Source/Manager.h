#pragma once

#include <memory>

class WindowBase;

namespace Manager {
	namespace Data {
		inline std::unique_ptr<WindowBase> CurrentWindow = nullptr;
		inline float NextSizeX = 300.0f;
		inline float NextSizeY = 300.0f;
	}

	void InitDefault();

	void SetNextSize(float width, float height);

	void SwitchWindow(std::unique_ptr<WindowBase> newWindow);

	void Render();
}