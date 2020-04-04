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
	string pathname1 = gg;
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
	getline(f, nth);
	while (f.peek() != EOF) {
		getline(f, dateTime, ',');
		getline(f, userid, ',');
		getline(f, post, '\n');
		/**
		newDateTime = dateTime.c_str();
		sscanf(newDateTime,	 "%a %b %d %H:%M:%S %z %Y", &day, &mth, &date, &hh, &mm, &ss, &z, &year);
		tm.tm_year = year - 1900;
		tm.tm_wday = day;
		tm.tm_mon = mth - 1;
		tm.tm_mday = date;
		tm.tm_hour = hh;
		tm.tm_min = mm;
		tm.tm_sec = ss;
		newTime = mktime(&tm);
		*/

		//remove colon from display
		regex regexCollon("[\"]");
		post = regex_replace(post, regexCollon, "");
		userid = regex_replace(userid, regexCollon, "");
		dateTime = regex_replace(dateTime, regexCollon, "");

		temp.storeData(dateTime, userid, post);
		twitter.push_back(temp);
	}
}