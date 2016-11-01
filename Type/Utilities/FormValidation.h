#pragma once

#include <stdlib.h>
#include <cctype>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>

#include <msclr\marshal.h>
#include <msclr\marshal_cppstd.h>

//#include "Transducers.h"

using namespace msclr::interop;

//extern Transducer currentTransducer;

using namespace System::Windows::Forms;

namespace PassportTable {

	// --- Form Validation ---

	// Проверка на ввод числа типа float
	void CheckFloatInKeyPress(System::Windows::Forms::KeyPressEventArgs^  e);

	// Проверка введенных значений размеров
	bool bCheckDimentionsTextBoxes(TextBox^ textBoxLength,
		ErrorProvider^ errorProviderLength,
		TextBox^ textBoxWidth,
		ErrorProvider^ errorProviderWidth,
		TextBox^ textBoxHeight,
		ErrorProvider^ errorProviderHeight,
		TextBox^ textBoxPort,
		ErrorProvider^ errorProviderPort);

	// Проверка наличия значения в поле
	bool bIsTextBoxEmpty(TextBox^ textBox, ErrorProvider^ errorProvider);

	// Проврерка на наличие float в строке
	bool bIsFloatString(const std::string& string);

	bool bIsToleranceValid(float baseSize, TextBox^ textBox, ErrorProvider^ errorProvider, int percentTolerance);

	// --- Tools ---

	// Сравнение отклонения двух размеров типа float в процентах
	bool bCompareSizes(float baseSize, float newSize, float percentDifference);

	// Загрузка стандартной информации в поле размеров
	void LoadSizeTextBoxesInfo(TextBox^ textBoxLength, TextBox^ textBoxWidth, TextBox^ textBoxHeight, TextBox^ textBoxPort);

	// Изменение цвета кнопки
	void SetColorOnButton(Button^ pButton, int r, int g, int b);

	// Преобразование с числом знаков после запятой
	std::string PrecisionCast(float number, int precision);

}
