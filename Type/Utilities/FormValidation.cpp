#include "FormValidation.h"

namespace PassportTable {

	// �������� �� ���� ����� ���� float
	void CheckFloatInKeyPress(System::Windows::Forms::KeyPressEventArgs^  e)
	{
		if (e->KeyChar == '.') e->KeyChar = ',';
		if (e->KeyChar > '9' || e->KeyChar < '0' && e->KeyChar != (char)8 && e->KeyChar != ',')
		{
			e->KeyChar = (char)0;
		}
	}

	// �������� ������������ �������� �������� ���
	bool bCheckDimentionsTextBoxes(TextBox^ textBoxLength, ErrorProvider^ errorProviderLength, TextBox^ textBoxWidth, ErrorProvider^ errorProviderWidth, TextBox^ textBoxHeight, ErrorProvider^ errorProviderHeight, TextBox^ textBoxPort, ErrorProvider^ errorProviderPort)
	{
		errorProviderLength->SetError(textBoxLength, "");
		errorProviderWidth->SetError(textBoxWidth, "");
		errorProviderHeight->SetError(textBoxHeight, "");
		errorProviderPort->SetError(textBoxPort, "");

		bool bHasErrors = false;

		bIsTextBoxEmpty(textBoxLength, errorProviderLength);
		bIsTextBoxEmpty(textBoxWidth, errorProviderWidth);
		bIsTextBoxEmpty(textBoxHeight, errorProviderHeight);
		bIsTextBoxEmpty(textBoxPort, errorProviderPort);

		//bHasErrors = bIsFloatString(marshal_as<std::string>(textBoxLength->Text);
		//bHasErrors = bIsFloatString(marshal_as<std::string>(textBoxWidth->Text);
		//bHasErrors = bIsFloatString(marshal_as<std::string>(textBoxHeight->Text);
		//bHasErrors = bIsFloatString(marshal_as<std::string>(textBoxPort->Text);

		//bIsToleranceValid(currentTransducer.dimensionsX, textBoxLength, errorProviderLength, 20);
		//bIsToleranceValid(currentTransducer.dimensionsY, textBoxWidth, errorProviderWidth, 20);
		//bIsToleranceValid(currentTransducer.dimensionsZ, textBoxHeight, errorProviderHeight, 20);
		//bIsToleranceValid(currentTransducer.dimension_port, textBoxPort, errorProviderPort, 10);

		if (!System::String::IsNullOrEmpty(errorProviderLength->GetError(textBoxLength))) bHasErrors = true;
		if (!System::String::IsNullOrEmpty(errorProviderWidth->GetError(textBoxWidth))) bHasErrors = true;
		if (!System::String::IsNullOrEmpty(errorProviderHeight->GetError(textBoxHeight))) bHasErrors = true;
		if (!System::String::IsNullOrEmpty(errorProviderPort->GetError(textBoxPort))) bHasErrors = true;

		return bHasErrors;
	}

	// �������� ������� �������� � ����
	bool bIsTextBoxEmpty(TextBox^ pTextBox, ErrorProvider^ pErrorProvider)
	{
		if (System::String::IsNullOrEmpty(pTextBox->Text))
		{
			if (pErrorProvider)
			{
				if (System::String::IsNullOrEmpty(pErrorProvider->GetError(pTextBox)))
				{
					pErrorProvider->SetError(pTextBox, "���� ������");
				}
			}
			return true;
		}
		else
		{
			return false;
		}
	}

	// ��������� �� ������� float � ������
	bool bIsFloatString(const std::string& string)
	{
		std::string::const_iterator it = string.begin();
		bool decimalPoint = false;
		int minSize = 0;
		if (string.size() > 0 && (string[0] == '-' || string[0] == '+'))
		{
			it++;
			minSize++;
		}
		while (it != string.end())
		{
			if (*it == ',')
			{
				if (!decimalPoint) decimalPoint = true;
				else break;
			}
			else if (!std::isdigit(*it) && ((*it != 'f') || it + 1 != string.end() || !decimalPoint))
			{
				break;
			}
			++it;
		}
		return string.size() > minSize && it == string.end();
	}

	// �������� �������� ���������� � ����
	bool bIsToleranceValid(float baseSize, TextBox^ textBox, ErrorProvider^ errorProvider, int percentTolerance)
	{
		float temp;
		if (float::TryParse(textBox->Text, temp))
		{
			if (!bCompareSizes(baseSize, float::Parse(textBox->Text), percentTolerance))
			{
				if (errorProvider)
				{
					if (System::String::IsNullOrEmpty(errorProvider->GetError(textBox)))
					{
						errorProvider->SetError(textBox, "���������� �� ������������ �������� ������ ��� �� " + percentTolerance + " ���������");
					}
				}
				return false;
			}
			else
			{
				return true;
			}
		}
		else return true;
	}

	// ��������� ���������� ���� �������� ���� float � ���������
	bool bCompareSizes(float baseSize, float newSize, float percentDifference)
	{
		if (abs(newSize - baseSize) / baseSize * 100 < percentDifference) return true;
		else return false;
	}

	// �������� ����������� ���������� � ���� ��������
	void LoadSizeTextBoxesInfo(System::Windows::Forms::TextBox^ textBoxLength, System::Windows::Forms::TextBox^  textBoxWidth, System::Windows::Forms::TextBox^  textBoxHeight, System::Windows::Forms::TextBox^  textBoxPort)
	{
		//textBoxLength->Text = System::Convert::ToString(currentTransducer.dimensionsX);
		//textBoxWidth->Text = System::Convert::ToString(currentTransducer.dimensionsY);
		//textBoxHeight->Text = System::Convert::ToString(currentTransducer.dimensionsZ);
		//textBoxPort->Text = System::Convert::ToString(currentTransducer.dimension_port);
	}

	// ��������� ����� ������
	void SetColorOnButton(System::Windows::Forms::Button^ pButton, int r, int g, int b)
	{
		pButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(r)), static_cast<System::Int32>(static_cast<System::Byte>(g)), static_cast<System::Int32>(static_cast<System::Byte>(b)));
	}

	// �������������� � ������ ������ ����� �������
	std::string PrecisionCast(float number, int precision)
	{
		std::stringstream stream;
		stream << std::fixed << std::setprecision(precision) << number;
		std::string temp = stream.str();
		std::replace(temp.begin(), temp.end(), '.', ',');
		return temp;
	}

}
