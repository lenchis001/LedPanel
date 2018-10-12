#pragma once

#include"vector"

#include"wx/wx.h"

#include"boost/shared_ptr.hpp"

class LedPanel: public wxPanel
{
public:
	LedPanel(wxWindow *parent, int cols, int rows);
	~LedPanel();

	void drawText(std::wstring text, int col = 0, int row = 0);

	void setLed(int col, int row, wxColor color);
	void clearLed(int col, int row);
	void clearAllLeds();
private:
	wxSizer *_sizer;

	std::vector<std::vector<boost::shared_ptr<wxPanel>>> _leds;
};

