#pragma once

#include <Windows.h>
#include <d3d11.h>
#include <iostream>
#include <memory>
#include <string>
#include <chrono>
#include <thread>

#include "../Library/ImGui/imgui_impl_dx11.h"
#include "../Library/ImGui/imgui_impl_win32.h"
#include "../Library/ImGui/imgui.h"

#include "Render.h"
#include "Style.h"
#include "Windows/WindowBase.h"
#include "Manager.h"

#include "Windows/SplashScreen.h"
#include "Windows/MainWindow.h"

namespace Global {
	inline bool ShouldExit = false;
}