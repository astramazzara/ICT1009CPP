#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <iomanip>
#include "twitter.h"
using namespace std;

// global variables
twitterData twitter[100]; // store twitter data in an array
int size = 0;				  // define size of data
void readData() {
	string dateTime;
	const char* newDateTime;
	time_t newTime;
	string userid;
	string post;
	string nth;
	int day, date, mth, z, hh, mm, ss, year;
	struct tm tm;
	ifstream f("TwitterData.csv");
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
		twitter[::size].storeData(dateTime, userid, post);
		::size++;
		//cout << "Date Time: " << newTime << endl;
	}
}
int main() {
	readData();
	for (int i = 0; i < ::size; ++i) {
		cout << "Date Time: " << twitter[i].getDate() << endl;
		cout << "Username: " << twitter[i].getUserId() << endl;
		cout << "Tweet Post: " << twitter[i].getPost() << endl;
	}
	cout << ::size;

}