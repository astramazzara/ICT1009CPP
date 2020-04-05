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

/*Twitter Class inherits from DataModel*/
class Twitter : public DataModel {
public:
	//-------------- Twitter Sort by Assc or Dese ----------------//
	/*Twitter struct*/
	struct userid_asc
	{

		inline bool operator() (Twitter& x, Twitter& y) {
			return x.getUserId() < y.getUserId();
		}
	}userid_asc;
	struct userid_desc
	{

		inline bool operator() (Twitter& x, Twitter& y) {
			return x.getUserId() > y.getUserId();
		}
	}userid_desc;
	struct post_asc
	{

		inline bool operator() (Twitter& x, Twitter& y) {
			return x.getPost() < y.getPost();
		}
	}post_asc;
	struct post_desc
	{

		inline bool operator() (Twitter& x, Twitter& y) {
			return x.getPost() > y.getPost();
		}
	}post_desc;

	/*Twitter Read CSV
	Twitter child Function*/
	void readTwitterData(string gg);

};

/*GLOBAL VARIABLES - vector twitterData Class*/
vector <Twitter> twitter;

// ----------------------------------------------------------------- Twitter.cpp ------------------------------------------------------------------ //
/*Twitter Read CSV
Twitter child Function*/
void Twitter::readTwitterData(string gg) {
	// declare variables
	string pathname1 = gg; // file path that is gg to be read
	string dateTime;
	const char* newDateTime;
	time_t newTime;
	string userid;
	string post;
	string nth;
	int day, date, mth, z, hh, mm, ss, year;
	struct tm tm;
	Twitter temp;			 // temporary store data before adding to vector twitter
	ifstream f(pathname1);
	getline(f, nth); // check header row
	int found = nth.find("Created By"); // check if header row contains 'created by' or it will reject file
	if (found != string::npos)
	{
		while (f.peek() != EOF) {
			getline(f, dateTime, ',');
			getline(f, userid, ',');
			getline(f, post, '\n');

			//remove colon from display
			regex regexCollon("[\"]");
			post = regex_replace(post, regexCollon, "");
			userid = regex_replace(userid, regexCollon, "");
			dateTime = regex_replace(dateTime, regexCollon, "");

			temp.storeData(dateTime, userid, post); // call function to store into twitterdata class
			twitter.push_back(temp); // push to vector
		}
	}
	else {
		// if header row does not contain created by, it will return error.
		cout << "File selected contains the wrong data format" << endl;
		const string ERROR_MSG = "File selected contains the wrong data format";
		throw(ERROR_MSG);
	}
}