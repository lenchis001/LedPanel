#include "Facade.h"

#include"boost/shared_ptr.hpp"
#include"boost/make_shared.hpp"

#include"App.h"
#include"Consts.h"

#include"Windows\MainWindow\Controls\LedPanel.h"
#include"Windows/MainWindow/MainWindow.h"

#define ledPanel dynamic_cast<LedPanel*>(wxTheApp->GetTopWindow()->FindWindowById(LED_PANEL_ID))
#define mainWindow dynamic_cast<MainWindow*>(wxTheApp->GetTopWindow())

void LedPanelCore::showWindow(int cols, int rows, std::function<void()> delegateFunction, int redrawDelay)
{
	// MyWxApp derives from wxApp
	wxApp::SetInstance(new App(cols, rows, delegateFunction, redrawDelay));

	int argc = 1;
	char** argv = new char*{ "Program.exe" };

	wxEntryStart(argc, argv);
	wxTheApp->OnInit();

	wxTheApp->OnRun();
	wxTheApp->OnExit();
	wxEntryCleanup();
}

void LedPanelCore::closeWindow()
{
	wxTheApp->GetTopWindow()->Close();
}

void LedPanelCore::setLed(int col, int row, int red, int green, int blue)
{
	ledPanel->setLed(col, row, wxColor(red, green, blue));
}

void LedPanelCore::clearLed(int col, int row)
{
	ledPanel->clearLed(col, row);
}

void LedPanelCore::clearAllLeds()
{
	ledPanel->clearAllLeds();
}

void LedPanelCore::drawText(std::wstring text, int col = 0, int row = 0)
{
	ledPanel->drawText(text, col, row);
}
