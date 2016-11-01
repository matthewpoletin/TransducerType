#pragma once

#include <stdlib.h>
#include <string.h>
#include <msclr\marshal.h>
#include <msclr\marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

#include "TransducerTypeForm.h"
#include "StandartTransducer.h"
#include "StandartTransducerManager.h"

namespace PassportTable {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			stMgr = new StandartTransducerManager();
		}

	protected:
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	public:
		StandartTransducerManager* stMgr;

	private:
		System::Windows::Forms::TableLayoutPanel^  tableLayoutPanelMain;
		System::Windows::Forms::TableLayoutPanel^  tableLayoutPanelButtons;
		System::Windows::Forms::Button^  buttonSave;
		System::Windows::Forms::Button^  buttonEdit;
		System::Windows::Forms::Button^  buttonDelete;
		System::Windows::Forms::Button^  buttonAdd;
		System::Windows::Forms::ListBox^  listBoxTransducers;

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->tableLayoutPanelMain = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanelButtons = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->buttonSave = (gcnew System::Windows::Forms::Button());
			this->buttonDelete = (gcnew System::Windows::Forms::Button());
			this->buttonEdit = (gcnew System::Windows::Forms::Button());
			this->buttonAdd = (gcnew System::Windows::Forms::Button());
			this->listBoxTransducers = (gcnew System::Windows::Forms::ListBox());
			this->tableLayoutPanelMain->SuspendLayout();
			this->tableLayoutPanelButtons->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanelMain
			// 
			this->tableLayoutPanelMain->ColumnCount = 2;
			this->tableLayoutPanelMain->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				72.16982F)));
			this->tableLayoutPanelMain->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				27.83019F)));
			this->tableLayoutPanelMain->Controls->Add(this->tableLayoutPanelButtons, 1, 0);
			this->tableLayoutPanelMain->Controls->Add(this->listBoxTransducers, 0, 0);
			this->tableLayoutPanelMain->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanelMain->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanelMain->Name = L"tableLayoutPanelMain";
			this->tableLayoutPanelMain->RowCount = 1;
			this->tableLayoutPanelMain->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanelMain->Size = System::Drawing::Size(442, 199);
			this->tableLayoutPanelMain->TabIndex = 6;
			// 
			// tableLayoutPanelButtons
			// 
			this->tableLayoutPanelButtons->ColumnCount = 1;
			this->tableLayoutPanelButtons->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanelButtons->Controls->Add(this->buttonSave, 0, 3);
			this->tableLayoutPanelButtons->Controls->Add(this->buttonDelete, 0, 2);
			this->tableLayoutPanelButtons->Controls->Add(this->buttonEdit, 0, 1);
			this->tableLayoutPanelButtons->Controls->Add(this->buttonAdd, 0, 0);
			this->tableLayoutPanelButtons->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanelButtons->Location = System::Drawing::Point(321, 3);
			this->tableLayoutPanelButtons->Name = L"tableLayoutPanelButtons";
			this->tableLayoutPanelButtons->RowCount = 4;
			this->tableLayoutPanelButtons->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanelButtons->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanelButtons->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanelButtons->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanelButtons->Size = System::Drawing::Size(118, 193);
			this->tableLayoutPanelButtons->TabIndex = 0;
			// 
			// buttonSave
			// 
			this->buttonSave->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->buttonSave->Location = System::Drawing::Point(21, 156);
			this->buttonSave->Name = L"buttonSave";
			this->buttonSave->Size = System::Drawing::Size(75, 25);
			this->buttonSave->TabIndex = 10;
			this->buttonSave->Text = L"Сохранить";
			this->buttonSave->UseVisualStyleBackColor = true;
			this->buttonSave->Click += gcnew System::EventHandler(this, &MainForm::buttonSave_Click);
			// 
			// buttonDelete
			// 
			this->buttonDelete->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->buttonDelete->Enabled = false;
			this->buttonDelete->Location = System::Drawing::Point(21, 107);
			this->buttonDelete->Name = L"buttonDelete";
			this->buttonDelete->Size = System::Drawing::Size(75, 25);
			this->buttonDelete->TabIndex = 9;
			this->buttonDelete->Text = L"Удалить";
			this->buttonDelete->UseVisualStyleBackColor = true;
			this->buttonDelete->Click += gcnew System::EventHandler(this, &MainForm::buttonDelete_Click);
			// 
			// buttonEdit
			// 
			this->buttonEdit->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->buttonEdit->Enabled = false;
			this->buttonEdit->Location = System::Drawing::Point(21, 59);
			this->buttonEdit->Name = L"buttonEdit";
			this->buttonEdit->Size = System::Drawing::Size(75, 25);
			this->buttonEdit->TabIndex = 7;
			this->buttonEdit->Text = L"Настройки";
			this->buttonEdit->UseVisualStyleBackColor = true;
			this->buttonEdit->Click += gcnew System::EventHandler(this, &MainForm::buttonEdit_Click);
			// 
			// buttonAdd
			// 
			this->buttonAdd->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->buttonAdd->Location = System::Drawing::Point(21, 11);
			this->buttonAdd->Name = L"buttonAdd";
			this->buttonAdd->Size = System::Drawing::Size(75, 25);
			this->buttonAdd->TabIndex = 8;
			this->buttonAdd->Text = L"Новый";
			this->buttonAdd->UseVisualStyleBackColor = true;
			this->buttonAdd->Click += gcnew System::EventHandler(this, &MainForm::buttonAdd_Click);
			// 
			// listBoxTransducers
			// 
			this->listBoxTransducers->Dock = System::Windows::Forms::DockStyle::Fill;
			this->listBoxTransducers->FormattingEnabled = true;
			this->listBoxTransducers->Location = System::Drawing::Point(3, 3);
			this->listBoxTransducers->Name = L"listBoxTransducers";
			this->listBoxTransducers->Size = System::Drawing::Size(312, 193);
			this->listBoxTransducers->Sorted = true;
			this->listBoxTransducers->TabIndex = 1;
			this->listBoxTransducers->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::listBoxTransducers_SelectedIndexChanged);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(442, 199);
			this->Controls->Add(this->tableLayoutPanelMain);
			this->Name = L"MainForm";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->Text = L"Параметры преобразователей";
			this->tableLayoutPanelMain->ResumeLayout(false);
			this->tableLayoutPanelButtons->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

	private:
		// нажатие кнопки создания нового
		System::Void buttonAdd_Click(System::Object^  sender, System::EventArgs^  e)
		{
			TransducerTypeForm^ transType = gcnew TransducerTypeForm();
			StandartTransducer* st = new StandartTransducer();
			transType->Init(st);
			System::Windows::Forms::DialogResult dr = transType->ShowDialog();
			if (dr == System::Windows::Forms::DialogResult::OK)
			{
				// генерация preview
				std::string preview = st->name;

				//StandartTransducer* temp = stMgr->Get(preview);
				// TODO: Добавить подсчёт числа участий и поиск наибольшего
				//if (temp != nullptr)	// preview exists
				//{
				//	preview += " (1)";
				//}
				
				stMgr->Insert(preview, st);
				this->listBoxTransducers->Items->Add(marshal_as<String^>(preview));
				//this->UpdateListBox();
			}
		}

		// нажатие кнопки редактирования
		System::Void buttonEdit_Click(System::Object^  sender, System::EventArgs^  e)
		{
			if (this->listBoxTransducers->SelectedIndex < 0)
			{
				std::cerr << "listbox item is not selected" << std::endl;
			}
			else
			{
				std::string oldPreview = marshal_as<std::string>(this->listBoxTransducers->SelectedItem->ToString());
				StandartTransducer* st = stMgr->Get(oldPreview);
				if (st == nullptr)
				{
					std::cerr << "Selected transducer not found" << std::endl;
				}
				else
				{
					TransducerTypeForm^ transType = gcnew TransducerTypeForm();
					{
						transType->Init(st);
						System::Windows::Forms::DialogResult dr = transType->ShowDialog();
						if (dr == System::Windows::Forms::DialogResult::OK)
						{
							std::string newPreview = st->name;
							this->stMgr->UpdatePreview(oldPreview, newPreview);
							this->listBoxTransducers->BeginUpdate();
							this->listBoxTransducers->Items->Remove(this->listBoxTransducers->SelectedItems[0]);
							this->listBoxTransducers->Items->Add(marshal_as<String^>(newPreview));
							this->listBoxTransducers->EndUpdate();
							//UpdateListBoxTransducers();
						}
					}
				}
			}
		}

		// нажатие кнопки удаления
		System::Void buttonDelete_Click(System::Object^  sender, System::EventArgs^  e)
		{
			std::string preview = marshal_as<std::string>(this->listBoxTransducers->SelectedItem->ToString());
			stMgr->Remove(preview);
			if (this->listBoxTransducers->Items->Count > 0)
				this->listBoxTransducers->Items->Remove(this->listBoxTransducers->SelectedItem);
		}

		// нажатие кнопки сохранения 
		System::Void buttonSave_Click(System::Object^  sender, System::EventArgs^  e)
		{
			stMgr->Save("");	// TODO: настроить сохранение в файл
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close();
		}

	private:
		// обновление доступа к кнопкам удаления и редактирования
		System::Void listBoxTransducers_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
		{
			if (this->listBoxTransducers->SelectedIndex >= 0)
			{
				this->buttonEdit->Enabled = true;
				this->buttonDelete->Enabled = true;
			}
			else
			{
				this->buttonEdit->Enabled = false;
				this->buttonDelete->Enabled = false;
			}
		}

	private:
		// Обновление данных listBoxTransducers(загрузка данных)
		void UpdateListBoxTransducers()
		{
			return;
		}

	};
}
