#pragma once

#include <memory>
#include "Windows/WindowBase.h"

namespace Manager {
	namespace Data {
		inline std::unique_ptr<WindowBase> current_window = nullptr;
	}

	void InitDefault();
	void SwitchWindow(std::unique_ptr<WindowBase> new_window);
	void Render();
}
