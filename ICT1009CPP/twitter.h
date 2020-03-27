#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <ctime>
#include <iomanip>


//#include "twitter.h"
using namespace std;


//using namespace std;

class twitterData {
private:
	string dateTime;
	string userid;
	string post;
	string filepath;
public:
	
	void set_csvfilepath(string);//for filepath from gui
	twitterData() { dateTime = ""; userid = ""; post = ""; }
	twitterData(string new_dateTime, string new_userid, string new_post);
	void storeData(string new_dateTime, string new_userid, string new_post);
	string getDate() { return dateTime; }
	string getUserId() { return userid; }
	string getPost() { return post; }
	string get_csvfilepath() {  return filepath; }
	//int readData();
};
//set filepath from gui
void twitterData::set_csvfilepath(string path) 
{
	filepath = path;
	
}

twitterData::twitterData(string new_dateTime, string new_userid, string new_post) {
	dateTime = new_dateTime;
	userid = new_userid;
	post = new_post;
}
void twitterData::storeData(string new_dateTime, string new_userid, string new_post) {
	dateTime = new_dateTime;
	userid = new_userid;
	post = new_post;
}
/*
int twitterData::readData() {
	//*************RE-POSITION FROM GLOBAL****************
	twitterData twitter[100];
	string dateTime;
	const char* newDateTime;
	time_t newTime;
	string userid;
	string post;
	string nth;
	
	int i = 0;
	int day, date, mth, z, hh, mm, ss, year;
	struct tm tm;
	
	ifstream f(get_csvfilepath());
	
	getline(f, nth);
	while (f.peek() != EOF) {
		getline(f, dateTime, ',');
		getline(f, userid, ',');
		getline(f, post, '\n');
		
		twitter[i].storeData(dateTime, userid, post);
		i++;
		
	}
	return i;
}*/

/*int main() {
	int size = 0;
	size = readData();
	for (int i = 0; i < size; ++i) {
		cout << "Date Time: " << twitter[i].getDate() << endl;
		cout << "Username: " << twitter[i].getUserId() << endl;
		cout << "Tweet Post: " << twitter[i].getPost() << endl;
	}

}*/