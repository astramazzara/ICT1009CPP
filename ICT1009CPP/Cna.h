#pragma once

#include "DataModel.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <ctime>
#include <iomanip>
#include <string>
#include <regex>
#include <functional>

using namespace std;

/*CNA Class inherits from DataModel*/
class Cna : public DataModel {
public:
	//-------------- CNA Sort by Assc or Dese ----------------//
	/*cna struct*/
	struct source_asc_cna
	{

		inline bool operator() (Cna& x, Cna& y) {
			return x.getUserId() < y.getUserId();
		}
	}source_asc_cna;
	struct source_desc_cna
	{

		inline bool operator() (Cna& x, Cna& y) {
			return x.getUserId() > y.getUserId();
		}
	}source_desc_cna;
	struct post_asc_cna {
		inline bool operator() (Cna& x, Cna& y) {
			return x.getPost() < y.getPost();
		}
	}post_asc_cna;
	struct post_desc_cna {
		inline bool operator() (Cna& x, Cna& y) {
			return x.getPost() > y.getPost();
		}
	}post_desc_cna;

	/*CNA Read CSV
	CNA child function*/
	void readCnaData(string);
};

/*GLOBAL VARIABLES - vector CNA Class*/
vector <Cna> cna;

/*CNA Read CSV
CNA child function*/
void Cna::readCnaData(string gg) {
	string pathname1 = gg;
	string dateTime;
	const char* newDateTime;
	time_t newTime;
	string author;
	string title;
	string source;
	string nth;
	int day, date, mth, z, hh, mm, ss, year;
	struct tm tm;
	Cna temp;			 // temporary store data before adding to vector cna
	ifstream f(pathname1);
	getline(f, nth, '\n');
	int found = nth.find("Title");
	if (found != string::npos)
	{
		while (f.peek() != EOF) {
			getline(f, title, ',');
			getline(f, dateTime, ',');
			getline(f, source, ',');
			getline(f, author, '\n');
			temp.storeData(dateTime, author, title);
			cna.push_back(temp);
		}
	}
	else {
		// if header row does not contain created by, it will return error.
		cout << "File selected contains the wrong data format" << endl;
		const string ERROR_MSG = "File selected contains the wrong data format";
		throw(ERROR_MSG);
	}
}