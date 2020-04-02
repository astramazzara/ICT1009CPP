
#include "Crawler.h"
#include "twitter.h"

#include <string>
#include <msclr\marshal_cppstd.h>
#include <filesystem>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <ctime>

#include <algorithm>
#include <map>
#include <filesystem>





namespace fs = std::filesystem;
using namespace System;
using namespace std;



using namespace msclr::interop;
//to error LNK2019: unresolved external symbols
//due to twitcurl lib developed in older programming definitions
//https://stackoverflow.com/questions/30412951/unresolved-external-symbol-imp-fprintf-and-imp-iob-func-sdl2
#define stdin  (__acrt_iob_func(0))
#define stdout (__acrt_iob_func(1))
#define stderr (__acrt_iob_func(2))

FILE _iob[] = { *stdin, *stdout, *stderr };

extern "C" FILE * __cdecl __iob_func(void) { return _iob; }
extern "C" void __imp__set_output_format(void) {};

namespace CPPProject1009Gui
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for GUI
	/// </summary>
	public ref class GUI : public System::Windows::Forms::Form
	{
	public:
		GUI(void)
		{
			InitializeComponent();


			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^ tabControl1;
	protected:
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::Button^ crawlBtn;

	private: System::Windows::Forms::TabPage^ tabPage3;



	private: System::Windows::Forms::TextBox^ recordTb;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ keywordTb;


	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;




	private: System::Windows::Forms::Button^ displayBtn;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;





	private: System::Windows::Forms::Button^ button1;




	private: System::Windows::Forms::GroupBox^ groupBox1;



	private: System::Windows::Forms::TextBox^ searchTb;
	private: System::Windows::Forms::Button^ searchBtn;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ clearBtn;

	private: System::Windows::Forms::TextBox^ searchTb2;
	private: System::Windows::Forms::Button^ searchBtn2;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ displayBtn2;


	private: System::Windows::Forms::RichTextBox^ richTextBox2;
	private: System::Windows::Forms::Button^ clearBtn2;
	private: System::Windows::Forms::Button^ toptenBtn;


	private: System::Windows::Forms::Button^ btnSort;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::GroupBox^ groupBox5;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column6;
	private: System::Windows::Forms::Button^ toptenBtn2;



















	private: System::ComponentModel::IContainer^ components;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->crawlBtn = (gcnew System::Windows::Forms::Button());
			this->recordTb = (gcnew System::Windows::Forms::TextBox());
			this->keywordTb = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->btnSort = (gcnew System::Windows::Forms::Button());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->searchBtn = (gcnew System::Windows::Forms::Button());
			this->searchTb = (gcnew System::Windows::Forms::TextBox());
			this->toptenBtn = (gcnew System::Windows::Forms::Button());
			this->clearBtn = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->displayBtn = (gcnew System::Windows::Forms::Button());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->searchTb2 = (gcnew System::Windows::Forms::TextBox());
			this->searchBtn2 = (gcnew System::Windows::Forms::Button());
			this->clearBtn2 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->displayBtn2 = (gcnew System::Windows::Forms::Button());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->toptenBtn2 = (gcnew System::Windows::Forms::Button());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox4->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->tabPage3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->groupBox5->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Location = System::Drawing::Point(-1, -1);
			this->tabControl1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1475, 794);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->BackColor = System::Drawing::Color::LavenderBlush;
			this->tabPage1->Controls->Add(this->groupBox1);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPage1->Size = System::Drawing::Size(1467, 765);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Crawler";
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::White;
			this->groupBox1->Controls->Add(this->crawlBtn);
			this->groupBox1->Controls->Add(this->recordTb);
			this->groupBox1->Controls->Add(this->keywordTb);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->groupBox1->Location = System::Drawing::Point(175, 94);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox1->Size = System::Drawing::Size(1080, 532);
			this->groupBox1->TabIndex = 10;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Twitter Crawl";
			// 
			// crawlBtn
			// 
			this->crawlBtn->Location = System::Drawing::Point(504, 282);
			this->crawlBtn->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->crawlBtn->Name = L"crawlBtn";
			this->crawlBtn->Size = System::Drawing::Size(101, 41);
			this->crawlBtn->TabIndex = 0;
			this->crawlBtn->Text = L"Crawl ";
			this->crawlBtn->UseVisualStyleBackColor = true;
			this->crawlBtn->Click += gcnew System::EventHandler(this, &GUI::crawlBtn_Click);
			// 
			// recordTb
			// 
			this->recordTb->Location = System::Drawing::Point(472, 223);
			this->recordTb->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->recordTb->Name = L"recordTb";
			this->recordTb->Size = System::Drawing::Size(132, 31);
			this->recordTb->TabIndex = 0;
			// 
			// keywordTb
			// 
			this->keywordTb->Location = System::Drawing::Point(472, 171);
			this->keywordTb->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->keywordTb->Name = L"keywordTb";
			this->keywordTb->Size = System::Drawing::Size(132, 31);
			this->keywordTb->TabIndex = 9;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(292, 226);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(155, 25);
			this->label2->TabIndex = 8;
			this->label2->Text = L"No. of Records";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(363, 175);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(95, 25);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Keyword";
			// 
			// tabPage2
			// 
			this->tabPage2->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->tabPage2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->tabPage2->Controls->Add(this->dataGridView1);
			this->tabPage2->Controls->Add(this->groupBox4);
			this->tabPage2->Controls->Add(this->groupBox3);
			this->tabPage2->Controls->Add(this->toptenBtn);
			this->tabPage2->Controls->Add(this->clearBtn);
			this->tabPage2->Controls->Add(this->label4);
			this->tabPage2->Controls->Add(this->button1);
			this->tabPage2->Controls->Add(this->richTextBox1);
			this->tabPage2->Controls->Add(this->displayBtn);
			this->tabPage2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPage2->Size = System::Drawing::Size(1467, 765);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Twitter";
			// 
			// dataGridView1
			// 
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->Column1,
					this->Column2, this->Column3
			});
			this->dataGridView1->Location = System::Drawing::Point(0, 38);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersWidth = 53;
			this->dataGridView1->Size = System::Drawing::Size(1180, 720);
			this->dataGridView1->TabIndex = 24;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"User ID";
			this->Column1->MinimumWidth = 7;
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			this->Column1->Width = 99;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Date Time";
			this->Column2->MinimumWidth = 7;
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			this->Column2->Width = 119;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"User Post";
			this->Column3->MinimumWidth = 7;
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			this->Column3->Width = 116;
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->comboBox2);
			this->groupBox4->Controls->Add(this->btnSort);
			this->groupBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox4->Location = System::Drawing::Point(1188, 38);
			this->groupBox4->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox4->Size = System::Drawing::Size(267, 128);
			this->groupBox4->TabIndex = 23;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Sort By";
			// 
			// comboBox2
			// 
			this->comboBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"Sort ascending order by username", L"Sort descending order by username",
					L"Sort ascending order by post", L"Sort descending order by post"
			});
			this->comboBox2->Location = System::Drawing::Point(3, 31);
			this->comboBox2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(255, 25);
			this->comboBox2->TabIndex = 20;
			// 
			// btnSort
			// 
			this->btnSort->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSort->Location = System::Drawing::Point(88, 59);
			this->btnSort->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnSort->Name = L"btnSort";
			this->btnSort->Size = System::Drawing::Size(100, 28);
			this->btnSort->TabIndex = 18;
			this->btnSort->Text = L"Sort";
			this->btnSort->UseVisualStyleBackColor = true;
			this->btnSort->Click += gcnew System::EventHandler(this, &GUI::btnSort_Click);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->searchBtn);
			this->groupBox3->Controls->Add(this->searchTb);
			this->groupBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox3->Location = System::Drawing::Point(1188, 174);
			this->groupBox3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox3->Size = System::Drawing::Size(261, 100);
			this->groupBox3->TabIndex = 22;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Search by Keyword";
			// 
			// searchBtn
			// 
			this->searchBtn->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->searchBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->searchBtn->Location = System::Drawing::Point(88, 60);
			this->searchBtn->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->searchBtn->Name = L"searchBtn";
			this->searchBtn->Size = System::Drawing::Size(100, 30);
			this->searchBtn->TabIndex = 8;
			this->searchBtn->Text = L"Search";
			this->searchBtn->UseVisualStyleBackColor = true;
			this->searchBtn->Click += gcnew System::EventHandler(this, &GUI::searchBtn_Click);
			// 
			// searchTb
			// 
			this->searchTb->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->searchTb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->searchTb->Location = System::Drawing::Point(8, 26);
			this->searchTb->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->searchTb->Name = L"searchTb";
			this->searchTb->Size = System::Drawing::Size(245, 27);
			this->searchTb->TabIndex = 9;
			// 
			// toptenBtn
			// 
			this->toptenBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->toptenBtn->Location = System::Drawing::Point(1221, 436);
			this->toptenBtn->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->toptenBtn->Name = L"toptenBtn";
			this->toptenBtn->Size = System::Drawing::Size(208, 41);
			this->toptenBtn->TabIndex = 15;
			this->toptenBtn->Text = L"Top Ten words";
			this->toptenBtn->UseVisualStyleBackColor = true;
			this->toptenBtn->Click += gcnew System::EventHandler(this, &GUI::toptenBtn_Click);
			// 
			// clearBtn
			// 
			this->clearBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->clearBtn->Location = System::Drawing::Point(1221, 388);
			this->clearBtn->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->clearBtn->Name = L"clearBtn";
			this->clearBtn->Size = System::Drawing::Size(208, 41);
			this->clearBtn->TabIndex = 12;
			this->clearBtn->Text = L"Clear Display";
			this->clearBtn->UseVisualStyleBackColor = true;
			this->clearBtn->Click += gcnew System::EventHandler(this, &GUI::clearBtn_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::LightGray;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(4, 4);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(301, 32);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Twitter Crawl Display";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(1221, 292);
			this->button1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(208, 41);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Import CSV";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &GUI::button1_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox1->Location = System::Drawing::Point(1191, 484);
			this->richTextBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(257, 260);
			this->richTextBox1->TabIndex = 6;
			this->richTextBox1->Text = L"";
			// 
			// displayBtn
			// 
			this->displayBtn->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->displayBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->displayBtn->Location = System::Drawing::Point(1221, 340);
			this->displayBtn->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->displayBtn->Name = L"displayBtn";
			this->displayBtn->Size = System::Drawing::Size(208, 41);
			this->displayBtn->TabIndex = 5;
			this->displayBtn->Text = L"Display CSV";
			this->displayBtn->UseVisualStyleBackColor = true;
			this->displayBtn->Click += gcnew System::EventHandler(this, &GUI::displayBtn_Click);
			// 
			// tabPage3
			// 
			this->tabPage3->BackColor = System::Drawing::Color::IndianRed;
			this->tabPage3->Controls->Add(this->toptenBtn2);
			this->tabPage3->Controls->Add(this->dataGridView2);
			this->tabPage3->Controls->Add(this->groupBox5);
			this->tabPage3->Controls->Add(this->clearBtn2);
			this->tabPage3->Controls->Add(this->button2);
			this->tabPage3->Controls->Add(this->displayBtn2);
			this->tabPage3->Controls->Add(this->richTextBox2);
			this->tabPage3->Controls->Add(this->label6);
			this->tabPage3->Location = System::Drawing::Point(4, 25);
			this->tabPage3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->tabPage3->Size = System::Drawing::Size(1467, 765);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"CNA";
			// 
			// dataGridView2
			// 
			this->dataGridView2->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGridView2->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->Column4,
					this->Column5, this->Column6
			});
			this->dataGridView2->Location = System::Drawing::Point(12, 38);
			this->dataGridView2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->ReadOnly = true;
			this->dataGridView2->RowHeadersWidth = 53;
			this->dataGridView2->Size = System::Drawing::Size(1115, 716);
			this->dataGridView2->TabIndex = 23;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Source";
			this->Column4->MinimumWidth = 7;
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			this->Column4->Width = 83;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Date";
			this->Column5->MinimumWidth = 7;
			this->Column5->Name = L"Column5";
			this->Column5->ReadOnly = true;
			this->Column5->Width = 69;
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"HeadLine";
			this->Column6->MinimumWidth = 7;
			this->Column6->Name = L"Column6";
			this->Column6->ReadOnly = true;
			this->Column6->Width = 99;
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->searchTb2);
			this->groupBox5->Controls->Add(this->searchBtn2);
			this->groupBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox5->Location = System::Drawing::Point(1135, 38);
			this->groupBox5->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox5->Size = System::Drawing::Size(299, 132);
			this->groupBox5->TabIndex = 22;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Search by Keyword";
			// 
			// searchTb2
			// 
			this->searchTb2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->searchTb2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->searchTb2->Location = System::Drawing::Point(23, 26);
			this->searchTb2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->searchTb2->Name = L"searchTb2";
			this->searchTb2->Size = System::Drawing::Size(254, 24);
			this->searchTb2->TabIndex = 17;
			// 
			// searchBtn2
			// 
			this->searchBtn2->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->searchBtn2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->searchBtn2->Location = System::Drawing::Point(91, 69);
			this->searchBtn2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->searchBtn2->Name = L"searchBtn2";
			this->searchBtn2->Size = System::Drawing::Size(123, 44);
			this->searchBtn2->TabIndex = 16;
			this->searchBtn2->Text = L"Search";
			this->searchBtn2->UseVisualStyleBackColor = true;
			this->searchBtn2->Click += gcnew System::EventHandler(this, &GUI::searchBtn2_Click);
			// 
			// clearBtn2
			// 
			this->clearBtn2->Location = System::Drawing::Point(1191, 287);
			this->clearBtn2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->clearBtn2->Name = L"clearBtn2";
			this->clearBtn2->Size = System::Drawing::Size(219, 39);
			this->clearBtn2->TabIndex = 21;
			this->clearBtn2->Text = L"Clear Display";
			this->clearBtn2->UseVisualStyleBackColor = true;
			this->clearBtn2->Click += gcnew System::EventHandler(this, &GUI::clearBtn2_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(1191, 193);
			this->button2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(219, 41);
			this->button2->TabIndex = 20;
			this->button2->Text = L"Import CSV";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &GUI::button2_Click);
			// 
			// displayBtn2
			// 
			this->displayBtn2->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->displayBtn2->Location = System::Drawing::Point(1191, 241);
			this->displayBtn2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->displayBtn2->Name = L"displayBtn2";
			this->displayBtn2->Size = System::Drawing::Size(219, 38);
			this->displayBtn2->TabIndex = 19;
			this->displayBtn2->Text = L"Display CSV";
			this->displayBtn2->UseVisualStyleBackColor = true;
			this->displayBtn2->Click += gcnew System::EventHandler(this, &GUI::displayBtn2_Click);
			// 
			// richTextBox2
			// 
			this->richTextBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox2->Location = System::Drawing::Point(1172, 468);
			this->richTextBox2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->ReadOnly = true;
			this->richTextBox2->Size = System::Drawing::Size(260, 249);
			this->richTextBox2->TabIndex = 18;
			this->richTextBox2->Text = L"";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::LightGray;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(4, 4);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(271, 32);
			this->label6->TabIndex = 0;
			this->label6->Text = L"CNA Crawl Display";
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->ImageScalingSize = System::Drawing::Size(21, 21);
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// toptenBtn2
			// 
			this->toptenBtn2->Location = System::Drawing::Point(1191, 334);
			this->toptenBtn2->Margin = System::Windows::Forms::Padding(4);
			this->toptenBtn2->Name = L"toptenBtn2";
			this->toptenBtn2->Size = System::Drawing::Size(219, 39);
			this->toptenBtn2->TabIndex = 24;
			this->toptenBtn2->Text = L"Top Ten words";
			this->toptenBtn2->UseVisualStyleBackColor = true;
			this->toptenBtn2->Click += gcnew System::EventHandler(this, &GUI::toptenBtn2_Click);
			// 
			// GUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1475, 796);
			this->Controls->Add(this->tabControl1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"GUI";
			this->Text = L"Crawler GUI";
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox4->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		//Global Var
		bool plsimporttweet = 0;//check for impor csv twiiter
		bool plsimportcna = 0;//check for import csv cna

		/*---------------BUTTONS for Crawling---------------------------------------*/
	private: System::Void crawlBtn_Click(System::Object^ sender, System::EventArgs^ e)
	{	//Keywords
		System::String^ strInput1;
		//No. of Records
		System::String^ intInput2;
		int input2;

		if (keywordTb->Text == "")
		{
			MessageBox::Show("Please input Keyword to crawl");
		}
		else if (recordTb->Text == "")
		{
			MessageBox::Show("Please input Record to crawl");
		}
		else {
			//Get Keyword from TexBox
			strInput1 = keywordTb->Text;
			std::string input1 = marshal_as<std::string>(strInput1);

			//Get Records from TexBox
			intInput2 = recordTb->Text;
			input2 = Convert::ToInt32(intInput2);


			Crawler twitterCrawler;
			twitterCrawler.crawlerTwitter(input1, input2);
			twitterCrawler.crawlerJsonToFile();

			MessageBox::Show("Successfully Crawled and Saved to File");
		}
	}
		/*--------------------END  OF BUTTONS for Crawling--------------------------*/

	/*-----------------------------------------------Twitter Buttons-------------------------------------------*/


		/*--------------------BUTTONS for Importing CSV File------------------------*/
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;

		openFileDialog1->InitialDirectory = "C:\\Users\\lim_j\\Documents\\GitHub\\ICT1009CPP\\ICT1009CPP\\";
		openFileDialog1->RestoreDirectory = true;

		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			System::String^ filepath = System::IO::Path::GetFileName(openFileDialog1->FileName);
			std::string filename = marshal_as<std::string>(filepath);


			//fs::path filepath = fs::u8path(fpath);
			//std::string path_string = filepath.u8string();

			//String^ str2 = gcnew String(path_string.c_str());
			
			twitterData tweet;
			tweet.set_csvfilepath(filename);// use stadard string
			readData(filename);
			MessageBox::Show("Successfully Load "+filepath, "FilePath:");//use system strig
			plsimporttweet = 1;


		}
	}
		/*---------------------END  OF BUTTONS for Importing CSV File---------------*/

		/*--------------------------DISPLAY CSV BUTTON------------------------------*/
	private: System::Void displayBtn_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (plsimporttweet == 0)
		{
			MessageBox::Show("Please Import CSV" ,"Error: ");
		}
		else
		{
		//richTextBox1->Text = marshal_as<String^>(display.getDate());
			for (int j = 0; j < twitter.size(); ++j)
			{
				//std::string date = marshal_as<std::string>(twitter[i].getDate());
				//textBox1->Text="Time Date";

				//std::string test1 = std::to_string(j);
				//String^ str2 = gcnew String(test1.c_str());
				//MessageBox::Show(str2);
				//richTextBox1->Text += "Date Time: " + marshal_as<String^>(twitter[j].getDate()) + "\r"
					//+ "User ID: " + marshal_as<String^>(twitter[j].getUserId()) + "\r"
					//+ "User Tweet: " + marshal_as<String^>(twitter[j].getPost()) + "\r" + "------------------------------------------------------------------------------------------------------------------------------------------------------------------" + "\r";
				
				dataGridView1->Rows->Add(marshal_as<String^>(twitter[j].getUserId()), marshal_as<String^>(twitter[j].getDate()), marshal_as<String^>(twitter[j].getPost()));
			}
		}
	} /*-----------------------------END OF DISPLAY CSV BUTTON------------------------------------*/
		/*---------------------END  OF DISPLAY CSV BUTTO----------------------------*/

	/*Twitter Search keyword BUTTON*/
	private: System::Void searchBtn_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		System::String^ search;//user input 
		if (plsimporttweet == 0)
		{
			MessageBox::Show("Please Import CSV", "Error: ");
		}

		else if (searchTb->Text == "")
		{
			MessageBox::Show("Please input Keyword to search!", "Error:");
		}
		
		else
		{
			search = searchTb->Text;//Get Keyword from TexBox

			std::string searchword = marshal_as<std::string>(search);//change to stadard string

			//vector<twitterData> filtered;
			//std::vector<twitterData> filtered = searchKeyword(searchword, filtered, twitter);//function
			std::vector<twitterData> filtered; 
			filtered = searchKeyword<twitterData>(searchword, filtered, twitter);

			if (filtered.empty())
			{
				MessageBox::Show("No Records "+ search+" Found!", "Error:");
			}
			else{
			for (int j = 0; j < filtered.size(); ++j) 
			{
				
				//richTextBox1->Text +="Date Time: " + marshal_as<String^>(filtered[j].getDate()) + "\r"
									//+ "User ID: " + marshal_as<String^>(filtered[j].getUserId()) + "\r"
									//+ "User Tweet: " + marshal_as<String^>(filtered[j].getPost()) + "\r" + "------------------------------------------------------------------------------------------------------------------------------------------------------------------"+"\r";

				dataGridView1->Rows->Add(marshal_as<String^>(filtered[j].getUserId()), marshal_as<String^>(filtered[j].getDate()), marshal_as<String^>(filtered[j].getPost()));
			}
	
			MessageBox::Show("Keyword Record "+search+" found!", "Keyword Found");
			}
		}
	}
	/*End of Twitter Search keyword BUTTON*/
	
	/*Start of clear BUTTON*/
	private: System::Void clearBtn_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		richTextBox1->Text = "";
		dataGridView1->Rows->Clear();
	}
	/*End of clear BUTTON*/
	
	/*Start of top ten BUTTON*/
	private: System::Void toptenBtn_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if (plsimporttweet == 0)
		{
			MessageBox::Show("Please Import CSV", "Error: ");
		}
		else{
			vector<pair<string, int> > wordvector;
			wordvector = top10WordTopics();
			for (int i = 0; i < wordvector.size(); ++i) 
			{
				//chart1->Series["Top Ten Words"]->
					//Points->Add( ((wordvector[i].first),wordvector[i].second));
				richTextBox1->Text += marshal_as<String^>(wordvector[i].first) + 
								" = " + marshal_as<String^>(to_string(wordvector[i].second)) + "\r";
			}
		}
	}
	/*End of top ten BUTTON*/
	
	/*Start of Sort BUTTON*/
	private: System::Void btnSort_Click(System::Object^ sender, System::EventArgs^ e) 
	{		
		
		
		if (plsimporttweet == 0)
		{
			MessageBox::Show("Please Import CSV", "Error: ");
		}
		else if (comboBox2->Text == "Sort ascending order by username")
		{
			
			// function sort userid ascending
			sort(twitter.begin(), twitter.end(), userid_asc);		
			
			
		}
		else if(comboBox2->Text == "Sort descending order by username")
		{
			
			// function sort userid descending
			
			sort(twitter.begin(), twitter.end(), userid_desc);
			
			
		}
		else if (comboBox2->Text == "Sort ascending order by post")
		{
			
			// function sort post ascending
			
			sort(twitter.begin(), twitter.end(), post_asc);
		
			
		}
		else if (comboBox2->Text == "Sort descending order by post")
		{
			
			// function sort post descending
			sort(twitter.begin(), twitter.end(), post_desc);

			
		}
		else
		{
			MessageBox::Show("Please input Keyword to sort!", "Error:");
		}
		for (int i = 0; i < twitter.size(); ++i) 
		{

			//richTextBox1->Text += "Date Time: " + marshal_as<String^>(twitter[i].getDate()) + "\r"
				//+ "User ID: " + marshal_as<String^>(twitter[i].getUserId()) + "\r"
				//+ "User Tweet: " + marshal_as<String^>(twitter[i].getPost()) + "\r" + "------------------------------------------------------------------------------------------------------------------------------------------------------------------" + "\r";
			dataGridView1->Rows->Add(marshal_as<String^>(twitter[i].getUserId()), marshal_as<String^>(twitter[i].getDate()), marshal_as<String^>(twitter[i].getPost()));

		}
		
	}
	/*End of top ten BUTTON*/
	





/*-----------------------------------------------CNA Buttons-------------------------------------------*/
	/*CNA Search by keyword*/
	private: System::Void searchBtn2_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		System::String^ search;//user input 

		if (plsimportcna == 0)
		{
			MessageBox::Show("Please Import CSV", "Error: ");
		}
		else if (searchTb2->Text == "")
		{
			MessageBox::Show("Please input Keyword to search!", "Error:");
		}

		else
		{
			search = searchTb2->Text;//Get Keyword from TexBox

			std::string searchword = marshal_as<std::string>(search);//change to stadard string
			
			//vector<CNA> filtered;
			std::vector<CNA> filtered;
			filtered = searchKeyword<CNA>(searchword, filtered, cna);//function

			if (filtered.empty())
			{
				MessageBox::Show("No Records " + search + " Found!", "Error:");
			}
			else {
				for (int j = 0; j < filtered.size(); ++j)
				{

					//richTextBox2->Text += "Date: " + marshal_as<String^>(filtered[j].getDate()) + "\r"
						//+ "Author: " + marshal_as<String^>(filtered[j].getUserId()) + "\r"
						//+ "Title: " + marshal_as<String^>(filtered[j].getPost()) + "\r" + "------------------------------------------------------------------------------------------------------------------------------------------------------------------" + "\r";
					dataGridView2->Rows->Add(marshal_as<String^>(filtered[j].getUserId()), marshal_as<String^>(filtered[j].getDate()), marshal_as<String^>(filtered[j].getPost()));

				}

				MessageBox::Show("Keyword Record " + search + " found!", "Keyword Found");
			}
		}
	}
	/*END of CNA Search by keyword*/



	/*Display CNA CSV*/
	private: System::Void displayBtn2_Click(System::Object^ sender, System::EventArgs^ e) {

	if (plsimportcna == 0)
	{
		MessageBox::Show("Please Import CSV", "Error: ");
	}
	else
	{
		
		for (int j = 0; j <cna.size(); ++j) 
		{

			//richTextBox2->Text += "Date: " + marshal_as<String^>(cna[j].getDate()) + "\r"
			//	+ "Author: " + marshal_as<String^>(cna[j].getUserId()) + "\r"
				//+ "Title: " + marshal_as<String^>(cna[j].getPost()) + "\r" + "------------------------------------------------------------------------------------------------------------------------------------------------------------------" + "\r";
			dataGridView2->Rows->Add(marshal_as<String^>(cna[j].getUserId()), marshal_as<String^>(cna[j].getDate()), marshal_as<String^>(cna[j].getPost()));


		}
	}
}
	/*END Display CNA CSV*/



	/*Loading CNA CSV*/
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		OpenFileDialog^ openFileDialog2 = gcnew OpenFileDialog;

		openFileDialog2->InitialDirectory = "C:\\Users\\lim_j\\Documents\\GitHub\\ICT1009CPP\\ICT1009CPP\\";
		openFileDialog2->RestoreDirectory = true;

		if (openFileDialog2->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			System::String^ filepath = System::IO::Path::GetFileName(openFileDialog2->FileName);
			std::string filename = marshal_as<std::string>(filepath);


			//fs::path filepath = fs::u8path(fpath);
			//std::string path_string = filepath.u8string();

			//String^ str2 = gcnew String(path_string.c_str());
			readCNAData(filename);
			//twitterData tweet;
			//tweet.set_csvfilepath(filename);// use stadard string
			MessageBox::Show("Successfully Load " + filepath, "FilePath:");//use system strig
			plsimportcna = 1;
		}
	}
	/*End of Loading CNA CSV*/
	
	/*Clear Display*/
	private: System::Void clearBtn2_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		
			richTextBox2->Text = "";
			dataGridView2->Rows->Clear();
	}
	/* End of Clear Display*/

private: System::Void toptenBtn2_Click(System::Object^ sender, System::EventArgs^ e) {


}
};
}

