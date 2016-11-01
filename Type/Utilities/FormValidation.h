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

	// �������� �� ���� ����� ���� float
	void CheckFloatInKeyPress(System::Windows::Forms::KeyPressEventArgs^  e);

	// �������� ��������� �������� ��������
	bool bCheckDimentionsTextBoxes(TextBox^ textBoxLength,
		ErrorProvider^ errorProviderLength,
		TextBox^ textBoxWidth,
		ErrorProvider^ errorProviderWidth,
		TextBox^ textBoxHeight,
		ErrorProvider^ errorProviderHeight,
		TextBox^ textBoxPort,
		ErrorProvider^ errorProviderPort);

	// �������� ������� �������� � ����
	bool bIsTextBoxEmpty(TextBox^ textBox, ErrorProvider^ errorProvider);

	// ��������� �� ������� float � ������
	bool bIsFloatString(const std::string& string);

	bool bIsToleranceValid(float baseSize, TextBox^ textBox, ErrorProvider^ errorProvider, int percentTolerance);

	// --- Tools ---

	// ��������� ���������� ���� �������� ���� float � ���������
	bool bCompareSizes(float baseSize, float newSize, float percentDifference);

	// �������� ����������� ���������� � ���� ��������
	void LoadSizeTextBoxesInfo(TextBox^ textBoxLength, TextBox^ textBoxWidth, TextBox^ textBoxHeight, TextBox^ textBoxPort);

	// ��������� ����� ������
	void SetColorOnButton(Button^ pButton, int r, int g, int b);

	// �������������� � ������ ������ ����� �������
	std::string PrecisionCast(float number, int precision);

}
