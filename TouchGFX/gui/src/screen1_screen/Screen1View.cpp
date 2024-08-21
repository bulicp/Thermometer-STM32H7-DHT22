#include <gui/screen1_screen/Screen1View.hpp>

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::updateTempData(DHT22_DataTypedef* DHT22_Data)
{
	Unicode::snprintfFloat(textArea3Buffer, TEXTAREA3_SIZE, "%2.1f", DHT22_Data->Temperature);
	Unicode::snprintfFloat(textArea4Buffer, TEXTAREA4_SIZE, "%2.1f", DHT22_Data->Humidity);
	textArea3.invalidate();
	textArea4.invalidate();
}

