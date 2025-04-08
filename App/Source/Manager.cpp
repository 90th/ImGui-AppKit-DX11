#include "Global.h"

void Manager::InitDefault() {
	Data::CurrentWindow = std::make_unique<SplashScreen>();
}

void Manager::SwitchWindow(std::unique_ptr<WindowBase> newWindow) {
	Data::CurrentWindow = std::move(newWindow);
}
void Manager::Render() {
	if (Data::CurrentWindow) {
		bool shouldContinue = Data::CurrentWindow->Render();
		if (!shouldContinue) {
			Global::ShouldExit = true;
		}
	}
	else {
		ImGui::Begin("Error", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_AlwaysAutoResize);
		ImGui::Text("error: no active window in manager.");
		ImGui::End();
	}
}