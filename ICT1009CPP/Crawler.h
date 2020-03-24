#pragma once
/*
* SOURCE 1: https://github.com/swatkat/twitcurl
* SOURCE 2: https://code.google.com/archive/p/twitcurl/wikis/WikiHowToUseTwitcurlLibrary.wiki
*/

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <regex>
//include libcurl header files
#include <libcurl/oauthlib.h>
#include <libcurl/twitcurl.h>
//include jsoncpp header files
#include <json/json.h>

////to error LNK2019: unresolved external symbols
////due to twitcurl lib developed in older programming definitions
////https://stackoverflow.com/questions/30412951/unresolved-external-symbol-imp-fprintf-and-imp-iob-func-sdl2
//#define stdin  (__acrt_iob_func(0))
//#define stdout (__acrt_iob_func(1))
//#define stderr (__acrt_iob_func(2))
//
//FILE _iob[] = { *stdin, *stdout, *stderr };
//
//extern "C" FILE * __cdecl __iob_func(void) { return _iob; }
//extern "C" void __imp__set_output_format(void) {};

using namespace std;

class Crawler {
	//twitCurl object & strings
	twitCurl twitterObj;
	string consumerKey = "gecVJpfhln3jQvDWkzlwJAP9z";
	string consumerKeySecret = "DmE5ScgU25Fia4X9MJQ03MOnfcqfeib9HLPWUApvatDoEaXfCw";
	string myOAuthAccessTokenKey = "1224630127553699840-rcPcecGhl7oeE3PNX1YMGMA6iHrtqJ";
	string myOAuthAccessTokenSecret = "2ID5dZFgv48gPsXNfp19AwPMHjWQeKnjIzHjnLp2K4F1F";

	//Json objects
	Json::Value jsonRoot;
	Json::Reader jsonReader;

	Json::Value search_metadata;
	Json::Value statuses;
	Json::Value statuses_text;
	Json::Value statuses_createdAt;
	Json::Value statuses_userScreenName;

public:
	Crawler();
	void crawlerTwitter(string, int);
	string crawlerCleanText(string);
	void crawlerJsonToFile();
};