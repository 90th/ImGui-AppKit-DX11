#include "SplashScreen.h"
#include <string>
#include <Windows.h>
#include "../../Library/ImGui/imgui.h"
#include "../Manager.h"
#include "MainWindow.h"

bool SplashScreen::Render() {
	constexpr ImGuiWindowFlags kSplashFlags =
		ImGuiWindowFlags_NoTitleBar |
		ImGuiWindowFlags_NoMove |
		ImGuiWindowFlags_NoResize |
		ImGuiWindowFlags_NoCollapse |
		ImGuiWindowFlags_NoScrollbar |
		ImGuiWindowFlags_NoSavedSettings |
		ImGuiWindowFlags_NoDocking;

	const ImVec2 kDesiredSize = ImVec2(350.0f, 150.0f);
	ImGui::SetNextWindowSize(kDesiredSize);

	const float screen_center_x = GetSystemMetrics(SM_CXSCREEN) / 2.0f;
	const float screen_center_y = GetSystemMetrics(SM_CYSCREEN) / 2.0f;
	ImGui::SetNextWindowPos(ImVec2(screen_center_x - kDesiredSize.x / 2.0f,
		screen_center_y - kDesiredSize.y / 2.0f), ImGuiCond_Always);

	ImGui::SetNextWindowBgAlpha(1.0f);

	if (ImGui::Begin("##SplashScreen", nullptr, kSplashFlags)) {
		ImVec2 window_size = ImGui::GetWindowSize();
		ImVec2 center_pos = ImVec2(window_size.x * 0.5f, window_size.y * 0.5f);

		const char* loading_text = "Loading Application...";
		ImVec2 text_size = ImGui::CalcTextSize(loading_text);
		ImGui::SetCursorPos(ImVec2(center_pos.x - text_size.x * 0.5f, center_pos.y - text_size.y * 0.5f - 10.0f));
		ImGui::TextUnformatted(loading_text);

		int dots = (frame_counter_ / 30) % 4;
		std::string progress_text = "";
		for (int i = 0; i < dots; ++i) {
			progress_text += ".";
		}
		ImVec2 progress_text_size = ImGui::CalcTextSize(progress_text.c_str());
		ImGui::SetCursorPos(ImVec2(center_pos.x - progress_text_size.x * 0.5f, center_pos.y + text_size.y * 0.5f));
		ImGui::TextUnformatted(progress_text.c_str());

		frame_counter_++;

		if (frame_counter_ > kDelayFrames) {
			Manager::SwitchWindow(std::make_unique<MainWindow>());
		}
		ImGui::End();
	}
	return true;
}