#pragma once

#include"wx/wx.h"

#include"boost/shared_ptr.hpp"

#include"Controls/LedPanel.h"
#include"Controls/Redrawer.h"

class MainWindow: public wxFrame
{
public:
	MainWindow(int cols, int rows, std::function<void()> delegateFunction, int redrawDelay);
	~MainWindow();
private:
	wxSizer *_sizer;

	boost::shared_ptr<Redrawer> _redrawer;
	boost::shared_ptr<LedPanel> _ledPanel;
};

