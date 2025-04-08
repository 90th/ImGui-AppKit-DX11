#pragma once

#include "WindowBase.h"

class MainWindow : public WindowBase {
public:
	bool Render() override;

private:
	bool isOpen = true;
};
