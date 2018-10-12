#include "MainWindow.h"

#include"boost/make_shared.hpp"

MainWindow::MainWindow(int cols, int rows, std::function<void()> delegateFunction, int redrawDelay) : wxFrame(nullptr, wxID_ANY, "")
{
	_sizer = new wxBoxSizer(wxVERTICAL);
	SetSizer(_sizer);

	_ledPanel = boost::make_shared<LedPanel>(this, cols, rows);
	_sizer->Add(_ledPanel.get(), 1, wxALL | wxEXPAND, 5);

	_redrawer = boost::make_shared<Redrawer>(delegateFunction);
	_redrawer->Start(redrawDelay);
}


MainWindow::~MainWindow()
{
	_redrawer->Stop();
}
