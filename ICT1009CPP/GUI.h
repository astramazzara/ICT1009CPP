#pragma once

#include "Crawler.h"
#include "Twitter.h"
#include "Cna.h"

#include <string>
#include <msclr\marshal_cppstd.h>
#include <filesystem>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <ctime>
#include <algorithm>
#include <map>


namespace fs = std::filesystem;
using namespace System;
using namespace std;
using namespace msclr::interop;

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
			/*Creates all GUI components*/
			InitializeComponent();
		}

	protected:
		/*Clean up any resources being used*/
		~GUI()
		{
			if (components)
			{
				delete components;
			}
		}

	//main
	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::TabControl^ tabControl1;

	//crawler tab
	private: System::Windows::Forms::TabPage^ tabCrawler;
	private: System::Windows::Forms::GroupBox^ grpBoxCrawler;
	private: System::Windows::Forms::Label^ crawlerLabel1;
	private: System::Windows::Forms::Label^ crawlerLabel2;
	private: System::Windows::Forms::TextBox^ keywordTb;
	private: System::Windows::Forms::TextBox^ recordTb;
	private: System::Windows::Forms::Button^ crawlBtn;

	//twitter tab
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::Label^ twitterLabel1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::Button^ btnTweetSearch;
	private: System::Windows::Forms::Button^ btnTweetImport;
	private: System::Windows::Forms::Button^ btnTweetClear;
	private: System::Windows::Forms::Button^ btnTweetDisplay;
	private: System::Windows::Forms::Button^ btnTweetTopTen;
	private: System::Windows::Forms::Button^ btnTweetSort;
	private: System::Windows::Forms::GroupBox^ grpBoxSortTweet;
	private: System::Windows::Forms::GroupBox^ grpBoxSearchTweet;
	private: System::Windows::Forms::TextBox^ searchTb;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::ComboBox^ comboBox1;

	//cna tab
	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column6;
	private: System::Windows::Forms::Button^ btnCnaSearch;
	private: System::Windows::Forms::Button^ btnCnaSort;
	private: System::Windows::Forms::Button^ btnCnaImport;
	private: System::Windows::Forms::Button^ btnCnaDisplay;
	private: System::Windows::Forms::Button^ btnCnaClear;
	private: System::Windows::Forms::Button^ btnCnaTopTen;
	private: System::Windows::Forms::TextBox^ searchTb2;
	private: System::Windows::Forms::RichTextBox^ richTextBox2;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::Label^ cnaLabel1;
	private: System::Windows::Forms::GroupBox^ grpBoxSortCna;
	private: System::Windows::Forms::GroupBox^ grpBoxSearchCna;

#pragma region Windows Form Designer generated code
		/*Creates all GUI components*/
		void InitializeComponent(void);
#pragma endregion
	
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