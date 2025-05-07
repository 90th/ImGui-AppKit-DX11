#include "MainWindow.h"
#include <Windows.h>
#include <shellapi.h>
#include "../../Library/ImGui/imgui.h"

bool MainWindow::Render() {
	constexpr ImGuiWindowFlags kMainFlags =
		ImGuiWindowFlags_NoSavedSettings |
		ImGuiWindowFlags_NoCollapse |
		ImGuiWindowFlags_NoScrollbar;

	const ImVec2 kDesiredSize = ImVec2(300.0f, 300.0f);
	ImGui::SetNextWindowSize(kDesiredSize, ImGuiCond_FirstUseEver);

	const float screen_center_x = GetSystemMetrics(SM_CXSCREEN) / 2.0f;
	const float screen_center_y = GetSystemMetrics(SM_CYSCREEN) / 2.0f;
	ImGui::SetNextWindowPos(ImVec2(screen_center_x - kDesiredSize.x / 2.0f,
		screen_center_y - kDesiredSize.y / 2.0f), ImGuiCond_FirstUseEver);

	if (ImGui::Begin("Main Application", &is_open_, kMainFlags)) {
		const ImVec2 window_size = ImGui::GetWindowSize();
		const float button_width = (window_size.x - ImGui::GetStyle().WindowPadding.x * 2.0f - ImGui::GetStyle().ItemSpacing.x) / 2.0f;

		if (ImGui::Button("Web", ImVec2(button_width, 0.0f))) {
			ShellExecuteA(nullptr, "open", "https://ninetieth.xyz/", nullptr, nullptr, SW_SHOWNORMAL);
		}
		ImGui::SameLine();

		if (ImGui::Button("Git", ImVec2(button_width, 0.0f))) {
			ShellExecuteA(nullptr, "open", "https://github.com/90th/ImGui-AppKit-DX11", nullptr, nullptr, SW_SHOWNORMAL);
		}

		ImGui::Separator();

		ImGui::TextWrapped("\nthis is the main application window content area.\n");
		ImGui::NewLine(); ImGui::NewLine(); ImGui::NewLine(); ImGui::NewLine();
		ImGui::NewLine(); ImGui::NewLine(); ImGui::NewLine();

		ImGui::Separator();

		ImGui::Text("build on:");
		ImGui::SameLine(); ImGui::Text(__DATE__);
		ImGui::SameLine(); ImGui::Text(__TIME__);

		ImGui::End();
	}
	return is_open_;
}