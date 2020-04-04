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
	private: System::Windows::Forms::Button^ btnTweetDisplay;





	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Button^ btnTweetImport;










	private: System::Windows::Forms::GroupBox^ groupBox1;



	private: System::Windows::Forms::TextBox^ searchTb;
	private: System::Windows::Forms::Button^ btnTweetSearch;



	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ btnTweetClear;



	private: System::Windows::Forms::TextBox^ searchTb2;
	private: System::Windows::Forms::Button^ btnCnaSearch;



	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ btnCnaImport;
	private: System::Windows::Forms::Button^ btnCnaDisplay;






	private: System::Windows::Forms::RichTextBox^ richTextBox2;
	private: System::Windows::Forms::Button^ btnCnaClear;


	private: System::Windows::Forms::Button^ btnTweetTopTen;
	private: System::Windows::Forms::Button^ btnTweetSort;






	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::GroupBox^ grpBoxSortTweet;
	private: System::Windows::Forms::GroupBox^ grpBoxSearchTweet;


	private: System::Windows::Forms::GroupBox^ groupBox5;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridView^ dataGridView2;



private: System::Windows::Forms::Button^ btnCnaTopTen;


	private: System::Windows::Forms::TabPage^ tabPage4;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::ComboBox^ comboBox1;
private: System::Windows::Forms::Button^ btnCnaSort;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column6;





















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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea4 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
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
			this->grpBoxSortTweet = (gcnew System::Windows::Forms::GroupBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->btnTweetSort = (gcnew System::Windows::Forms::Button());
			this->grpBoxSearchTweet = (gcnew System::Windows::Forms::GroupBox());
			this->btnTweetSearch = (gcnew System::Windows::Forms::Button());
			this->searchTb = (gcnew System::Windows::Forms::TextBox());
			this->btnTweetTopTen = (gcnew System::Windows::Forms::Button());
			this->btnTweetClear = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->btnTweetImport = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->btnTweetDisplay = (gcnew System::Windows::Forms::Button());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->btnCnaSort = (gcnew System::Windows::Forms::Button());
			this->btnCnaTopTen = (gcnew System::Windows::Forms::Button());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->searchTb2 = (gcnew System::Windows::Forms::TextBox());
			this->btnCnaSearch = (gcnew System::Windows::Forms::Button());
			this->btnCnaClear = (gcnew System::Windows::Forms::Button());
			this->btnCnaImport = (gcnew System::Windows::Forms::Button());
			this->btnCnaDisplay = (gcnew System::Windows::Forms::Button());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->grpBoxSortTweet->SuspendLayout();
			this->grpBoxSearchTweet->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->groupBox5->SuspendLayout();
			this->tabPage4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage4);
			this->tabControl1->Location = System::Drawing::Point(-1, -1);
			this->tabControl1->Margin = System::Windows::Forms::Padding(4);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1475, 794);
			this->tabControl1->TabIndex = 3;
			// 
			// tabPage1
			// 
			this->tabPage1->BackColor = System::Drawing::Color::LavenderBlush;
			this->tabPage1->Controls->Add(this->groupBox1);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Margin = System::Windows::Forms::Padding(4);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(4);
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
			this->groupBox1->Margin = System::Windows::Forms::Padding(4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4);
			this->groupBox1->Size = System::Drawing::Size(1080, 532);
			this->groupBox1->TabIndex = 10;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Twitter Crawl";
			// 
			// crawlBtn
			// 
			this->crawlBtn->Location = System::Drawing::Point(504, 282);
			this->crawlBtn->Margin = System::Windows::Forms::Padding(4);
			this->crawlBtn->Name = L"crawlBtn";
			this->crawlBtn->Size = System::Drawing::Size(101, 41);
			this->crawlBtn->TabIndex = 2;
			this->crawlBtn->Text = L"Crawl ";
			this->crawlBtn->UseVisualStyleBackColor = true;
			this->crawlBtn->Click += gcnew System::EventHandler(this, &GUI::crawlBtn_Click);
			// 
			// recordTb
			// 
			this->recordTb->Location = System::Drawing::Point(472, 223);
			this->recordTb->Margin = System::Windows::Forms::Padding(4);
			this->recordTb->Name = L"recordTb";
			this->recordTb->Size = System::Drawing::Size(132, 31);
			this->recordTb->TabIndex = 1;
			// 
			// keywordTb
			// 
			this->keywordTb->Location = System::Drawing::Point(472, 171);
			this->keywordTb->Margin = System::Windows::Forms::Padding(4);
			this->keywordTb->Name = L"keywordTb";
			this->keywordTb->Size = System::Drawing::Size(132, 31);
			this->keywordTb->TabIndex = 0;
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
			this->tabPage2->Controls->Add(this->grpBoxSortTweet);
			this->tabPage2->Controls->Add(this->grpBoxSearchTweet);
			this->tabPage2->Controls->Add(this->btnTweetTopTen);
			this->tabPage2->Controls->Add(this->btnTweetClear);
			this->tabPage2->Controls->Add(this->label4);
			this->tabPage2->Controls->Add(this->btnTweetImport);
			this->tabPage2->Controls->Add(this->richTextBox1);
			this->tabPage2->Controls->Add(this->btnTweetDisplay);
			this->tabPage2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Margin = System::Windows::Forms::Padding(4);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(4);
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
			this->dataGridView1->Margin = System::Windows::Forms::Padding(4);
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
			// grpBoxSortTweet
			// 
			this->grpBoxSortTweet->Controls->Add(this->comboBox2);
			this->grpBoxSortTweet->Controls->Add(this->btnTweetSort);
			this->grpBoxSortTweet->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->grpBoxSortTweet->Location = System::Drawing::Point(1188, 38);
			this->grpBoxSortTweet->Margin = System::Windows::Forms::Padding(4);
			this->grpBoxSortTweet->Name = L"grpBoxSortTweet";
			this->grpBoxSortTweet->Padding = System::Windows::Forms::Padding(4);
			this->grpBoxSortTweet->Size = System::Drawing::Size(267, 128);
			this->grpBoxSortTweet->TabIndex = 4;
			this->grpBoxSortTweet->TabStop = false;
			this->grpBoxSortTweet->Text = L"Sort By";
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
			this->comboBox2->Margin = System::Windows::Forms::Padding(4);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(255, 25);
			this->comboBox2->TabIndex = 0;
			// 
			// btnTweetSort
			// 
			this->btnTweetSort->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnTweetSort->Location = System::Drawing::Point(88, 59);
			this->btnTweetSort->Margin = System::Windows::Forms::Padding(4);
			this->btnTweetSort->Name = L"btnTweetSort";
			this->btnTweetSort->Size = System::Drawing::Size(100, 28);
			this->btnTweetSort->TabIndex = 1;
			this->btnTweetSort->Text = L"Sort";
			this->btnTweetSort->UseVisualStyleBackColor = true;
			this->btnTweetSort->Click += gcnew System::EventHandler(this, &GUI::btnTweetSort_Click);
			// 
			// grpBoxSearchTweet
			// 
			this->grpBoxSearchTweet->Controls->Add(this->btnTweetSearch);
			this->grpBoxSearchTweet->Controls->Add(this->searchTb);
			this->grpBoxSearchTweet->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->grpBoxSearchTweet->Location = System::Drawing::Point(1188, 174);
			this->grpBoxSearchTweet->Margin = System::Windows::Forms::Padding(4);
			this->grpBoxSearchTweet->Name = L"grpBoxSearchTweet";
			this->grpBoxSearchTweet->Padding = System::Windows::Forms::Padding(4);
			this->grpBoxSearchTweet->Size = System::Drawing::Size(261, 100);
			this->grpBoxSearchTweet->TabIndex = 5;
			this->grpBoxSearchTweet->TabStop = false;
			this->grpBoxSearchTweet->Text = L"Search by Keyword";
			// 
			// btnTweetSearch
			// 
			this->btnTweetSearch->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnTweetSearch->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnTweetSearch->Location = System::Drawing::Point(88, 60);
			this->btnTweetSearch->Margin = System::Windows::Forms::Padding(4);
			this->btnTweetSearch->Name = L"btnTweetSearch";
			this->btnTweetSearch->Size = System::Drawing::Size(100, 30);
			this->btnTweetSearch->TabIndex = 1;
			this->btnTweetSearch->Text = L"Search";
			this->btnTweetSearch->UseVisualStyleBackColor = true;
			this->btnTweetSearch->Click += gcnew System::EventHandler(this, &GUI::btnTweetSearch_Click);
			// 
			// searchTb
			// 
			this->searchTb->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->searchTb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->searchTb->Location = System::Drawing::Point(8, 26);
			this->searchTb->Margin = System::Windows::Forms::Padding(4);
			this->searchTb->Name = L"searchTb";
			this->searchTb->Size = System::Drawing::Size(245, 27);
			this->searchTb->TabIndex = 0;
			// 
			// btnTweetTopTen
			// 
			this->btnTweetTopTen->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnTweetTopTen->Location = System::Drawing::Point(1221, 436);
			this->btnTweetTopTen->Margin = System::Windows::Forms::Padding(4);
			this->btnTweetTopTen->Name = L"btnTweetTopTen";
			this->btnTweetTopTen->Size = System::Drawing::Size(208, 41);
			this->btnTweetTopTen->TabIndex = 3;
			this->btnTweetTopTen->Text = L"Top Ten words";
			this->btnTweetTopTen->UseVisualStyleBackColor = true;
			this->btnTweetTopTen->Click += gcnew System::EventHandler(this, &GUI::btnTweetTopTen_Click);
			// 
			// btnTweetClear
			// 
			this->btnTweetClear->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnTweetClear->Location = System::Drawing::Point(1221, 388);
			this->btnTweetClear->Margin = System::Windows::Forms::Padding(4);
			this->btnTweetClear->Name = L"btnTweetClear";
			this->btnTweetClear->Size = System::Drawing::Size(208, 41);
			this->btnTweetClear->TabIndex = 2;
			this->btnTweetClear->Text = L"Clear Display";
			this->btnTweetClear->UseVisualStyleBackColor = true;
			this->btnTweetClear->Click += gcnew System::EventHandler(this, &GUI::btnTweetClear_Click);
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
			// btnTweetImport
			// 
			this->btnTweetImport->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnTweetImport->Location = System::Drawing::Point(1221, 292);
			this->btnTweetImport->Margin = System::Windows::Forms::Padding(4);
			this->btnTweetImport->Name = L"btnTweetImport";
			this->btnTweetImport->Size = System::Drawing::Size(208, 41);
			this->btnTweetImport->TabIndex = 0;
			this->btnTweetImport->Text = L"Import CSV";
			this->btnTweetImport->UseVisualStyleBackColor = true;
			this->btnTweetImport->Click += gcnew System::EventHandler(this, &GUI::btnTweetImport_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox1->Location = System::Drawing::Point(1191, 484);
			this->richTextBox1->Margin = System::Windows::Forms::Padding(4);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(257, 260);
			this->richTextBox1->TabIndex = 6;
			this->richTextBox1->TabStop = false;
			this->richTextBox1->Text = L"";
			// 
			// btnTweetDisplay
			// 
			this->btnTweetDisplay->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnTweetDisplay->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnTweetDisplay->Location = System::Drawing::Point(1221, 340);
			this->btnTweetDisplay->Margin = System::Windows::Forms::Padding(4);
			this->btnTweetDisplay->Name = L"btnTweetDisplay";
			this->btnTweetDisplay->Size = System::Drawing::Size(208, 41);
			this->btnTweetDisplay->TabIndex = 1;
			this->btnTweetDisplay->Text = L"Display CSV";
			this->btnTweetDisplay->UseVisualStyleBackColor = true;
			this->btnTweetDisplay->Click += gcnew System::EventHandler(this, &GUI::btnTweetDisplay_Click);
			// 
			// tabPage3
			// 
			this->tabPage3->BackColor = System::Drawing::Color::IndianRed;
			this->tabPage3->Controls->Add(this->groupBox2);
			this->tabPage3->Controls->Add(this->btnCnaTopTen);
			this->tabPage3->Controls->Add(this->dataGridView2);
			this->tabPage3->Controls->Add(this->groupBox5);
			this->tabPage3->Controls->Add(this->btnCnaClear);
			this->tabPage3->Controls->Add(this->btnCnaImport);
			this->tabPage3->Controls->Add(this->btnCnaDisplay);
			this->tabPage3->Controls->Add(this->richTextBox2);
			this->tabPage3->Controls->Add(this->label6);
			this->tabPage3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->tabPage3->Location = System::Drawing::Point(4, 25);
			this->tabPage3->Margin = System::Windows::Forms::Padding(4);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(4);
			this->tabPage3->Size = System::Drawing::Size(1467, 765);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"CNA";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->comboBox1);
			this->groupBox2->Controls->Add(this->btnCnaSort);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox2->Location = System::Drawing::Point(1192, 38);
			this->groupBox2->Margin = System::Windows::Forms::Padding(4);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(4);
			this->groupBox2->Size = System::Drawing::Size(267, 128);
			this->groupBox2->TabIndex = 4;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Sort By";
			// 
			// comboBox1
			// 
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"Sort ascending order by source", L"Sort descending order by source",
					L"Sort ascending order by headline", L"Sort descending order by headline"
			});
			this->comboBox1->Location = System::Drawing::Point(3, 31);
			this->comboBox1->Margin = System::Windows::Forms::Padding(4);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(255, 25);
			this->comboBox1->TabIndex = 0;
			// 
			// btnCnaSort
			// 
			this->btnCnaSort->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCnaSort->Location = System::Drawing::Point(88, 59);
			this->btnCnaSort->Margin = System::Windows::Forms::Padding(4);
			this->btnCnaSort->Name = L"btnCnaSort";
			this->btnCnaSort->Size = System::Drawing::Size(100, 28);
			this->btnCnaSort->TabIndex = 1;
			this->btnCnaSort->Text = L"Sort";
			this->btnCnaSort->UseVisualStyleBackColor = true;
			this->btnCnaSort->Click += gcnew System::EventHandler(this, &GUI::btnCnaSort_Click);
			// 
			// btnCnaTopTen
			// 
			this->btnCnaTopTen->Location = System::Drawing::Point(1211, 423);
			this->btnCnaTopTen->Margin = System::Windows::Forms::Padding(4);
			this->btnCnaTopTen->Name = L"btnCnaTopTen";
			this->btnCnaTopTen->Size = System::Drawing::Size(219, 39);
			this->btnCnaTopTen->TabIndex = 3;
			this->btnCnaTopTen->Text = L"Top Ten words";
			this->btnCnaTopTen->UseVisualStyleBackColor = true;
			this->btnCnaTopTen->Click += gcnew System::EventHandler(this, &GUI::btnCnaTopTen_Click);
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
			this->dataGridView2->Location = System::Drawing::Point(0, 38);
			this->dataGridView2->Margin = System::Windows::Forms::Padding(4);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->ReadOnly = true;
			this->dataGridView2->RowHeadersWidth = 53;
			this->dataGridView2->Size = System::Drawing::Size(1180, 720);
			this->dataGridView2->TabIndex = 23;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Source";
			this->Column4->MinimumWidth = 7;
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			this->Column4->Width = 94;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Date";
			this->Column5->MinimumWidth = 7;
			this->Column5->Name = L"Column5";
			this->Column5->ReadOnly = true;
			this->Column5->Width = 77;
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"Headline";
			this->Column6->MinimumWidth = 7;
			this->Column6->Name = L"Column6";
			this->Column6->ReadOnly = true;
			this->Column6->Width = 107;
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->searchTb2);
			this->groupBox5->Controls->Add(this->btnCnaSearch);
			this->groupBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox5->Location = System::Drawing::Point(1188, 174);
			this->groupBox5->Margin = System::Windows::Forms::Padding(4);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Padding = System::Windows::Forms::Padding(4);
			this->groupBox5->Size = System::Drawing::Size(261, 100);
			this->groupBox5->TabIndex = 5;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Search by Keyword";
			// 
			// searchTb2
			// 
			this->searchTb2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->searchTb2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->searchTb2->Location = System::Drawing::Point(8, 28);
			this->searchTb2->Margin = System::Windows::Forms::Padding(4);
			this->searchTb2->Name = L"searchTb2";
			this->searchTb2->Size = System::Drawing::Size(245, 24);
			this->searchTb2->TabIndex = 0;
			// 
			// btnCnaSearch
			// 
			this->btnCnaSearch->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnCnaSearch->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCnaSearch->Location = System::Drawing::Point(88, 60);
			this->btnCnaSearch->Margin = System::Windows::Forms::Padding(4);
			this->btnCnaSearch->Name = L"btnCnaSearch";
			this->btnCnaSearch->Size = System::Drawing::Size(100, 30);
			this->btnCnaSearch->TabIndex = 2;
			this->btnCnaSearch->Text = L"Search";
			this->btnCnaSearch->UseVisualStyleBackColor = true;
			this->btnCnaSearch->Click += gcnew System::EventHandler(this, &GUI::btnCnaSearch_Click);
			// 
			// btnCnaClear
			// 
			this->btnCnaClear->Location = System::Drawing::Point(1211, 376);
			this->btnCnaClear->Margin = System::Windows::Forms::Padding(4);
			this->btnCnaClear->Name = L"btnCnaClear";
			this->btnCnaClear->Size = System::Drawing::Size(219, 39);
			this->btnCnaClear->TabIndex = 2;
			this->btnCnaClear->Text = L"Clear Display";
			this->btnCnaClear->UseVisualStyleBackColor = true;
			this->btnCnaClear->Click += gcnew System::EventHandler(this, &GUI::btnCnaClear_Click);
			// 
			// btnCnaImport
			// 
			this->btnCnaImport->Location = System::Drawing::Point(1211, 282);
			this->btnCnaImport->Margin = System::Windows::Forms::Padding(4);
			this->btnCnaImport->Name = L"btnCnaImport";
			this->btnCnaImport->Size = System::Drawing::Size(219, 41);
			this->btnCnaImport->TabIndex = 0;
			this->btnCnaImport->Text = L"Import CSV";
			this->btnCnaImport->UseVisualStyleBackColor = true;
			this->btnCnaImport->Click += gcnew System::EventHandler(this, &GUI::btnCnaImport_Click);
			// 
			// btnCnaDisplay
			// 
			this->btnCnaDisplay->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnCnaDisplay->Location = System::Drawing::Point(1211, 330);
			this->btnCnaDisplay->Margin = System::Windows::Forms::Padding(4);
			this->btnCnaDisplay->Name = L"btnCnaDisplay";
			this->btnCnaDisplay->Size = System::Drawing::Size(219, 38);
			this->btnCnaDisplay->TabIndex = 1;
			this->btnCnaDisplay->Text = L"Display CSV";
			this->btnCnaDisplay->UseVisualStyleBackColor = true;
			this->btnCnaDisplay->Click += gcnew System::EventHandler(this, &GUI::btnCnaDisplay_Click);
			// 
			// richTextBox2
			// 
			this->richTextBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox2->Location = System::Drawing::Point(1191, 484);
			this->richTextBox2->Margin = System::Windows::Forms::Padding(4);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->ReadOnly = true;
			this->richTextBox2->Size = System::Drawing::Size(257, 260);
			this->richTextBox2->TabIndex = 18;
			this->richTextBox2->TabStop = false;
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
			// tabPage4
			// 
			this->tabPage4->Controls->Add(this->chart1);
			this->tabPage4->Location = System::Drawing::Point(4, 25);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Padding = System::Windows::Forms::Padding(3);
			this->tabPage4->Size = System::Drawing::Size(1467, 765);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"tabPage4";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// chart1
			// 
			chartArea4->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea4);
			legend4->Name = L"Legend1";
			this->chart1->Legends->Add(legend4);
			this->chart1->Location = System::Drawing::Point(368, 95);
			this->chart1->Name = L"chart1";
			series4->ChartArea = L"ChartArea1";
			series4->Legend = L"Legend1";
			series4->Name = L"Series1";
			this->chart1->Series->Add(series4);
			this->chart1->Size = System::Drawing::Size(848, 417);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->ImageScalingSize = System::Drawing::Size(21, 21);
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// GUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1475, 796);
			this->Controls->Add(this->tabControl1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"GUI";
			this->Text = L"Crawler GUI";
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->grpBoxSortTweet->ResumeLayout(false);
			this->grpBoxSearchTweet->ResumeLayout(false);
			this->grpBoxSearchTweet->PerformLayout();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->tabPage4->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		//Global Var
		bool plsimporttweet = 0;//check for impor csv twiiter
		bool plsimportcna = 0;//check for import csv cna

	
	/*BUTTONS for Crawling*/
	private: System::Void crawlBtn_Click(System::Object^ sender, System::EventArgs^ e);
	/*END OF BUTTONS for Crawling*/

	/*-----------------------------------------------Twitter Buttons-------------------------------------------*/

	/*BUTTONS for Importing CSV File*/
	private: System::Void btnTweetImport_Click(System::Object^ sender, System::EventArgs^ e);
	/*END OF BUTTONS for Importing CSV File*/

	/*DISPLAY CSV BUTTON*/
	private: System::Void btnTweetDisplay_Click(System::Object^ sender, System::EventArgs^ e);
	/*END OF DISPLAY CSV BUTTON*/

	
	/*Twitter Search keyword BUTTON*/
	private: System::Void btnTweetSearch_Click(System::Object^ sender, System::EventArgs^ e);
	/*End of Twitter Search keyword BUTTON*/
	
	/*clear BUTTON*/
	private: System::Void btnTweetClear_Click(System::Object^ sender, System::EventArgs^ e);
	/*End of clear BUTTON*/
	
	/*top ten BUTTON*/
	private: System::Void btnTweetTopTen_Click(System::Object^ sender, System::EventArgs^ e);
	/*End of top ten BUTTON*/
	
	/*Twitter Sort BUTTON*/
	private: System::Void btnTweetSort_Click(System::Object^ sender, System::EventArgs^ e);
	/*End of top ten BUTTON*/

	/*-----------------------------------------------CNA Buttons-------------------------------------------*/

	/*CNA Search by keyword*/
	private: System::Void btnCnaSearch_Click(System::Object^ sender, System::EventArgs^ e);
	/*END of CNA Search by keyword*/

	/*Display CNA CSV*/
	private: System::Void btnCnaDisplay_Click(System::Object^ sender, System::EventArgs^ e);
	/*END Display CNA CSV*/

	/*Loading CNA CSV*/
	private: System::Void btnCnaImport_Click(System::Object^ sender, System::EventArgs^ e);
	/*End of Loading CNA CSV*/
	
	/*Clear Display Button*/
	private: System::Void btnCnaClear_Click(System::Object^ sender, System::EventArgs^ e);
	/* End of Clear Button*/

	/*CNA top ten button*/
	private: System::Void btnCnaTopTen_Click(System::Object^ sender, System::EventArgs^ e);
	/*End of top ten BUTTON*/

	/*CNA Sort BUTTON*/
	private: System::Void btnCnaSort_Click(System::Object^ sender, System::EventArgs^ e);
	/*End of CNA Sort BUTTON*/
};
}