#pragma once

#include "StandartTransducer.h"
#include "StandartTransducerManager.h"
#include "Utilities/FormValidation.h"

#include <string.h>

#include <msclr/marshal.h>
#include <msclr/marshal_cppstd.h>
using namespace msclr::interop;

namespace PassportTable {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;

	public ref class TransducerTypeForm : public System::Windows::Forms::Form
	{
	public:
		TransducerTypeForm(void)
		{
			InitializeComponent();
		}

		bool Init(StandartTransducer* st)
		{
			if (st != nullptr)
			{
				this->st = st;
			
				// TODO: заполнить загрузку всех параметров
				this->comboBoxType->SelectedIndex = st->type;
				this->textBoxName->Text = marshal_as<String^>(st->name);
				if (st->dimensionsX != 0) this->textBoxLength->Text = st->dimensionsX.ToString();
				if (st->dimensionsY != 0) this->textBoxWidth->Text = st->dimensionsY.ToString();
				if (st->dimensionsZ != 0) this->textBoxHeight->Text = st->dimensionsZ.ToString();
				if (st->dimension_port != 0) this->textBoxPort->Text = st->dimension_port.ToString();

				//...
			}
			else
			{
				std::cerr << "Transducer is not specified" << std::endl;
			}
			return true;
		}

	protected:
		~TransducerTypeForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		StandartTransducer* st;

	private: System::Windows::Forms::Button^  buttonSave;

	private:
		System::Windows::Forms::Label^  labelType;
		System::Windows::Forms::ComboBox^  comboBoxType;
		System::Windows::Forms::ErrorProvider^  errorProviderType;

	private:
		System::Windows::Forms::Label^  labelName;
		System::Windows::Forms::TextBox^  textBoxName;
		System::Windows::Forms::ErrorProvider^  errorProviderName;

	private:
		System::Windows::Forms::Label^  labelLength;
		System::Windows::Forms::TextBox^  textBoxLength;
		System::Windows::Forms::ErrorProvider^  errorProviderLength;

	private:
		System::Windows::Forms::Label^  labelWidth;
		System::Windows::Forms::TextBox^  textBoxWidth;
		System::Windows::Forms::ErrorProvider^  errorProviderWidth;

	private:
		System::Windows::Forms::Label^  labelHeight;
		System::Windows::Forms::TextBox^  textBoxHeight;
		System::Windows::Forms::ErrorProvider^  errorProviderHeight;

	private:
		System::Windows::Forms::Label^  labelPort;
		System::Windows::Forms::TextBox^  textBoxPort;
		System::Windows::Forms::ErrorProvider^  errorProviderPort;

	private:
		System::Windows::Forms::Label^  labelDimentionPiezo;
		System::Windows::Forms::TextBox^  textBoxDimentionPiezo;

	private:
		System::Windows::Forms::Label^  labelMass;
		System::Windows::Forms::TextBox^  textBoxMass;
	
	private:
		System::Windows::Forms::Label^  labelConnectorType;
		System::Windows::Forms::TextBox^  textBoxConnectorType;

	private:
		System::Windows::Forms::Label^  labelCapacity;
		System::Windows::Forms::TextBox^  textBoxCapacity;

	private:
		System::Windows::Forms::Label^  labelCapacityError;
		System::Windows::Forms::TextBox^  textBoxCapacityError;

	private:
		System::Windows::Forms::Label^  labeleEectricalDamper;
		System::Windows::Forms::TextBox^  textBoxElectricalDamper;

	private:
		System::Windows::Forms::Label^  labelMatchingInductance;
		System::Windows::Forms::ComboBox^  comboBoxMatchingInductance;
	
	private:
		System::Windows::Forms::Label^  labelImpulseAmplitude;
		System::Windows::Forms::TextBox^  textBoxImpulseAmplitude;

	private:
		System::Windows::Forms::Label^  labelAmplitudeRange;
		System::Windows::Forms::ComboBox^  comboBoxAmplitudeRange;
	
	private: System::Windows::Forms::ErrorProvider^  errorProvider7;
	private: System::Windows::Forms::ErrorProvider^  errorProvider8;
	private: System::Windows::Forms::ErrorProvider^  errorProvider9;
	private: System::Windows::Forms::ErrorProvider^  errorProvider10;
	private: System::Windows::Forms::ErrorProvider^  errorProvider11;

	private: System::ComponentModel::IContainer^  components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->buttonSave = (gcnew System::Windows::Forms::Button());
			this->textBoxLength = (gcnew System::Windows::Forms::TextBox());
			this->labelType = (gcnew System::Windows::Forms::Label());
			this->labelName = (gcnew System::Windows::Forms::Label());
			this->labelLength = (gcnew System::Windows::Forms::Label());
			this->labelWidth = (gcnew System::Windows::Forms::Label());
			this->labelHeight = (gcnew System::Windows::Forms::Label());
			this->labelPort = (gcnew System::Windows::Forms::Label());
			this->labelDimentionPiezo = (gcnew System::Windows::Forms::Label());
			this->labelMass = (gcnew System::Windows::Forms::Label());
			this->labelConnectorType = (gcnew System::Windows::Forms::Label());
			this->labelCapacity = (gcnew System::Windows::Forms::Label());
			this->labelCapacityError = (gcnew System::Windows::Forms::Label());
			this->labeleEectricalDamper = (gcnew System::Windows::Forms::Label());
			this->labelMatchingInductance = (gcnew System::Windows::Forms::Label());
			this->labelImpulseAmplitude = (gcnew System::Windows::Forms::Label());
			this->labelAmplitudeRange = (gcnew System::Windows::Forms::Label());
			this->comboBoxType = (gcnew System::Windows::Forms::ComboBox());
			this->textBoxWidth = (gcnew System::Windows::Forms::TextBox());
			this->textBoxHeight = (gcnew System::Windows::Forms::TextBox());
			this->textBoxPort = (gcnew System::Windows::Forms::TextBox());
			this->textBoxDimentionPiezo = (gcnew System::Windows::Forms::TextBox());
			this->textBoxMass = (gcnew System::Windows::Forms::TextBox());
			this->textBoxConnectorType = (gcnew System::Windows::Forms::TextBox());
			this->textBoxCapacity = (gcnew System::Windows::Forms::TextBox());
			this->textBoxCapacityError = (gcnew System::Windows::Forms::TextBox());
			this->textBoxElectricalDamper = (gcnew System::Windows::Forms::TextBox());
			this->textBoxImpulseAmplitude = (gcnew System::Windows::Forms::TextBox());
			this->comboBoxAmplitudeRange = (gcnew System::Windows::Forms::ComboBox());
			this->textBoxName = (gcnew System::Windows::Forms::TextBox());
			this->errorProviderType = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->errorProviderName = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->errorProviderLength = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->errorProviderWidth = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->errorProviderHeight = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->errorProviderPort = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->errorProvider7 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->errorProvider8 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->errorProvider9 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->errorProvider10 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->errorProvider11 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->comboBoxMatchingInductance = (gcnew System::Windows::Forms::ComboBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProviderType))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProviderName))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProviderLength))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProviderWidth))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProviderHeight))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProviderPort))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider9))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider11))->BeginInit();
			this->SuspendLayout();
			// 
			// buttonSave
			// 
			this->buttonSave->Location = System::Drawing::Point(12, 606);
			this->buttonSave->Name = L"buttonSave";
			this->buttonSave->Size = System::Drawing::Size(190, 23);
			this->buttonSave->TabIndex = 30;
			this->buttonSave->Text = L"Сохранить";
			this->buttonSave->UseVisualStyleBackColor = true;
			this->buttonSave->Click += gcnew System::EventHandler(this, &TransducerTypeForm::buttonSave_Click);
			// 
			// textBoxLength
			// 
			this->textBoxLength->Location = System::Drawing::Point(12, 105);
			this->textBoxLength->Name = L"textBoxLength";
			this->textBoxLength->Size = System::Drawing::Size(190, 20);
			this->textBoxLength->TabIndex = 5;
			this->textBoxLength->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &TransducerTypeForm::textBoxLength_KeyPress);
			// 
			// labelType
			// 
			this->labelType->AutoSize = true;
			this->labelType->Location = System::Drawing::Point(12, 9);
			this->labelType->Name = L"labelType";
			this->labelType->Size = System::Drawing::Size(118, 13);
			this->labelType->TabIndex = 0;
			this->labelType->Text = L"Тип преобразователя";
			// 
			// labelName
			// 
			this->labelName->AutoSize = true;
			this->labelName->Location = System::Drawing::Point(12, 49);
			this->labelName->Name = L"labelName";
			this->labelName->Size = System::Drawing::Size(83, 13);
			this->labelName->TabIndex = 2;
			this->labelName->Text = L"Наименование";
			// 
			// labelLength
			// 
			this->labelLength->AutoSize = true;
			this->labelLength->Location = System::Drawing::Point(12, 89);
			this->labelLength->Name = L"labelLength";
			this->labelLength->Size = System::Drawing::Size(40, 13);
			this->labelLength->TabIndex = 4;
			this->labelLength->Text = L"Длина";
			// 
			// labelWidth
			// 
			this->labelWidth->AutoSize = true;
			this->labelWidth->Location = System::Drawing::Point(12, 128);
			this->labelWidth->Name = L"labelWidth";
			this->labelWidth->Size = System::Drawing::Size(46, 13);
			this->labelWidth->TabIndex = 6;
			this->labelWidth->Text = L"Ширина";
			// 
			// labelHeight
			// 
			this->labelHeight->AutoSize = true;
			this->labelHeight->Location = System::Drawing::Point(12, 167);
			this->labelHeight->Name = L"labelHeight";
			this->labelHeight->Size = System::Drawing::Size(45, 13);
			this->labelHeight->TabIndex = 8;
			this->labelHeight->Text = L"Высота";
			// 
			// labelPort
			// 
			this->labelPort->AutoSize = true;
			this->labelPort->Location = System::Drawing::Point(12, 206);
			this->labelPort->Name = L"labelPort";
			this->labelPort->Size = System::Drawing::Size(114, 13);
			this->labelPort->TabIndex = 10;
			this->labelPort->Text = L"Расстояние до порта";
			// 
			// labelDimentionPiezo
			// 
			this->labelDimentionPiezo->AutoSize = true;
			this->labelDimentionPiezo->Enabled = false;
			this->labelDimentionPiezo->Location = System::Drawing::Point(12, 248);
			this->labelDimentionPiezo->Name = L"labelDimentionPiezo";
			this->labelDimentionPiezo->Size = System::Drawing::Size(135, 13);
			this->labelDimentionPiezo->TabIndex = 12;
			this->labelDimentionPiezo->Text = L"Диаметр пьезоэлемента";
			// 
			// labelMass
			// 
			this->labelMass->AutoSize = true;
			this->labelMass->Enabled = false;
			this->labelMass->Location = System::Drawing::Point(12, 287);
			this->labelMass->Name = L"labelMass";
			this->labelMass->Size = System::Drawing::Size(40, 13);
			this->labelMass->TabIndex = 14;
			this->labelMass->Text = L"Масса";
			// 
			// labelConnectorType
			// 
			this->labelConnectorType->AutoSize = true;
			this->labelConnectorType->Enabled = false;
			this->labelConnectorType->Location = System::Drawing::Point(12, 326);
			this->labelConnectorType->Name = L"labelConnectorType";
			this->labelConnectorType->Size = System::Drawing::Size(88, 13);
			this->labelConnectorType->TabIndex = 16;
			this->labelConnectorType->Text = L"Тип коннектора";
			// 
			// labelCapacity
			// 
			this->labelCapacity->AutoSize = true;
			this->labelCapacity->Enabled = false;
			this->labelCapacity->Location = System::Drawing::Point(12, 365);
			this->labelCapacity->Name = L"labelCapacity";
			this->labelCapacity->Size = System::Drawing::Size(51, 13);
			this->labelCapacity->TabIndex = 18;
			this->labelCapacity->Text = L"Емкость";
			// 
			// labelCapacityError
			// 
			this->labelCapacityError->AutoSize = true;
			this->labelCapacityError->Enabled = false;
			this->labelCapacityError->Location = System::Drawing::Point(12, 404);
			this->labelCapacityError->Name = L"labelCapacityError";
			this->labelCapacityError->Size = System::Drawing::Size(91, 13);
			this->labelCapacityError->TabIndex = 20;
			this->labelCapacityError->Text = L"Допуск ёмкости";
			// 
			// labeleEectricalDamper
			// 
			this->labeleEectricalDamper->AutoSize = true;
			this->labeleEectricalDamper->Enabled = false;
			this->labeleEectricalDamper->Location = System::Drawing::Point(12, 443);
			this->labeleEectricalDamper->Name = L"labeleEectricalDamper";
			this->labeleEectricalDamper->Size = System::Drawing::Size(86, 13);
			this->labeleEectricalDamper->TabIndex = 22;
			this->labeleEectricalDamper->Text = L"electricalDamper";
			// 
			// labelMatchingInductance
			// 
			this->labelMatchingInductance->AutoSize = true;
			this->labelMatchingInductance->Enabled = false;
			this->labelMatchingInductance->Location = System::Drawing::Point(12, 483);
			this->labelMatchingInductance->Name = L"labelMatchingInductance";
			this->labelMatchingInductance->Size = System::Drawing::Size(155, 13);
			this->labelMatchingInductance->TabIndex = 24;
			this->labelMatchingInductance->Text = L"Согласующая индуктивность";
			// 
			// labelImpulseAmplitude
			// 
			this->labelImpulseAmplitude->AutoSize = true;
			this->labelImpulseAmplitude->Enabled = false;
			this->labelImpulseAmplitude->Location = System::Drawing::Point(12, 522);
			this->labelImpulseAmplitude->Name = L"labelImpulseAmplitude";
			this->labelImpulseAmplitude->Size = System::Drawing::Size(114, 13);
			this->labelImpulseAmplitude->TabIndex = 26;
			this->labelImpulseAmplitude->Text = L"Амплитуда импульса";
			// 
			// labelAmplitudeRange
			// 
			this->labelAmplitudeRange->AutoSize = true;
			this->labelAmplitudeRange->Enabled = false;
			this->labelAmplitudeRange->Location = System::Drawing::Point(12, 561);
			this->labelAmplitudeRange->Name = L"labelAmplitudeRange";
			this->labelAmplitudeRange->Size = System::Drawing::Size(112, 13);
			this->labelAmplitudeRange->TabIndex = 28;
			this->labelAmplitudeRange->Text = L"Диапазон амплитды";
			// 
			// comboBoxType
			// 
			this->comboBoxType->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxType->FormattingEnabled = true;
			this->comboBoxType->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"Наклонный совмещённый", L"Прямой совмещённый",
					L"Прямой раздельно-совмещённый"
			});
			this->comboBoxType->Location = System::Drawing::Point(12, 25);
			this->comboBoxType->Name = L"comboBoxType";
			this->comboBoxType->Size = System::Drawing::Size(190, 21);
			this->comboBoxType->TabIndex = 1;
			// 
			// textBoxWidth
			// 
			this->textBoxWidth->Location = System::Drawing::Point(12, 144);
			this->textBoxWidth->Name = L"textBoxWidth";
			this->textBoxWidth->Size = System::Drawing::Size(190, 20);
			this->textBoxWidth->TabIndex = 7;
			this->textBoxWidth->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &TransducerTypeForm::textBoxWidth_KeyPress);
			// 
			// textBoxHeight
			// 
			this->textBoxHeight->Location = System::Drawing::Point(12, 183);
			this->textBoxHeight->Name = L"textBoxHeight";
			this->textBoxHeight->Size = System::Drawing::Size(190, 20);
			this->textBoxHeight->TabIndex = 9;
			this->textBoxHeight->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &TransducerTypeForm::textBoxHeight_KeyPress);
			// 
			// textBoxPort
			// 
			this->textBoxPort->Location = System::Drawing::Point(12, 222);
			this->textBoxPort->Name = L"textBoxPort";
			this->textBoxPort->Size = System::Drawing::Size(190, 20);
			this->textBoxPort->TabIndex = 11;
			this->textBoxPort->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &TransducerTypeForm::textBoxPort_KeyPress);
			// 
			// textBoxDimentionPiezo
			// 
			this->textBoxDimentionPiezo->Enabled = false;
			this->textBoxDimentionPiezo->Location = System::Drawing::Point(12, 264);
			this->textBoxDimentionPiezo->Name = L"textBoxDimentionPiezo";
			this->textBoxDimentionPiezo->Size = System::Drawing::Size(190, 20);
			this->textBoxDimentionPiezo->TabIndex = 13;
			// 
			// textBoxMass
			// 
			this->textBoxMass->Enabled = false;
			this->textBoxMass->Location = System::Drawing::Point(12, 303);
			this->textBoxMass->Name = L"textBoxMass";
			this->textBoxMass->Size = System::Drawing::Size(190, 20);
			this->textBoxMass->TabIndex = 15;
			// 
			// textBoxConnectorType
			// 
			this->textBoxConnectorType->Enabled = false;
			this->textBoxConnectorType->Location = System::Drawing::Point(12, 342);
			this->textBoxConnectorType->Name = L"textBoxConnectorType";
			this->textBoxConnectorType->Size = System::Drawing::Size(190, 20);
			this->textBoxConnectorType->TabIndex = 17;
			// 
			// textBoxCapacity
			// 
			this->textBoxCapacity->Enabled = false;
			this->textBoxCapacity->Location = System::Drawing::Point(12, 381);
			this->textBoxCapacity->Name = L"textBoxCapacity";
			this->textBoxCapacity->Size = System::Drawing::Size(190, 20);
			this->textBoxCapacity->TabIndex = 19;
			// 
			// textBoxCapacityError
			// 
			this->textBoxCapacityError->Enabled = false;
			this->textBoxCapacityError->Location = System::Drawing::Point(12, 420);
			this->textBoxCapacityError->Name = L"textBoxCapacityError";
			this->textBoxCapacityError->Size = System::Drawing::Size(190, 20);
			this->textBoxCapacityError->TabIndex = 21;
			// 
			// textBoxElectricalDamper
			// 
			this->textBoxElectricalDamper->Enabled = false;
			this->textBoxElectricalDamper->Location = System::Drawing::Point(12, 460);
			this->textBoxElectricalDamper->Name = L"textBoxElectricalDamper";
			this->textBoxElectricalDamper->Size = System::Drawing::Size(190, 20);
			this->textBoxElectricalDamper->TabIndex = 23;
			// 
			// textBoxImpulseAmplitude
			// 
			this->textBoxImpulseAmplitude->Enabled = false;
			this->textBoxImpulseAmplitude->Location = System::Drawing::Point(12, 538);
			this->textBoxImpulseAmplitude->Name = L"textBoxImpulseAmplitude";
			this->textBoxImpulseAmplitude->Size = System::Drawing::Size(190, 20);
			this->textBoxImpulseAmplitude->TabIndex = 27;
			// 
			// comboBoxAmplitudeRange
			// 
			this->comboBoxAmplitudeRange->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxAmplitudeRange->Enabled = false;
			this->comboBoxAmplitudeRange->FormattingEnabled = true;
			this->comboBoxAmplitudeRange->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"10mV", L"20mV", L"1V" });
			this->comboBoxAmplitudeRange->Location = System::Drawing::Point(12, 577);
			this->comboBoxAmplitudeRange->Name = L"comboBoxAmplitudeRange";
			this->comboBoxAmplitudeRange->Size = System::Drawing::Size(190, 21);
			this->comboBoxAmplitudeRange->TabIndex = 29;
			// 
			// textBoxName
			// 
			this->textBoxName->Location = System::Drawing::Point(12, 66);
			this->textBoxName->Name = L"textBoxName";
			this->textBoxName->Size = System::Drawing::Size(190, 20);
			this->textBoxName->TabIndex = 3;
			// 
			// errorProviderType
			// 
			this->errorProviderType->BlinkStyle = System::Windows::Forms::ErrorBlinkStyle::NeverBlink;
			this->errorProviderType->ContainerControl = this;
			// 
			// errorProviderName
			// 
			this->errorProviderName->BlinkStyle = System::Windows::Forms::ErrorBlinkStyle::NeverBlink;
			this->errorProviderName->ContainerControl = this;
			// 
			// errorProviderLength
			// 
			this->errorProviderLength->BlinkStyle = System::Windows::Forms::ErrorBlinkStyle::NeverBlink;
			this->errorProviderLength->ContainerControl = this;
			// 
			// errorProviderWidth
			// 
			this->errorProviderWidth->BlinkStyle = System::Windows::Forms::ErrorBlinkStyle::NeverBlink;
			this->errorProviderWidth->ContainerControl = this;
			// 
			// errorProviderHeight
			// 
			this->errorProviderHeight->BlinkStyle = System::Windows::Forms::ErrorBlinkStyle::NeverBlink;
			this->errorProviderHeight->ContainerControl = this;
			// 
			// errorProviderPort
			// 
			this->errorProviderPort->BlinkStyle = System::Windows::Forms::ErrorBlinkStyle::NeverBlink;
			this->errorProviderPort->ContainerControl = this;
			// 
			// errorProvider7
			// 
			this->errorProvider7->BlinkStyle = System::Windows::Forms::ErrorBlinkStyle::NeverBlink;
			this->errorProvider7->ContainerControl = this;
			// 
			// errorProvider8
			// 
			this->errorProvider8->ContainerControl = this;
			// 
			// errorProvider9
			// 
			this->errorProvider9->ContainerControl = this;
			// 
			// errorProvider10
			// 
			this->errorProvider10->ContainerControl = this;
			// 
			// errorProvider11
			// 
			this->errorProvider11->ContainerControl = this;
			// 
			// comboBoxMatchingInductance
			// 
			this->comboBoxMatchingInductance->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxMatchingInductance->Enabled = false;
			this->comboBoxMatchingInductance->FormattingEnabled = true;
			this->comboBoxMatchingInductance->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Нет", L"Есть" });
			this->comboBoxMatchingInductance->Location = System::Drawing::Point(12, 499);
			this->comboBoxMatchingInductance->Name = L"comboBoxMatchingInductance";
			this->comboBoxMatchingInductance->Size = System::Drawing::Size(190, 21);
			this->comboBoxMatchingInductance->TabIndex = 32;
			// 
			// TransducerTypeForm
			// 
			this->AcceptButton = this->buttonSave;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(214, 641);
			this->Controls->Add(this->comboBoxMatchingInductance);
			this->Controls->Add(this->textBoxName);
			this->Controls->Add(this->comboBoxAmplitudeRange);
			this->Controls->Add(this->textBoxImpulseAmplitude);
			this->Controls->Add(this->textBoxElectricalDamper);
			this->Controls->Add(this->textBoxCapacityError);
			this->Controls->Add(this->textBoxCapacity);
			this->Controls->Add(this->textBoxConnectorType);
			this->Controls->Add(this->textBoxMass);
			this->Controls->Add(this->textBoxDimentionPiezo);
			this->Controls->Add(this->textBoxPort);
			this->Controls->Add(this->textBoxHeight);
			this->Controls->Add(this->textBoxWidth);
			this->Controls->Add(this->comboBoxType);
			this->Controls->Add(this->labelAmplitudeRange);
			this->Controls->Add(this->labelImpulseAmplitude);
			this->Controls->Add(this->labelMatchingInductance);
			this->Controls->Add(this->labeleEectricalDamper);
			this->Controls->Add(this->labelCapacityError);
			this->Controls->Add(this->labelCapacity);
			this->Controls->Add(this->labelConnectorType);
			this->Controls->Add(this->labelMass);
			this->Controls->Add(this->labelDimentionPiezo);
			this->Controls->Add(this->labelPort);
			this->Controls->Add(this->labelHeight);
			this->Controls->Add(this->labelWidth);
			this->Controls->Add(this->labelLength);
			this->Controls->Add(this->labelName);
			this->Controls->Add(this->labelType);
			this->Controls->Add(this->textBoxLength);
			this->Controls->Add(this->buttonSave);
			this->Name = L"TransducerTypeForm";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->Text = L"Характеристики преобразователя";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProviderType))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProviderName))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProviderLength))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProviderWidth))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProviderHeight))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProviderPort))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider9))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider11))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		System::Void buttonSave_Click(System::Object^  sender, System::EventArgs^  e)
		{
			if (bIsFormValid())
			{
				// TODO: Добавить сохранение всех параметров
				this->st->type = (TransducerType)this->comboBoxType->TabIndex;
				this->st->name = marshal_as<std::string>(this->textBoxName->Text);
				this->st->dimensionsX = float::Parse(this->textBoxLength->Text);
				this->st->dimensionsY = float::Parse(this->textBoxWidth->Text);
				this->st->dimensionsZ = float::Parse(this->textBoxHeight->Text);
				this->st->dimension_port = float::Parse(this->textBoxPort->Text);

				this->DialogResult = System::Windows::Forms::DialogResult::OK;
				this->Close();
			}
		}

	private:
		bool bIsFormValid()
		{
			// TODO: Добавить проверку всех параметров
			bool bHasErrors = false;
			if (bIsTextBoxEmpty(this->textBoxName, this->errorProviderName)) bHasErrors = true;
			if (bIsTextBoxEmpty(this->textBoxLength, this->errorProviderLength)) bHasErrors = true;
			if (bIsTextBoxEmpty(this->textBoxWidth, this->errorProviderWidth)) bHasErrors = true;
			if (bIsTextBoxEmpty(this->textBoxHeight, this->errorProviderPort)) bHasErrors = true;
			if (bIsTextBoxEmpty(this->textBoxPort, this->errorProviderPort)) bHasErrors = true;
			return !bHasErrors;
		}

	private:
		// Проверка на ввод значеня float
		System::Void textBoxLength_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
		{
			CheckFloatInKeyPress(e);
		}

		System::Void textBoxWidth_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
		{
			CheckFloatInKeyPress(e);
		}

		System::Void textBoxHeight_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
		{
			CheckFloatInKeyPress(e);
		}

		System::Void textBoxPort_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
		{
			CheckFloatInKeyPress(e);
		}

	};
}

