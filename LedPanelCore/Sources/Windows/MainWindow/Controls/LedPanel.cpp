#include "LedPanel.h"

#include"boost/make_shared.hpp"

#include"Consts.h"

#define DEFAULT_COLOR wxColor(200,200,200)

LedPanel::LedPanel(wxWindow *parent, int cols, int rows): wxPanel(parent, LED_PANEL_ID)
{
	SetBackgroundColour(wxColor(255, 255, 255));

	_sizer = new wxGridSizer(rows, cols, 1, 1);
	SetSizer(_sizer);

	for (int j = 0; j < rows; j++) {
		std::vector<boost::shared_ptr<wxPanel>> colLeds;

		for (int i = 0; i < cols; i++) {
			auto led = boost::make_shared<wxPanel>(this);
			led->SetBackgroundColour(DEFAULT_COLOR);

			_sizer->Add(led.get(), 0, wxALL | wxEXPAND, 1);

			colLeds.push_back(led);
		}

		_leds.push_back(colLeds);
	}
}


LedPanel::~LedPanel()
{
}

void LedPanel::drawText(std::wstring text, int col, int row)
{

}

void LedPanel::setLed(int col, int row, wxColor color)
{
	_leds[row][col]->SetBackgroundColour(color);

	_leds[row][col]->Refresh();
}

void LedPanel::clearLed(int col, int row)
{
	_leds[col][row]->SetBackgroundColour(DEFAULT_COLOR);

	_leds[col][row]->Refresh();
}

void LedPanel::clearAllLeds()
{
	for(auto col: _leds)
	{
		for(auto led: col)
		{
			led->SetBackgroundColour(DEFAULT_COLOR);

			led->Refresh();
		}
	}
}
