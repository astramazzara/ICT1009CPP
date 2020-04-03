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

//Twitter Class
class twitterData {
protected:
	string dateTime;
	string userid;
	string post;
	string filepath;
	string t_keyword;
public:

	twitterData() { dateTime = ""; userid = ""; post = ""; }
	twitterData(string new_dateTime, string new_userid, string new_post);
	void storeData(string new_dateTime, string new_userid, string new_post);// USED for both CNA Twitter
	string getDate() { return dateTime; }
	string getUserId() { return userid; }
	string getPost() { return post; }

	void set_csvfilepath(string);//for filepath from gui
	string get_csvfilepath() { return filepath; }

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

//CNA Class
class CNA : virtual public twitterData {

};

//----------------------------------------------- Twitter Sort by Assc or Dese -----------------------------------------------//
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
/*GLOBAL VARIABLES - vector twitterData Class*/
vector <twitterData> twitter; // store twitter data in an array
//twitterData temp;			 // temporary store data before adding to vector twitter
/*GLOBAL VARIABLES - vector CNA Class*/
vector <CNA> cna;
//CNA tempcna;
//int size = 0;				  // define size of data

//----------------------------------------------- READ DATA FROM CSV -----------------------------------------------//
//Twitter Read CSV
void readData(string gg) {
	string pathname1 = gg;
	string dateTime;
	const char* newDateTime;
	time_t newTime;
	string userid;
	string post;
	string nth;
	int day, date, mth, z, hh, mm, ss, year;
	struct tm tm;
	twitterData temp;			 // temporary store data before adding to vector twitter
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
		//::size++;

	}
}

//CNA Read CSV
void readCNAData(string gg) {
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
	CNA temp;			 // temporary store data before adding to vector cna
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
			//::size++;
		}
	}
	else {
		cout << "Error File Format" << endl;
	}
}


// ----------------------------------------------- SEARCH KEYWORDS ----------------------------------------------- //
/*OLD SEARCH!!!!!!*/
/*vector<twitterData> searchKeyword(string key) {
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
}*/
// ----------------------------------------------- CNA SEARCH KEYWORDS ----------------------------------------------- //
///*OLD NEW SEARCH!!!!!!*/
//vector<CNA> searchKeywordcna(string key) {
//	vector<CNA> filtered;
//	int found;
//	string str;
//	for (int i = 0; i < cna.size(); ++i) {
//		str = cna[i].getPost();
//		for_each(str.begin(), str.end(), [](char& c) {
//			c = ::tolower(c);
//			});
//		found = str.find(key);
//		if (found != string::npos)
//		{
//			tempcna.storeData(cna[i].getDate(), cna[i].getUserId(), cna[i].getPost());
//			filtered.push_back(tempcna);
//		}
//	}
//	if (filtered.empty()) {
//		cout << "No such records!" << endl;
//	}
//	return filtered;
//}
//
//
//// ----------------------------------------------- Twitter SEARCH KEYWORDS ----------------------------------------------- //
///*OLD NEW SEARCH!!!!!!*/
//vector<twitterData> searchKeyword(string key) {
//
//	vector<twitterData> filtered;
//	int found;
//	string str;
//	for (int i = 0; i < ::size; ++i) {
//		str = twitter[i].getPost();
//		for_each(str.begin(), str.end(), [](char& c) {
//			c = ::tolower(c);
//			});
//		found = str.find(key);
//		if (found != string::npos)
//		{
//			temp.storeData(twitter[i].getDate(), twitter[i].getUserId(), twitter[i].getPost());
//			filtered.push_back(temp);
//		}
//	}
//	if (filtered.empty()) {
//		cout << "No such records!" << endl;
//	}
//	return filtered;
//}

// ----------------------------------------------- SEARCH KEYWORDS USING TEMPLATE ------------------------------------------- //
/*SEARCH KEYWORD USING TEMPLATE*/
template<typename dataSrcType>
typename vector<dataSrcType> searchKeyword(string key, vector<dataSrcType> &vect, vector<dataSrcType> &dataSource) {
	//convert search key to lowercase
	for_each(key.begin(), key.end(), [](char& c) {
		c = ::tolower(c);
		});

	dataSrcType temp;			 // temporary store data before adding to vector twitter OR cna

	int found;
	string str;
	for (int i = 0; i < dataSource.size(); ++i) {
		str = dataSource[i].getPost();
		for_each(str.begin(), str.end(), [](char& c) {
			c = ::tolower(c);
			});
		found = str.find(key);
		if (found != string::npos)
		{
			temp.storeData(dataSource[i].getDate(), dataSource[i].getUserId(), dataSource[i].getPost());
			vect.push_back(temp);
		}
	}
	if (vect.empty()) {
		cout << "No such records!" << endl;
	}
	return vect;
}

// ----------------------------------------------- Clean Text ----------------------------------------------- //
/*recursive function to find and erase substring
Input: vector<string>:commonWord, vector<string>:vstrings
Output: vector<string>:commonWord, vector<string>:vstrings*/
vector<string> eraseSubstring(vector<string> commonWord, vector<string> vstrings)
{
	//loop through all words
	for (int j = 0; j < vstrings.size(); j++)
	{
		//loop through commonWord.txt file to match common words
		for (int k = 0; k < commonWord.size(); k++)
		{
			if (vstrings[j] == commonWord[k]) {
				//get index found it std::vector<string>::iterator
				vector<string>::iterator foundIndex = find(vstrings.begin(), vstrings.end(), vstrings[j]);
				//get index found in int
				int indexX = distance(vstrings.begin(), find(vstrings.begin(), vstrings.end(), vstrings[j]));
				//do not erese if out of range
				if (indexX < vstrings.size()) {
					vstrings.erase(foundIndex);
					return eraseSubstring(commonWord, vstrings);
				}
			}
		}
	}
	return commonWord, vstrings;
}

/*clean Text function entry point and calls for eraseSubstring
Input: string:strText
Output: string:strText*/
string deepCleanText(string strText) {
	// convert string to lower case
	for_each(strText.begin(), strText.end(), [](char& c) {
		c = ::tolower(c);
		});

	// remove Non-Ascii chars
	regex regexNonAscii("[^\\x00-\\x7F]");
	strText = regex_replace(strText, regexNonAscii, "");

	// Remove punctuation
	replace_if(strText.begin(), strText.end(),
		[](const char& c) { return std::ispunct(c); }, ' ');

	// further cleaning using regex
	regex regexAllowAlphabetsOnly("[^a-zA-Z\\s:]");
	regex regexMultiSpace("[\\s]+");
	regex regexLeadSpaces("^\\s+");
	regex regexTrailSpaces("\\s+$");

	strText = regex_replace(strText, regexAllowAlphabetsOnly, "");
	strText = regex_replace(strText, regexMultiSpace, " ");
	strText = regex_replace(strText, regexLeadSpaces, "");
	strText = regex_replace(strText, regexTrailSpaces, "");

	//load commonWords from .txt file to vector
	string tmpWord;
	vector<string> commonWord;

	//read common word from txt file
	ifstream f("commonWords.txt");
	while (f.peek() != EOF) {
		getline(f, tmpWord, '\n');
		//add to vector
		commonWord.push_back(tmpWord);
	}

	//convert string to vector string
	stringstream ss(strText);
	istream_iterator<string> begin(ss);
	istream_iterator<string> end;
	vector<string> vstrings(begin, end);

	//call recursive function to erase substring
	//cuz vector size changes after every erase; to prevent out of range
	commonWord, vstrings = eraseSubstring(commonWord, vstrings);

	//store back to strText
	strText = "";
	for (vector<string>::const_iterator i = vstrings.begin(); i != vstrings.end(); ++i)
		strText += *i + " ";

	cout << strText << endl << endl;
	return strText;
}

// ----------------------------------------------- TOP 10 COMMON WORDS USED ----------------------------------------------- //
/*TOP 10 COMMON WORDS USED
Input: vector Data Source
Output: vector with key and value pair for top 10 frequently appeared words*/
template<typename dataSrcType>
vector<pair<string, int>> top10WordTopics(vector<dataSrcType> &dataSource) {
	string line;
	string intermediate;
	vector<string> words;
	word_count_list word_count;

	//loop all records from source
	for (int i = 0; i < dataSource.size(); i++) {
		//clean text and stored into line
		line = deepCleanText(dataSource[i].getPost());
		stringstream check1(line);
		while (getline(check1, intermediate, ' ')) {
			//if NOT space, push_back to words
			words.push_back(intermediate);
		}
	}

	for (int i = 0; i < words.size(); i++) {
		line = words[i];
		// Remove punctuation.
		int index;
		while ((index = line.find_first_of("\".:,!?\\;-*+")) != string::npos)
			line.erase(index, 1);

		++word_count[line];
	}
	//copy pairs to vector
	vector<pair<string, int> > wordvector;
	vector<pair<string, int> > wordvector10;
	copy(word_count.begin(), word_count.end(), back_inserter(wordvector));
	
	//sort the vector by second (value) instead of key
	sort(wordvector.begin(), wordvector.end(), val_lt);
	int intTop10Size = 0;
	if (wordvector.size() >= 10) {
		intTop10Size = 10;
	}
	else if(wordvector.size() >=1 & wordvector.size() < 10) {
		intTop10Size = wordvector.size();
	}
	for (int i = 0; i < intTop10Size; i++)
		wordvector10.push_back(wordvector[i]);
	return wordvector10; // return key value pair of limit 10
}