#pragma once

#include "WindowBase.h"

class MainWindow : public WindowBase {
public:
	MainWindow() = default;
	bool Render() override;

private:
	bool is_open_ = true;
};
