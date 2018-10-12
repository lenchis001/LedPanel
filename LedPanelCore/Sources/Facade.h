#pragma once

#include"functional"

#ifdef IMPLEMENTATION  
#define DLL_MARK    __declspec(dllexport)  
#else  
#define DLL_MARK    __declspec(dllimport)  
#endif
namespace LedPanelCore {
	DLL_MARK
	void showWindow(int cols, int rows, std::function<void()> delegateFunction, int redrawMilliseconds);
	DLL_MARK
	void closeWindow();
	
	DLL_MARK
	void setLed(int col, int row, int red, int green, int blue);
	DLL_MARK
	void clearLed(int col, int row);
	DLL_MARK
	void clearAllLeds();

	DLL_MARK
	void drawText(std::wstring text, int col = 0, int row = 0);
}
