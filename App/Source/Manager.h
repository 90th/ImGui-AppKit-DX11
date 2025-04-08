#pragma once

#include <memory>

class WindowBase;

namespace Manager {
	namespace Data {
		inline std::unique_ptr<WindowBase> CurrentWindow = nullptr;
	}

	void InitDefault();

	void SwitchWindow(std::unique_ptr<WindowBase> newWindow);

	void Render();
}
