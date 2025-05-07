#pragma once

#include <Windows.h>
#include <d3d11.h>

namespace Render {
	namespace Data {
		inline HWND MainWindow = nullptr;
		inline ID3D11Device* Device = nullptr;
		inline ID3D11DeviceContext* DeviceContext = nullptr;
		inline IDXGISwapChain* SwapChain = nullptr;
		inline ID3D11RenderTargetView* RenderTargetView = nullptr;
	}

	bool CreateRenderTarget();
	bool CreateDevice();

	void CleanupRenderTarget();
	void CleanupDevice();

	void Loop();

	LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
}