#pragma once

#include"functional"

#include"wx/wx.h"

class App: public wxApp
{
public:
	App(int cols, int rows, std::function<void()> delegateFunction, int redrawDelay);

	bool OnInit() override;
private:
	std::function<void()> _delegateFunction;
	int _redrawDelay, _cols, _rows;
};

