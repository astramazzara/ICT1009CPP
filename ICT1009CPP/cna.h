#include <iostream>
#include "rapidjson/document.h"
#include <cpr/cpr.h>
#include <fstream>
#include <string>
#include <Windows.h>


using namespace rapidjson;
using namespace std;
using namespace cpr;

class CNA {
private:
	string title;
	string date;
public:
	void setTitle(string);
	void setdate(string);
	void createCSV(vector<CNA>);
	string getTitle();
	string getdate();
};

void CNA::setTitle(string input)
{
	this->title = input;
}

void CNA::setdate(string input)
{
	this->date = input;
}

string CNA::getTitle()
{
	return this->title;
}

string CNA::getdate()
{
	return this->date;
}


void CNA::createCSV(vector<CNA> cna)
{
	ofstream output;
	output.open("export.csv");
	const char* bom = "\xef\xbb\xbf";
	output << bom;
	output << "Title,date" << endl;
	for (int i = 0; i < cna.size(); i++) {
		title = cna[i].getTitle();
		for (int j = 0; j < title.length(); ++j) {
			//Prevent separation of columns by replacing commas with semicommas
			if (title[j] == ',') {
				title[j] = ';';
			}
		}
		output << title << ",";
		output << cna[i].getdate() << "," << endl;

	}
	output.close();
}
