
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
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->searchTb2 = (gcnew System::Windows::Forms::TextBox());
			this->searchBtn2 = (gcnew System::Windows::Forms::Button());
			this->clearBtn2 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->displayBtn2 = (gcnew System::Windows::Forms::Button());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Location = System::Drawing::Point(-1, -1);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(941, 555);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->BackColor = System::Drawing::Color::LavenderBlush;
			this->tabPage1->Controls->Add(this->groupBox1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(933, 529);
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
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->groupBox1->Location = System::Drawing::Point(164, 89);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(619, 335);
			this->groupBox1->TabIndex = 10;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Twitter Crawl";
			// 
			// crawlBtn
			// 
			this->crawlBtn->Location = System::Drawing::Point(302, 200);
			this->crawlBtn->Name = L"crawlBtn";
			this->crawlBtn->Size = System::Drawing::Size(76, 33);
			this->crawlBtn->TabIndex = 0;
			this->crawlBtn->Text = L"Crawl ";
			this->crawlBtn->UseVisualStyleBackColor = true;
			this->crawlBtn->Click += gcnew System::EventHandler(this, &GUI::crawlBtn_Click);
			// 
			// recordTb
			// 
			this->recordTb->Location = System::Drawing::Point(278, 152);
			this->recordTb->Name = L"recordTb";
			this->recordTb->Size = System::Drawing::Size(100, 26);
			this->recordTb->TabIndex = 0;
			// 
			// keywordTb
			// 
			this->keywordTb->Location = System::Drawing::Point(278, 110);
			this->keywordTb->Name = L"keywordTb";
			this->keywordTb->Size = System::Drawing::Size(100, 26);
			this->keywordTb->TabIndex = 9;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(143, 155);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(129, 20);
			this->label2->TabIndex = 8;
			this->label2->Text = L"No. of Records";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(196, 113);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(76, 20);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Keyword";
			// 
			// tabPage2
			// 
			this->tabPage2->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->tabPage2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->tabPage2->Controls->Add(this->groupBox4);
			this->tabPage2->Controls->Add(this->groupBox3);
			this->tabPage2->Controls->Add(this->toptenBtn);
			this->tabPage2->Controls->Add(this->clearBtn);
			this->tabPage2->Controls->Add(this->label4);
			this->tabPage2->Controls->Add(this->button1);
			this->tabPage2->Controls->Add(this->richTextBox1);
			this->tabPage2->Controls->Add(this->displayBtn);
			this->tabPage2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(933, 529);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Twitter";
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->comboBox2);
			this->groupBox4->Controls->Add(this->btnSort);
			this->groupBox4->Location = System::Drawing::Point(734, 195);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(196, 104);
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
			this->comboBox2->Location = System::Drawing::Point(6, 21);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(192, 21);
			this->comboBox2->TabIndex = 20;
			// 
			// btnSort
			// 
			this->btnSort->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSort->Location = System::Drawing::Point(66, 48);
			this->btnSort->Name = L"btnSort";
			this->btnSort->Size = System::Drawing::Size(75, 23);
			this->btnSort->TabIndex = 18;
			this->btnSort->Text = L"Sort";
			this->btnSort->UseVisualStyleBackColor = true;
			this->btnSort->Click += gcnew System::EventHandler(this, &GUI::btnSort_Click);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->searchBtn);
			this->groupBox3->Controls->Add(this->searchTb);
			this->groupBox3->Location = System::Drawing::Point(734, 322);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(196, 81);
			this->groupBox3->TabIndex = 22;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Search by Keyword";
			// 
			// searchBtn
			// 
			this->searchBtn->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->searchBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->searchBtn->Location = System::Drawing::Point(66, 49);
			this->searchBtn->Name = L"searchBtn";
			this->searchBtn->Size = System::Drawing::Size(75, 24);
			this->searchBtn->TabIndex = 8;
			this->searchBtn->Text = L"Search";
			this->searchBtn->UseVisualStyleBackColor = true;
			this->searchBtn->Click += gcnew System::EventHandler(this, &GUI::searchBtn_Click);
			// 
			// searchTb
			// 
			this->searchTb->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->searchTb->Location = System::Drawing::Point(17, 21);
			this->searchTb->Name = L"searchTb";
			this->searchTb->Size = System::Drawing::Size(173, 22);
			this->searchTb->TabIndex = 9;
			// 
			// toptenBtn
			// 
			this->toptenBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->toptenBtn->Location = System::Drawing::Point(758, 138);
			this->toptenBtn->Name = L"toptenBtn";
			this->toptenBtn->Size = System::Drawing::Size(142, 33);
			this->toptenBtn->TabIndex = 15;
			this->toptenBtn->Text = L"Top Ten words";
			this->toptenBtn->UseVisualStyleBackColor = true;
			this->toptenBtn->Click += gcnew System::EventHandler(this, &GUI::toptenBtn_Click);
			// 
			// clearBtn
			// 
			this->clearBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->clearBtn->Location = System::Drawing::Point(758, 102);
			this->clearBtn->Name = L"clearBtn";
			this->clearBtn->Size = System::Drawing::Size(142, 30);
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
			this->label4->Location = System::Drawing::Point(6, 3);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(234, 25);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Twitter Crawl Display";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(758, 31);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(142, 30);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Import CSV";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &GUI::button1_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox1->Location = System::Drawing::Point(6, 31);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(714, 491);
			this->richTextBox1->TabIndex = 6;
			this->richTextBox1->Text = L"";
			// 
			// displayBtn
			// 
			this->displayBtn->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->displayBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->displayBtn->Location = System::Drawing::Point(758, 67);
			this->displayBtn->Name = L"displayBtn";
			this->displayBtn->Size = System::Drawing::Size(142, 29);
			this->displayBtn->TabIndex = 5;
			this->displayBtn->Text = L"Display CSV";
			this->displayBtn->UseVisualStyleBackColor = true;
			this->displayBtn->Click += gcnew System::EventHandler(this, &GUI::displayBtn_Click);
			// 
			// tabPage3
			// 
			this->tabPage3->BackColor = System::Drawing::Color::IndianRed;
			this->tabPage3->Controls->Add(this->groupBox5);
			this->tabPage3->Controls->Add(this->clearBtn2);
			this->tabPage3->Controls->Add(this->button2);
			this->tabPage3->Controls->Add(this->displayBtn2);
			this->tabPage3->Controls->Add(this->richTextBox2);
			this->tabPage3->Controls->Add(this->label6);
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(933, 529);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"CNA";
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->searchTb2);
			this->groupBox5->Controls->Add(this->searchBtn2);
			this->groupBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox5->Location = System::Drawing::Point(737, 223);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(190, 94);
			this->groupBox5->TabIndex = 22;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Search by Keyword";
			// 
			// searchTb2
			// 
			this->searchTb2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->searchTb2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->searchTb2->Location = System::Drawing::Point(10, 21);
			this->searchTb2->Name = L"searchTb2";
			this->searchTb2->Size = System::Drawing::Size(174, 20);
			this->searchTb2->TabIndex = 17;
			// 
			// searchBtn2
			// 
			this->searchBtn2->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->searchBtn2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->searchBtn2->Location = System::Drawing::Point(50, 52);
			this->searchBtn2->Name = L"searchBtn2";
			this->searchBtn2->Size = System::Drawing::Size(75, 36);
			this->searchBtn2->TabIndex = 16;
			this->searchBtn2->Text = L"Search";
			this->searchBtn2->UseVisualStyleBackColor = true;
			this->searchBtn2->Click += gcnew System::EventHandler(this, &GUI::searchBtn2_Click);
			// 
			// clearBtn2
			// 
			this->clearBtn2->Location = System::Drawing::Point(750, 116);
			this->clearBtn2->Name = L"clearBtn2";
			this->clearBtn2->Size = System::Drawing::Size(156, 32);
			this->clearBtn2->TabIndex = 21;
			this->clearBtn2->Text = L"Clear Display";
			this->clearBtn2->UseVisualStyleBackColor = true;
			this->clearBtn2->Click += gcnew System::EventHandler(this, &GUI::clearBtn2_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(750, 42);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(156, 30);
			this->button2->TabIndex = 20;
			this->button2->Text = L"Import CSV";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &GUI::button2_Click);
			// 
			// displayBtn2
			// 
			this->displayBtn2->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->displayBtn2->Location = System::Drawing::Point(750, 78);
			this->displayBtn2->Name = L"displayBtn2";
			this->displayBtn2->Size = System::Drawing::Size(156, 32);
			this->displayBtn2->TabIndex = 19;
			this->displayBtn2->Text = L"Display CSV";
			this->displayBtn2->UseVisualStyleBackColor = true;
			this->displayBtn2->Click += gcnew System::EventHandler(this, &GUI::displayBtn2_Click);
			// 
			// richTextBox2
			// 
			this->richTextBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox2->Location = System::Drawing::Point(3, 31);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->ReadOnly = true;
			this->richTextBox2->Size = System::Drawing::Size(724, 495);
			this->richTextBox2->TabIndex = 18;
			this->richTextBox2->Text = L"";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::LightGray;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(3, 3);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(210, 25);
			this->label6->TabIndex = 0;
			this->label6->Text = L"CNA Crawl Display";
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// GUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(941, 555);
			this->Controls->Add(this->tabControl1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"GUI";
			this->Text = L"Crawler GUI";
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
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
			readData();
			twitterData tweet;
			tweet.set_csvfilepath(filename);// use stadard string
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
			for (int j = 0; j < ::size; ++j) 
			{
				//std::string date = marshal_as<std::string>(twitter[i].getDate());
				//textBox1->Text="Time Date";

				//std::string test1 = std::to_string(j);
				//String^ str2 = gcnew String(test1.c_str());
				//MessageBox::Show(str2);
				richTextBox1->Text += "Date Time: " + marshal_as<String^>(twitter[j].getDate()) + "\r"
					+ "User ID: " + marshal_as<String^>(twitter[j].getUserId()) + "\r"
					+ "User Tweet: " + marshal_as<String^>(twitter[j].getPost()) + "\r" + "------------------------------------------------------------------------------------------------------------------------------------------------------------------" + "\r";


			}
		}
	} /*-----------------------------END OF DISPLAY CSV BUTTON------------------------------------*/
		/*---------------------END  OF DISPLAY CSV BUTTO----------------------------*/

	/*Twitter Search keyword BUTTON*/
	private: System::Void searchBtn_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		vector<twitterData> filtered;
		
		
		
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
			
			
			
			
			filtered = searchKeyword(searchword);//function
			if (filtered.empty())
			{
				MessageBox::Show("No Records "+ search+" Found!", "Error:");
			}
			else{
			for (int j = 0; j < filtered.size(); ++j) 
			{
				
				richTextBox1->Text +="Date Time: " + marshal_as<String^>(filtered[j].getDate()) + "\r"
									+ "User ID: " + marshal_as<String^>(filtered[j].getUserId()) + "\r"
									+ "User Tweet: " + marshal_as<String^>(filtered[j].getPost()) + "\r" + "------------------------------------------------------------------------------------------------------------------------------------------------------------------"+"\r";


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
		for (int i = 0; i < ::size; ++i) 
		{

			richTextBox1->Text += "Date Time: " + marshal_as<String^>(twitter[i].getDate()) + "\r"
				+ "User ID: " + marshal_as<String^>(twitter[i].getUserId()) + "\r"
				+ "User Tweet: " + marshal_as<String^>(twitter[i].getPost()) + "\r" + "------------------------------------------------------------------------------------------------------------------------------------------------------------------" + "\r";
		}
		
	}
	/*End of top ten BUTTON*/
	





/*-----------------------------------------------CNA Buttons-------------------------------------------*/
	/*CNA Search by keyword*/
	private: System::Void searchBtn2_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		vector<CNA> filtered;
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
			

			readCNAData();

			filtered = searchKeywordcna(searchword);//function

			if (filtered.empty())
			{
				MessageBox::Show("No Records " + search + " Found!", "Error:");
			}
			else {
				for (int j = 0; j < filtered.size(); ++j)
				{

					richTextBox2->Text += "Date: " + marshal_as<String^>(filtered[j].getDate()) + "\r"
						+ "Author: " + marshal_as<String^>(filtered[j].getUserId()) + "\r"
						+ "Title: " + marshal_as<String^>(filtered[j].getPost()) + "\r" + "------------------------------------------------------------------------------------------------------------------------------------------------------------------" + "\r";


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
		readCNAData();//Read CNA CSV
		for (int j = 0; j < ::size; ++j) 
		{

			richTextBox2->Text += "Date: " + marshal_as<String^>(cna[j].getDate()) + "\r"
				+ "Author: " + marshal_as<String^>(cna[j].getUserId()) + "\r"
				+ "Title: " + marshal_as<String^>(cna[j].getPost()) + "\r" + "------------------------------------------------------------------------------------------------------------------------------------------------------------------" + "\r";


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
			readCNAData();
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
		
	}
	/* End of Clear Display*/
};
}

