#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

class twitterData {
private:
	string dateTime;
	string userid;
	string post;
public:
	twitterData() { dateTime = ""; userid = ""; post = ""; }
	twitterData(string new_dateTime, string new_userid, string new_post);
	void storeData(string new_dateTime, string new_userid, string new_post);
	string getDate() { return dateTime; }
	string getUserId() { return userid; }
	string getPost() { return post; }
};

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
