#include "Crawler.h"

#ifdef _DEBUG
#	pragma comment (lib, "lib/libcurl.lib")
#else
#	pragma comment (lib, "lib/libcurl.lib")
#endif

Crawler::Crawler() {
	this->twitterObj.getOAuth().setConsumerKey(this->consumerKey);
	this->twitterObj.getOAuth().setConsumerSecret(this->consumerKeySecret);
	this->twitterObj.getOAuth().setOAuthTokenKey(this->myOAuthAccessTokenKey);
	this->twitterObj.getOAuth().setOAuthTokenSecret(this->myOAuthAccessTokenSecret);
}

void Crawler::crawlerTwitter(string strSearch, int intCount) {
	//inform about crawl limit of 100
	if (intCount > 100) {
		cout << "Sorry, You can only crawl a maxmium of 100 records" << endl
			<< "Continue with Crawling of 100 records" << endl;
	}

	string tmpStr2;
	string replyMsg;

	//convert to string
	tmpStr2 = to_string(intCount);
	replyMsg = "";

	if (this->twitterObj.search(strSearch, tmpStr2))
	{
		this->twitterObj.getLastWebResponse(replyMsg);
		//cout << "\n\n\ntwitterClient:: twitCurl::search web response:\n" << replyMsg.c_str() << endl;
		cout << "twitCurl::search web responded" << endl;

		bool parsingSuccessful = this->jsonReader.parse(replyMsg, this->jsonRoot);
		if (!parsingSuccessful)
		{
			//fail to parse and their locations in the document
			cout << "Failed to parse configuration\n"
				<< this->jsonReader.getFormattedErrorMessages();
		}
		else {
			this->search_metadata = this->jsonRoot["search_metadata"];

			//reduce the scope of json object
			this->statuses = this->jsonRoot["statuses"];

			int j = 0;
			for (int i = 0; i < this->statuses.size(); i++)
			{
				//filter out tweets to be of lang English only
				if (this->statuses[i]["lang"] == "en") {
					//stores each records to individual json object
					this->statuses_text[j] = this->crawlerCleanText(this->statuses[i]["text"].asString());
					this->statuses_createdAt[j] = this->statuses[i]["created_at"];
					this->statuses_userScreenName[j] = this->statuses[i]["user"]["screen_name"];
					j++;
				}
			}
			cout << "Only Tweets in English will be saved" << endl;
			cout << this->statuses_text.size()-1 << " Records Saved" << endl;
			//cout << this->statuses_text[statuses_text.size() - 1] << endl;
			//cout << this->statuses_createdAt[statuses_text.size() - 1] << endl;
			//cout << this->statuses_userScreenName[statuses_text.size() - 1] << endl;
		}
	}
	else
	{
		this->twitterObj.getLastCurlError(replyMsg);
		cout << "twitCurl::search error:" << replyMsg.c_str() << endl;
	}

	//replyMsg = "";

	//if (twitterObj.savedSearchShow("1241332597206085632"))
	//{
	//	twitterObj.getLastWebResponse(replyMsg);
	//	cout << "twitCurl::search web response:\n" << replyMsg.c_str() << endl;
	//	//cout << "twitCurl::search web response:\n" << endl;
	//}
	//else
	//{
	//	twitterObj.getLastCurlError(replyMsg);
	//	cout << "twitCurl::search error:\n" << replyMsg.c_str() << endl;
	//}
}

string Crawler::crawlerCleanText(string text) {
	regex regexNonAscii("[^\\x00-\\x7F]");
	regex regexNewLine("\n+");
	regex regexCarriageReturn("\r+");
	regex regexTab("\t+");
	regex regexCommaBlackSlash("[,\/]");
	regex regexMultiSpace("[\\s]+");
	regex regexLeadSpaces("^\\s+");
	regex regexTrailSpaces("\\s+$");

	//remove hyperlinks
	regex regexLinks("http.*?[\\S]+");
	//remove hashtags
	regex regexHashtags("#[\\S]+");
	//remove mentions
	regex regexMentions("@[\\S]+");
	//remove &amp;
	regex regexAnd("&amp;");
	//remove RT
	regex regexRT("RT");
	//remove Double Apostrophe
	regex regexDoubleApostrophe("\\\"");

	text = regex_replace(text, regexNonAscii, "");

	text = regex_replace(text, regexLinks, "");
	text = regex_replace(text, regexHashtags, "");
	text = regex_replace(text, regexMentions, "");
	text = regex_replace(text, regexAnd, " ");
	text = regex_replace(text, regexRT, "");
	text = regex_replace(text, regexDoubleApostrophe, "");

	text = regex_replace(text, regexNewLine, " ");
	text = regex_replace(text, regexCarriageReturn, " ");
	text = regex_replace(text, regexTab, " ");
	text = regex_replace(text, regexCommaBlackSlash, "");

	text = regex_replace(text, regexMultiSpace, " ");
	text = regex_replace(text, regexLeadSpaces, "");
	text = regex_replace(text, regexTrailSpaces, "");

	return text;
}

void Crawler::crawlerJsonToFile() {
	ofstream outFile;
	//declare what file to work with
	outFile.open("TwitterData.csv");

	if (outFile.is_open()) {
		//header column
		outFile << "Created On,Created By,Text" << endl;

		//for each row of records
		for (int i = 0; i < this->statuses_text.size(); i++)
		{
			outFile 
				<< this->statuses_createdAt[i] << ","
				<< this->statuses_userScreenName[i] << ","
				<< this->statuses_text[i] << endl;
		}
		outFile.close();
		cout << "Write to file successful" << endl;
	}
	else {
		outFile.close();
		cout << "Error: cannot write to file" << endl;
	}
}

//int main() {
//	
//	string strInput1;
//	int intInput2;
//	/* Search a string */
//	cout << "\nEnter string to search: ";
//	cin >> strInput1;
//
//	cout << "\nLimit search results to: ";
//	cin >> intInput2;
//
//	Crawler twitterCrawler;
//	twitterCrawler.crawlerTwitter(strInput1, intInput2);
//	twitterCrawler.crawlerJsonToFile();
//
//	cout << "END OF PROGRAM" << endl;
//	return 0;
//}