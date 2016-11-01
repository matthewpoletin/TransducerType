#include <iostream>

#include "MainForm.h"

//#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

using namespace PassportTable;

int main()
{
	Application::EnableVisualStyles();

	Application::Run(gcnew MainForm());

	return 0;
}