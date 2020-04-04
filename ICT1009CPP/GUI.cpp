#include "GUI.h"
#include "Crawler.h"
#include "twitter.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(cli::array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	CPPProject1009Gui::GUI form;
	Application::Run(% form);

}

//Global Var
bool plsimporttweet = 0;//check for impor csv twiiter
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
		twitterCrawler.crawlerJsonToFile();

		MessageBox::Show("Successfully Crawled and Saved to File");
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
		TWITTER.readTwitterData(filename);
		MessageBox::Show("Successfully Load " + filepath, "FilePath:");//use system strig
		plsimporttweet = 1;
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

		CNA.readCnaData(filename);
		MessageBox::Show("Successfully Load " + filepath, "FilePath:");//use system strig
		plsimportcna = 1;
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