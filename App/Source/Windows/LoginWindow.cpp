#include "../Global.h"

void LoginWindow::Render() {
	Manager::SetNextSize(300.0f, 95.0f);

	ImVec2 windowSize = ImGui::GetWindowSize();

	constexpr float textBoxWidth = 250.0f;
	ImGui::PushItemWidth(textBoxWidth);
	ImGui::SetCursorPosX((windowSize.x - textBoxWidth) * 0.5f);
	ImGui::InputTextWithHint("##license", "license", UsernameField, IM_ARRAYSIZE(UsernameField));
	ImGui::PopItemWidth();
	ImGui::Spacing();

	ImGui::SetCursorPosX((windowSize.x - textBoxWidth) * 0.5f);
	ImGui::Checkbox("remember", &RememberCredentials);

	ImGui::SameLine();
	constexpr float buttonWidth = 45.0f;
	const float buttonPosX = (windowSize.x - textBoxWidth) * 0.5f + textBoxWidth - buttonWidth;
	ImGui::SetCursorPosX(buttonPosX);
	if (ImGui::Button("login", ImVec2(buttonWidth, 0.0f))) {
		Manager::SwitchWindow(std::make_unique<MainWindow>());
	}

	ImGui::Spacing();
}