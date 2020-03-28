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


class twitterData {
private:
	string dateTime;
	string userid;
	string post;
	string filepath;
	string t_keyword;
public:
	
	twitterData() { dateTime = ""; userid = ""; post = ""; }
	twitterData(string new_dateTime, string new_userid, string new_post);
	void storeData(string new_dateTime, string new_userid, string new_post);
	string getDate() { return dateTime; }
	string getUserId() { return userid; }
	string getPost() { return post; }

	void set_csvfilepath(string);//for filepath from gui
	string get_csvfilepath() {  return filepath; }
	
};
/*set filepath from gui*/
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

typedef map<string, int> word_count_list;

struct val_morethan
{
	inline bool operator() (const pair<string, int>& x, const pair<string, int>& y) const
	{
		return x.second > y.second;
	}
}val_lt;

struct userid_asc
{

	inline bool operator() (twitterData& x, twitterData& y) {
		return x.getUserId() < y.getUserId();
	}
}userid_asc;

struct userid_desc
{

	inline bool operator() (twitterData& x, twitterData& y) {
		return x.getUserId() > y.getUserId();
	}
}userid_desc;

struct post_asc
{

	inline bool operator() (twitterData& x, twitterData& y) {
		return x.getPost() < y.getPost();
	}
}post_asc;

struct post_desc
{

	inline bool operator() (twitterData& x, twitterData& y) {
		return x.getPost() > y.getPost();
	}
}post_desc;

//----------------------------------------------- DEFINE GLOBAL VARIABLES -----------------------------------------------//
vector <twitterData> twitter; // store twitter data in an array
twitterData temp;			 // temporary store data before adding to vector twitter
int size = 0;				  // define size of data

//----------------------------------------------- READ DATA FROM CSV -----------------------------------------------//
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
		temp.storeData(dateTime, userid, post);
		twitter.push_back(temp);
		::size++;
		
	}
}


// ----------------------------------------------- SEARCH KEYWORDS ----------------------------------------------- //
vector<twitterData> searchKeyword(string key) {
	int j = 0;
	vector<twitterData> filtered;
	size_t found;
	string str;
	for (int i = 0; i < ::size; ++i) {
		str = twitter[i].getPost();
		for_each(str.begin(), str.end(), [](char& c) {
			c = ::tolower(c);
			});
		found = str.find(key);
		if (found != string::npos)
		{
			temp.storeData(twitter[j].getDate(), twitter[j].getUserId(), twitter[j].getPost());
			filtered.push_back(temp);
			j++;
		}
	}
	return filtered;
}

// ----------------------------------------------- TOP 10 COMMON WORDS USED ----------------------------------------------- //
vector<pair<string, int>> top10WordTopics() {
	string line;
	string intermediate;
	vector<string> words;
	word_count_list word_count;
	for (int i = 0; i < ::size; i++) {
		line = twitter[i].getPost();
		stringstream check1(line);
		while (getline(check1, intermediate, ' ')) {
			words.push_back(intermediate);
		}
	}

	for (int i = 0; i < words.size(); i++) {
		line = words[i];
		// Remove punctuation.
		int index;
		while ((index = line.find_first_of(".,!?\\;-*+")) != string::npos)
			line.erase(index, 1);

		++word_count[line];
	}
	//copy pairs to vector
	vector<pair<string, int> > wordvector;
	vector<pair<string, int> > wordvector10;
	copy(word_count.begin(), word_count.end(), back_inserter(wordvector));
	//sort the vector by second (value) instead of key
	sort(wordvector.begin(), wordvector.end(), val_lt);
	for (int i = 0; i < 10; i++)
		wordvector10.push_back(wordvector[i]);
	return wordvector10; // return key value pair of limit 10 
}



