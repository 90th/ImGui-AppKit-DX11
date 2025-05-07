#include "Manager.h"
#include "Global.h"
#include "Windows/SplashScreen.h"
#include "Windows/MainWindow.h"
#include "../Library/ImGui/imgui.h"

void Manager::InitDefault() {
	Data::current_window = std::make_unique<SplashScreen>();
}

void Manager::SwitchWindow(std::unique_ptr<WindowBase> new_window) {
	Data::current_window = std::move(new_window);
}

void Manager::Render() {
	if (Data::current_window) {
		bool should_continue = Data::current_window->Render();
		if (!should_continue) {
			Global::should_exit = true;
		}
	}
	else {
		ImGui::Begin("Error", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_AlwaysAutoResize);
		ImGui::Text("error: no active window in manager.");
		ImGui::End();
	}
}