#include "../Global.h"
#include <shellapi.h> // required for shellexecutea

bool MainWindow::Render() {
	constexpr ImGuiWindowFlags mainFlags =
		ImGuiWindowFlags_NoSavedSettings |
		ImGuiWindowFlags_NoCollapse |
		ImGuiWindowFlags_NoScrollbar;

	const ImVec2 desiredSize = ImVec2(300.0f, 300.0f);
	ImGui::SetNextWindowSize(desiredSize, ImGuiCond_FirstUseEver);
	ImGui::SetNextWindowPos(ImVec2(GetSystemMetrics(SM_CXSCREEN) / 2.0f - desiredSize.x / 2.0f,
		GetSystemMetrics(SM_CYSCREEN) / 2.0f - desiredSize.y / 2.0f), ImGuiCond_FirstUseEver);

	if (ImGui::Begin("Main Application", &isOpen, mainFlags)) {
		const ImVec2 windowSize = ImGui::GetWindowSize();
		float buttonWidth = (windowSize.x - ImGui::GetStyle().WindowPadding.x * 2 - ImGui::GetStyle().ItemSpacing.x * 2) / 2.0f;

		if (ImGui::Button("web", ImVec2(buttonWidth, 0.0f)))
			ShellExecuteA(nullptr, "open", "https://ninetieth.xyz/", nullptr, nullptr, SW_SHOWNORMAL);
		ImGui::SameLine();

		if (ImGui::Button("git", ImVec2(buttonWidth, 0.0f)))
			ShellExecuteA(nullptr, "open", "https://github.com/90th/ImGui-AppKit-DX11", nullptr, nullptr, SW_SHOWNORMAL);

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
	return isOpen;
}