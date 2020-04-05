#include "GUI.h"

using namespace System;
using namespace System::Windows::Forms;

//to error LNK2019: unresolved external symbols
//due to twitcurl lib developed in older programming definitions
//https://stackoverflow.com/questions/30412951/unresolved-external-symbol-imp-fprintf-and-imp-iob-func-sdl2
#define stdin  (__acrt_iob_func(0))
#define stdout (__acrt_iob_func(1))
#define stderr (__acrt_iob_func(2))

FILE _iob[] = { *stdin, *stdout, *stderr };

extern "C" FILE * __cdecl __iob_func(void) { return _iob; }
extern "C" void __imp__set_output_format(void) {};

[STAThread]
void main(cli::array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	CPPProject1009Gui::GUI form;
	Application::Run(% form);

}

/*------------------------------------------ Creates all GUI components -----------------------------------*/
/*Creates all GUI components*/
void CPPProject1009Gui::GUI::InitializeComponent(void)
{
	this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
	this->tabCrawler = (gcnew System::Windows::Forms::TabPage());
	this->grpBoxCrawler = (gcnew System::Windows::Forms::GroupBox());
	this->crawlBtn = (gcnew System::Windows::Forms::Button());
	this->recordTb = (gcnew System::Windows::Forms::TextBox());
	this->keywordTb = (gcnew System::Windows::Forms::TextBox());
	this->crawlerLabel2 = (gcnew System::Windows::Forms::Label());
	this->crawlerLabel1 = (gcnew System::Windows::Forms::Label());
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
	this->twitterLabel1 = (gcnew System::Windows::Forms::Label());
	this->btnTweetImport = (gcnew System::Windows::Forms::Button());
	this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
	this->btnTweetDisplay = (gcnew System::Windows::Forms::Button());
	this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
	this->grpBoxSortCna = (gcnew System::Windows::Forms::GroupBox());
	this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
	this->btnCnaSort = (gcnew System::Windows::Forms::Button());
	this->btnCnaTopTen = (gcnew System::Windows::Forms::Button());
	this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
	this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
	this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
	this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
	this->grpBoxSearchCna = (gcnew System::Windows::Forms::GroupBox());
	this->searchTb2 = (gcnew System::Windows::Forms::TextBox());
	this->btnCnaSearch = (gcnew System::Windows::Forms::Button());
	this->btnCnaClear = (gcnew System::Windows::Forms::Button());
	this->btnCnaImport = (gcnew System::Windows::Forms::Button());
	this->btnCnaDisplay = (gcnew System::Windows::Forms::Button());
	this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
	this->cnaLabel1 = (gcnew System::Windows::Forms::Label());
	this->tabControl1->SuspendLayout();
	this->tabCrawler->SuspendLayout();
	this->grpBoxCrawler->SuspendLayout();
	this->tabPage2->SuspendLayout();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
	this->grpBoxSortTweet->SuspendLayout();
	this->grpBoxSearchTweet->SuspendLayout();
	this->tabPage3->SuspendLayout();
	this->grpBoxSortCna->SuspendLayout();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
	this->grpBoxSearchCna->SuspendLayout();
	this->SuspendLayout();
	// 
	// tabControl1
	// 
	this->tabControl1->Controls->Add(this->tabCrawler);
	this->tabControl1->Controls->Add(this->tabPage2);
	this->tabControl1->Controls->Add(this->tabPage3);
	this->tabControl1->Location = System::Drawing::Point(-1, -1);
	this->tabControl1->Margin = System::Windows::Forms::Padding(4);
	this->tabControl1->Name = L"tabControl1";
	this->tabControl1->SelectedIndex = 0;
	this->tabControl1->Size = System::Drawing::Size(1475, 794);
	this->tabControl1->TabIndex = 3;
	// 
	// tabCrawler
	// 
	this->tabCrawler->BackColor = System::Drawing::Color::LavenderBlush;
	this->tabCrawler->Controls->Add(this->grpBoxCrawler);
	this->tabCrawler->Location = System::Drawing::Point(4, 25);
	this->tabCrawler->Margin = System::Windows::Forms::Padding(4);
	this->tabCrawler->Name = L"tabCrawler";
	this->tabCrawler->Padding = System::Windows::Forms::Padding(4);
	this->tabCrawler->Size = System::Drawing::Size(1467, 765);
	this->tabCrawler->TabIndex = 0;
	this->tabCrawler->Text = L"Crawler";
	// 
	// grpBoxCrawler
	// 
	this->grpBoxCrawler->BackColor = System::Drawing::Color::White;
	this->grpBoxCrawler->Controls->Add(this->crawlBtn);
	this->grpBoxCrawler->Controls->Add(this->recordTb);
	this->grpBoxCrawler->Controls->Add(this->keywordTb);
	this->grpBoxCrawler->Controls->Add(this->crawlerLabel2);
	this->grpBoxCrawler->Controls->Add(this->crawlerLabel1);
	this->grpBoxCrawler->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->grpBoxCrawler->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
	this->grpBoxCrawler->Location = System::Drawing::Point(175, 94);
	this->grpBoxCrawler->Margin = System::Windows::Forms::Padding(4);
	this->grpBoxCrawler->Name = L"grpBoxCrawler";
	this->grpBoxCrawler->Padding = System::Windows::Forms::Padding(4);
	this->grpBoxCrawler->Size = System::Drawing::Size(1080, 532);
	this->grpBoxCrawler->TabIndex = 10;
	this->grpBoxCrawler->TabStop = false;
	this->grpBoxCrawler->Text = L"Twitter Crawl";
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
	// crawlerLabel2
	// 
	this->crawlerLabel2->AutoSize = true;
	this->crawlerLabel2->Location = System::Drawing::Point(303, 226);
	this->crawlerLabel2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
	this->crawlerLabel2->Name = L"crawlerLabel2";
	this->crawlerLabel2->Size = System::Drawing::Size(155, 25);
	this->crawlerLabel2->TabIndex = 8;
	this->crawlerLabel2->Text = L"No. of Records";
	// 
	// crawlerLabel1
	// 
	this->crawlerLabel1->AutoSize = true;
	this->crawlerLabel1->Location = System::Drawing::Point(363, 175);
	this->crawlerLabel1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
	this->crawlerLabel1->Name = L"crawlerLabel1";
	this->crawlerLabel1->Size = System::Drawing::Size(95, 25);
	this->crawlerLabel1->TabIndex = 7;
	this->crawlerLabel1->Text = L"Keyword";
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
	this->tabPage2->Controls->Add(this->twitterLabel1);
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
	// twitterLabel1
	// 
	this->twitterLabel1->AutoSize = true;
	this->twitterLabel1->BackColor = System::Drawing::Color::LightGray;
	this->twitterLabel1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->twitterLabel1->Location = System::Drawing::Point(4, 4);
	this->twitterLabel1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
	this->twitterLabel1->Name = L"twitterLabel1";
	this->twitterLabel1->Size = System::Drawing::Size(301, 32);
	this->twitterLabel1->TabIndex = 11;
	this->twitterLabel1->Text = L"Twitter Crawl Display";
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
	this->tabPage3->Controls->Add(this->grpBoxSortCna);
	this->tabPage3->Controls->Add(this->btnCnaTopTen);
	this->tabPage3->Controls->Add(this->dataGridView2);
	this->tabPage3->Controls->Add(this->grpBoxSearchCna);
	this->tabPage3->Controls->Add(this->btnCnaClear);
	this->tabPage3->Controls->Add(this->btnCnaImport);
	this->tabPage3->Controls->Add(this->btnCnaDisplay);
	this->tabPage3->Controls->Add(this->richTextBox2);
	this->tabPage3->Controls->Add(this->cnaLabel1);
	this->tabPage3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
	this->tabPage3->Location = System::Drawing::Point(4, 25);
	this->tabPage3->Margin = System::Windows::Forms::Padding(4);
	this->tabPage3->Name = L"tabPage3";
	this->tabPage3->Padding = System::Windows::Forms::Padding(4);
	this->tabPage3->Size = System::Drawing::Size(1467, 765);
	this->tabPage3->TabIndex = 2;
	this->tabPage3->Text = L"CNA";
	// 
	// grpBoxSortCna
	// 
	this->grpBoxSortCna->Controls->Add(this->comboBox1);
	this->grpBoxSortCna->Controls->Add(this->btnCnaSort);
	this->grpBoxSortCna->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->grpBoxSortCna->Location = System::Drawing::Point(1192, 38);
	this->grpBoxSortCna->Margin = System::Windows::Forms::Padding(4);
	this->grpBoxSortCna->Name = L"grpBoxSortCna";
	this->grpBoxSortCna->Padding = System::Windows::Forms::Padding(4);
	this->grpBoxSortCna->Size = System::Drawing::Size(267, 128);
	this->grpBoxSortCna->TabIndex = 4;
	this->grpBoxSortCna->TabStop = false;
	this->grpBoxSortCna->Text = L"Sort By";
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
	// grpBoxSearchCna
	// 
	this->grpBoxSearchCna->Controls->Add(this->searchTb2);
	this->grpBoxSearchCna->Controls->Add(this->btnCnaSearch);
	this->grpBoxSearchCna->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->grpBoxSearchCna->Location = System::Drawing::Point(1188, 174);
	this->grpBoxSearchCna->Margin = System::Windows::Forms::Padding(4);
	this->grpBoxSearchCna->Name = L"grpBoxSearchCna";
	this->grpBoxSearchCna->Padding = System::Windows::Forms::Padding(4);
	this->grpBoxSearchCna->Size = System::Drawing::Size(261, 100);
	this->grpBoxSearchCna->TabIndex = 5;
	this->grpBoxSearchCna->TabStop = false;
	this->grpBoxSearchCna->Text = L"Search by Keyword";
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
	// cnaLabel1
	// 
	this->cnaLabel1->AutoSize = true;
	this->cnaLabel1->BackColor = System::Drawing::Color::LightGray;
	this->cnaLabel1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->cnaLabel1->Location = System::Drawing::Point(4, 4);
	this->cnaLabel1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
	this->cnaLabel1->Name = L"cnaLabel1";
	this->cnaLabel1->Size = System::Drawing::Size(271, 32);
	this->cnaLabel1->TabIndex = 0;
	this->cnaLabel1->Text = L"CNA Crawl Display";
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
	this->tabCrawler->ResumeLayout(false);
	this->grpBoxCrawler->ResumeLayout(false);
	this->grpBoxCrawler->PerformLayout();
	this->tabPage2->ResumeLayout(false);
	this->tabPage2->PerformLayout();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
	this->grpBoxSortTweet->ResumeLayout(false);
	this->grpBoxSearchTweet->ResumeLayout(false);
	this->grpBoxSearchTweet->PerformLayout();
	this->tabPage3->ResumeLayout(false);
	this->tabPage3->PerformLayout();
	this->grpBoxSortCna->ResumeLayout(false);
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
	this->grpBoxSearchCna->ResumeLayout(false);
	this->grpBoxSearchCna->PerformLayout();
	this->ResumeLayout(false);

}
/*END OF Creating all GUI components*/

//Global Var
bool plsimporttweet = 0;//check for import csv twiiter
bool plsimportcna = 0;//check for import csv cna


/*-----------------------------------------------Crawler Buttons-------------------------------------------*/

/*BUTTONS for Crawling*/
System::Void CPPProject1009Gui::GUI::crawlBtn_Click(System::Object^ sender, System::EventArgs^ e)
{
	//Keywords
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
		try {
			twitterCrawler.crawlerJsonToFile();
			MessageBox::Show("Successfully Crawled and Saved to File", "Successful: ");
		}
		catch (string msg) {
			System::String^ error_msg = gcnew String(msg.c_str());
			MessageBox::Show(error_msg, "Error: ");
		}
	}
}
/*END OF BUTTONS for Crawling*/


/*-----------------------------------------------Twitter Buttons-------------------------------------------*/

/*BUTTONS for Importing CSV File*/
System::Void CPPProject1009Gui::GUI::btnTweetImport_Click(System::Object^ sender, System::EventArgs^ e)
{
		OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;

	openFileDialog1->InitialDirectory = "C:\\Users\\lim_j\\Documents\\GitHub\\ICT1009CPP\\ICT1009CPP\\";
	openFileDialog1->RestoreDirectory = true;

	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		System::String^ filepath = System::IO::Path::GetFileName(openFileDialog1->FileName);
		std::string filename = marshal_as<std::string>(filepath);

		//create a Twitter object
		Twitter TWITTER;
		TWITTER.set_csvfilepath(filename);// use stadard string
		try {
			TWITTER.readTwitterData(filename);
			MessageBox::Show("Successfully Load " + filepath, "FilePath:");//use system strig
			plsimporttweet = 1;
		}
		catch (string msg) {
			System::String^ error_msg = gcnew String(msg.c_str());
			MessageBox::Show(error_msg, "Error: ");
		}
	}
}
/*END OF BUTTONS for Importing CSV File*/

/*DISPLAY CSV BUTTON*/
System::Void CPPProject1009Gui::GUI::btnTweetDisplay_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (plsimporttweet == 0)
	{
		MessageBox::Show("Please Import CSV", "Error: ");
	}
	else
	{
		for (int j = 0; j < twitter.size(); ++j)
		{
			dataGridView1->Rows->Add(
				marshal_as<String^>(twitter[j].getUserId()),
				marshal_as<String^>(twitter[j].getDate()),
				marshal_as<String^>(twitter[j].getPost()));
		}
	}
}
/*END OF DISPLAY CSV BUTTON*/

/*Twitter Search keyword BUTTON*/
System::Void CPPProject1009Gui::GUI::btnTweetSearch_Click(System::Object^ sender, System::EventArgs^ e)
{
	//create Twitter object
	Twitter TWITTER;

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
		btnTweetClear_Click(sender, e);
		search = searchTb->Text;//Get Keyword from TexBox

		std::string searchword = marshal_as<std::string>(search);//change to stadard string

		std::vector<Twitter> filtered;
		filtered = TWITTER.searchKeyword<Twitter>(searchword, filtered, twitter);

		if (filtered.empty())
		{
			MessageBox::Show("No Records " + search + " Found!", "Error:");
		}
		else {
			for (int j = 0; j < filtered.size(); ++j)
			{
				dataGridView1->Rows->Add(
					marshal_as<String^>(filtered[j].getUserId()),
					marshal_as<String^>(filtered[j].getDate()),
					marshal_as<String^>(filtered[j].getPost()));
			}
			MessageBox::Show("Keyword Record " + search + " found!", "Keyword Found");
		}
	}

}
/*End of Twitter Search keyword BUTTON*/

/*clear BUTTON*/
System::Void CPPProject1009Gui::GUI::btnTweetClear_Click(System::Object^ sender, System::EventArgs^ e)
{
	richTextBox1->Text = "";
	dataGridView1->Rows->Clear();
}
/*End of clear BUTTON*/

/*top ten BUTTON*/
System::Void CPPProject1009Gui::GUI::btnTweetTopTen_Click(System::Object^ sender, System::EventArgs^ e)
{	
	//create Twitter Object
	Twitter TWITTER;

	if (plsimporttweet == 0)
	{
		MessageBox::Show("Please Import CSV", "Error: ");
	}
	else {
		vector<pair<string, int> > wordvector;
		wordvector = TWITTER.top10WordTopics(twitter);
		for (int i = 0; i < wordvector.size(); ++i)
		{
			richTextBox1->Text += marshal_as<String^>(wordvector[i].first) +
				" = " +
				marshal_as<String^>(to_string(wordvector[i].second)) + "\r";
		}
	}
}
/*End of top ten BUTTON*/

/*Twitter Sort BUTTON*/
System::Void CPPProject1009Gui::GUI::btnTweetSort_Click(System::Object^ sender, System::EventArgs^ e)
{
	//create Twitter object
	Twitter TWITTER;
	if (plsimporttweet == 0)
	{
		MessageBox::Show("Please Import CSV", "Error: ");
	}
	else if (comboBox2->Text == "Sort ascending order by username")
	{
		btnTweetClear_Click(sender, e);
		// function sort userid ascending
		sort(twitter.begin(), twitter.end(), TWITTER.userid_asc);
	}
	else if (comboBox2->Text == "Sort descending order by username")
	{
		btnTweetClear_Click(sender, e);
		// function sort userid descending	
		sort(twitter.begin(), twitter.end(), TWITTER.userid_desc);
	}
	else if (comboBox2->Text == "Sort ascending order by post")
	{
		btnTweetClear_Click(sender, e);
		// function sort post ascending	
		sort(twitter.begin(), twitter.end(), TWITTER.post_asc);
	}
	else if (comboBox2->Text == "Sort descending order by post")
	{
		btnTweetClear_Click(sender, e);
		// function sort post descending
		sort(twitter.begin(), twitter.end(), TWITTER.post_desc);
	}
	else
	{
		MessageBox::Show("Please input Keyword to sort!", "Error:");
	}
	for (int i = 0; i < twitter.size(); ++i)
	{
		dataGridView1->Rows->Add(
			marshal_as<String^>(twitter[i].getUserId()),
			marshal_as<String^>(twitter[i].getDate()),
			marshal_as<String^>(twitter[i].getPost()));
	}
}
/*End of top ten BUTTON*/


/*-----------------------------------------------CNA Buttons-------------------------------------------*/

/*CNA Search by keyword*/
System::Void CPPProject1009Gui::GUI::btnCnaSearch_Click(System::Object^ sender, System::EventArgs^ e)
{
	//create Cna object
	Cna CNA;
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
		btnCnaClear_Click(sender, e);
		search = searchTb2->Text;//Get Keyword from TexBox

		std::string searchword = marshal_as<std::string>(search);//change to stadard string

		std::vector<Cna> filtered;
		filtered = CNA.searchKeyword<Cna>(searchword, filtered, cna);//function

		if (filtered.empty())
		{
			MessageBox::Show("No Records " + search + " Found!", "Error:");
		}
		else {
			for (int j = 0; j < filtered.size(); ++j)
			{
				dataGridView2->Rows->Add(
					marshal_as<String^>(filtered[j].getUserId()),
					marshal_as<String^>(filtered[j].getDate()),
					marshal_as<String^>(filtered[j].getPost()));
			}
			MessageBox::Show("Keyword Record " + search + " found!", "Keyword Found");
		}
	}

}
/*END of CNA Search by keyword*/

/*Display CNA CSV*/
System::Void CPPProject1009Gui::GUI::btnCnaDisplay_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (plsimportcna == 0)
	{
		MessageBox::Show("Please Import CSV", "Error: ");
	}
	else
	{
		for (int j = 0; j < cna.size(); ++j)
		{
			dataGridView2->Rows->Add(
				marshal_as<String^>(cna[j].getUserId()),
				marshal_as<String^>(cna[j].getDate()),
				marshal_as<String^>(cna[j].getPost()));
		}
	}

}
/*END Display CNA CSV*/

/*Loading CNA CSV*/
System::Void CPPProject1009Gui::GUI::btnCnaImport_Click(System::Object^ sender, System::EventArgs^ e)
{
	OpenFileDialog^ openFileDialog2 = gcnew OpenFileDialog;

	openFileDialog2->InitialDirectory = "C:\\Users\\lim_j\\Documents\\GitHub\\ICT1009CPP\\ICT1009CPP\\";
	openFileDialog2->RestoreDirectory = true;

	if (openFileDialog2->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		System::String^ filepath = System::IO::Path::GetFileName(openFileDialog2->FileName);
		std::string filename = marshal_as<std::string>(filepath);

		//create Cna object
		Cna CNA;

		try {
			CNA.readCnaData(filename);
			MessageBox::Show("Successfully Load " + filepath, "FilePath:");//use system strig
			plsimportcna = 1;
		}
		catch (string msg) {
			System::String^ error_msg = gcnew String(msg.c_str());
			MessageBox::Show(error_msg, "Error: ");
		}
		
	}
}
/*End of Loading CNA CSV*/

/*Clear Display Button*/
System::Void CPPProject1009Gui::GUI::btnCnaClear_Click(System::Object^ sender, System::EventArgs^ e)
{
	richTextBox2->Text = "";
	dataGridView2->Rows->Clear();
}
/* End of Clear Button*/

/*CNA top ten button*/
System::Void CPPProject1009Gui::GUI::btnCnaTopTen_Click(System::Object^ sender, System::EventArgs^ e)
{
	//create Cna object
	Cna CNA;

	if (plsimportcna == 0)
	{
		MessageBox::Show("Please Import CSV", "Error: ");
	}
	else {
		vector<pair<string, int> > wordvector;
		wordvector = CNA.top10WordTopics(cna);
		for (int i = 0; i < wordvector.size(); ++i)
		{
			richTextBox2->Text += marshal_as<String^>(wordvector[i].first) +
				" = " +
				marshal_as<String^>(to_string(wordvector[i].second)) + "\r";
		}
	}
}
/*End of top ten BUTTON*/

/*CNA Sort BUTTON*/
System::Void CPPProject1009Gui::GUI::btnCnaSort_Click(System::Object^ sender, System::EventArgs^ e)
{
	//create Cna object
	Cna CNA;

	if (plsimportcna == 0)
	{
		MessageBox::Show("Please Import CSV", "Error: ");
	}
	else if (comboBox1->Text == "Sort ascending order by source")
	{
		btnCnaClear_Click(sender, e);
		// function sort userid ascending
		sort(cna.begin(), cna.end(), CNA.source_asc_cna);
	}
	else if (comboBox1->Text == "Sort descending order by source")
	{
		btnCnaClear_Click(sender, e);
		// function sort userid descending	
		sort(cna.begin(), cna.end(), CNA.source_desc_cna);
	}
	else if (comboBox1->Text == "Sort ascending order by headline")
	{
		btnCnaClear_Click(sender, e);
		// function sort post ascending	
		sort(cna.begin(), cna.end(), CNA.post_asc_cna);
	}
	else if (comboBox1->Text == "Sort descending order by headline")
	{
		btnCnaClear_Click(sender, e);
		// function sort post descending
		sort(cna.begin(), cna.end(), CNA.post_desc_cna);
	}
	else
	{
		MessageBox::Show("Please input Keyword to sort!", "Error:");
	}
	for (int i = 0; i < cna.size(); ++i)
	{
		dataGridView2->Rows->Add(
			marshal_as<String^>(cna[i].getUserId()),
			marshal_as<String^>(cna[i].getDate()),
			marshal_as<String^>(cna[i].getPost()));
	}

}
/*End of CNA Sort BUTTON*/