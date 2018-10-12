#pragma once

#include"wx/wx.h"

#include"functional"

class Redrawer:public wxTimer
{
public:
	void Notify() override;

	Redrawer(std::function<void()> delegateFunction);
	~Redrawer();

private:
	std::function<void()> _delegateFunction;
};

