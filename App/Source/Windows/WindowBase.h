#pragma once

class WindowBase {
public:
	virtual ~WindowBase() = default;

	virtual bool Render() = 0;
};
