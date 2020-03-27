
#include "Crawler.h"
#include "twitter.h"
#include <string>
#include <msclr\marshal_cppstd.h>
#include <filesystem>
#include <string>
#include <iostream>
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
	private: System::Windows::Forms::TabPage^ tabPage4;
	private: System::Windows::Forms::TabPage^ tabPage5;
	private: System::Windows::Forms::TabPage^ tabPage6;
	private: System::Windows::Forms::TextBox^ recordTb;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ keywordTb;
	private: System::Windows::Forms::Button^ importBtn;

	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;




	private: System::Windows::Forms::Button^ displayBtn;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;

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
			this->recordTb = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->keywordTb = (gcnew System::Windows::Forms::TextBox());
			this->crawlBtn = (gcnew System::Windows::Forms::Button());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->displayBtn = (gcnew System::Windows::Forms::Button());
			this->importBtn = (gcnew System::Windows::Forms::Button());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage6 = (gcnew System::Windows::Forms::TabPage());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage4);
			this->tabControl1->Controls->Add(this->tabPage5);
			this->tabControl1->Controls->Add(this->tabPage6);
			this->tabControl1->Location = System::Drawing::Point(-1, -1);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(646, 458);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->recordTb);
			this->tabPage1->Controls->Add(this->label2);
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Controls->Add(this->keywordTb);
			this->tabPage1->Controls->Add(this->crawlBtn);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(638, 432);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Main Menu";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// recordTb
			// 
			this->recordTb->Location = System::Drawing::Point(118, 84);
			this->recordTb->Name = L"recordTb";
			this->recordTb->Size = System::Drawing::Size(100, 20);
			this->recordTb->TabIndex = 0;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(33, 87);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(79, 13);
			this->label2->TabIndex = 8;
			this->label2->Text = L"No. of Records";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(64, 48);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(48, 13);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Keyword";
			// 
			// keywordTb
			// 
			this->keywordTb->Location = System::Drawing::Point(118, 45);
			this->keywordTb->Name = L"keywordTb";
			this->keywordTb->Size = System::Drawing::Size(100, 20);
			this->keywordTb->TabIndex = 9;
			// 
			// crawlBtn
			// 
			this->crawlBtn->Location = System::Drawing::Point(142, 125);
			this->crawlBtn->Name = L"crawlBtn";
			this->crawlBtn->Size = System::Drawing::Size(76, 33);
			this->crawlBtn->TabIndex = 0;
			this->crawlBtn->Text = L"Crawl ";
			this->crawlBtn->UseVisualStyleBackColor = true;
			this->crawlBtn->Click += gcnew System::EventHandler(this, &GUI::crawlBtn_Click);
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->richTextBox1);
			this->tabPage2->Controls->Add(this->displayBtn);
			this->tabPage2->Controls->Add(this->importBtn);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(638, 432);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"View Record";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// displayBtn
			// 
			this->displayBtn->Location = System::Drawing::Point(513, 374);
			this->displayBtn->Name = L"displayBtn";
			this->displayBtn->Size = System::Drawing::Size(75, 23);
			this->displayBtn->TabIndex = 5;
			this->displayBtn->Text = L"Display CSV";
			this->displayBtn->UseVisualStyleBackColor = true;
			this->displayBtn->Click += gcnew System::EventHandler(this, &GUI::displayBtn_Click);
			// 
			// importBtn
			// 
			this->importBtn->Location = System::Drawing::Point(417, 374);
			this->importBtn->Name = L"importBtn";
			this->importBtn->Size = System::Drawing::Size(75, 23);
			this->importBtn->TabIndex = 3;
			this->importBtn->Text = L"Import CSV file";
			this->importBtn->UseVisualStyleBackColor = true;
			this->importBtn->Click += gcnew System::EventHandler(this, &GUI::importBtn_Click_1);
			// 
			// tabPage3
			// 
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(638, 432);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Function1";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// tabPage4
			// 
			this->tabPage4->Location = System::Drawing::Point(4, 22);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Size = System::Drawing::Size(638, 432);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"Function2";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// tabPage5
			// 
			this->tabPage5->Location = System::Drawing::Point(4, 22);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Size = System::Drawing::Size(638, 432);
			this->tabPage5->TabIndex = 4;
			this->tabPage5->Text = L"tabPage5";
			this->tabPage5->UseVisualStyleBackColor = true;
			// 
			// tabPage6
			// 
			this->tabPage6->Location = System::Drawing::Point(4, 22);
			this->tabPage6->Name = L"tabPage6";
			this->tabPage6->Size = System::Drawing::Size(638, 432);
			this->tabPage6->TabIndex = 5;
			this->tabPage6->Text = L"tabPage6";
			this->tabPage6->UseVisualStyleBackColor = true;
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(3, 6);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(618, 333);
			this->richTextBox1->TabIndex = 6;
			this->richTextBox1->Text = L"";
			// 
			// GUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(645, 455);
			this->Controls->Add(this->tabControl1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"GUI";
			this->Text = L"Crawler GUI";
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
		/*BUTTONS for Crawling*/
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
		   /*END  OF BUTTONS for Crawling*/


		   /*BUTTONS for Importing CSV File*/
	private: System::Void importBtn_Click_1(System::Object^ sender, System::EventArgs^ e)
	{
		
		

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
			MessageBox::Show(filepath, "FilePath:");//use system strig

			

		}
	}
		   /*END  OF BUTTONS for Importing CSV File*/

	
	private: System::Void displayBtn_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		twitterData display;
		twitterData twitter[100];


		
		int size =display.readData();

		//richTextBox1->Text = marshal_as<String^>(display.getDate());
		for (int i = 0; i < size; ++i) {
			//std::string date = marshal_as<std::string>(twitter[i].getDate());
			//textBox1->Text="Time Date";
			
			
			richTextBox1->Text = "Date Time: " + marshal_as<String^>(twitter[i].getDate()) + "\r"
								 + "User ID: " + marshal_as<String^>(twitter[i].getUserId()) + "\r"
								 + "User Post: " + marshal_as<String^>(twitter[i].getPost()) + "\r";
			

			//cout << twitter[i].getDate() << endl;
			//cout << twitter[i].getUserId() << endl;
			//cout << twitter[i].getPost()<< endl;
		}
	}
};
}


