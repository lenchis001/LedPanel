#include "App.h"

#include"Windows\MainWindow\MainWindow.h"

App::App(int cols, int rows, std::function<void()> delegateFunction, int redrawDelay)
{
	_cols = cols;
	_rows = rows;
	_delegateFunction = delegateFunction;
	_redrawDelay = redrawDelay;
}

bool App::OnInit()
{
	// call the base class initialization method, currently it only parses a
	// few common command-line options but it could be do more in the future
	if (!wxApp::OnInit())
		return false;

	MainWindow *window = new MainWindow(_cols, _rows, _delegateFunction, _redrawDelay);

	window->Show();

	// success: wxApp::OnRun() will be called which will enter the main message
	// loop and the application will run. If we returned false here, the
	// application would exit immediately.
	return true;
}
