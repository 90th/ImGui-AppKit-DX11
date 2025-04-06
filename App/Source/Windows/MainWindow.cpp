#include "../Global.h"

void MainWindow::Render() {
	Manager::SetNextSize(300.0f, 300.0f);

	const ImVec2 windowSize = ImGui::GetWindowSize();
	float buttonWidth = (windowSize.x - ImGui::GetStyle().WindowPadding.x * 2 - ImGui::GetStyle().ItemSpacing.x * 2) / 3.0f;

	if (ImGui::Button("log out", ImVec2(buttonWidth, 0.0f))) {
		Manager::SwitchWindow(std::make_unique<LoginWindow>());
		return;
	}
	ImGui::SameLine();

	if (ImGui::Button("web", ImVec2(buttonWidth, 0.0f)))
		ShellExecuteA(nullptr, "open", "https://ninetieth.xyz/", nullptr, nullptr, SW_SHOWNORMAL);
	ImGui::SameLine();

	if (ImGui::Button("git", ImVec2(buttonWidth, 0.0f)))
		ShellExecuteA(nullptr, "open", "https://github.com/90th/ImGui-AppKit-DX11", nullptr, nullptr, SW_SHOWNORMAL);

	ImGui::Separator();

	ImGui::TextWrapped("\nthis is the main application window content area.\n");
	ImGui::NewLine();
	ImGui::NewLine();
	ImGui::NewLine();
	ImGui::NewLine();
	ImGui::NewLine();
	ImGui::NewLine();
	ImGui::NewLine();

	ImGui::Separator();

	ImGui::Text("build on:");
	ImGui::SameLine();
	ImGui::Text(__DATE__);
	ImGui::SameLine();
	ImGui::Text(__TIME__);
}