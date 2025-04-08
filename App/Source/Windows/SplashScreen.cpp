#include "SplashScreen.h"

bool SplashScreen::Render() {
	constexpr ImGuiWindowFlags splashFlags =
		ImGuiWindowFlags_NoTitleBar |
		ImGuiWindowFlags_NoMove |
		ImGuiWindowFlags_NoResize |
		ImGuiWindowFlags_NoCollapse |
		ImGuiWindowFlags_NoScrollbar |
		ImGuiWindowFlags_NoSavedSettings;

	const ImVec2 desiredSize = ImVec2(350.0f, 150.0f);
	ImGui::SetNextWindowSize(desiredSize);
	ImGui::SetNextWindowPos(ImVec2(GetSystemMetrics(SM_CXSCREEN) / 2.0f - desiredSize.x / 2.0f,
		GetSystemMetrics(SM_CYSCREEN) / 2.0f - desiredSize.y / 2.0f), ImGuiCond_Always);
	ImGui::SetNextWindowBgAlpha(1.0f);

	if (ImGui::Begin("##SplashScreen", nullptr, splashFlags)) {
		ImVec2 windowSize = ImGui::GetWindowSize();
		ImVec2 centerPos = ImVec2(windowSize.x * 0.5f, windowSize.y * 0.5f);

		const char* loadingText = "Loading Application...";
		ImVec2 textSize = ImGui::CalcTextSize(loadingText);
		ImGui::SetCursorPos(ImVec2(centerPos.x - textSize.x * 0.5f, centerPos.y - textSize.y * 0.5f - 10.0f));
		ImGui::TextUnformatted(loadingText);

		int dots = (frameCounter / 30) % 4;
		std::string progressText = "";
		for (int i = 0; i < dots; ++i) {
			progressText += ".";
		}
		ImVec2 progressTextSize = ImGui::CalcTextSize(progressText.c_str());
		ImGui::SetCursorPos(ImVec2(centerPos.x - progressTextSize.x * 0.5f, centerPos.y + textSize.y * 0.5f));
		ImGui::TextUnformatted(progressText.c_str());

		frameCounter++;

		if (frameCounter > delayFrames) {
			Manager::SwitchWindow(std::make_unique<MainWindow>());
		}

		ImGui::End();
	}

	return true;
}