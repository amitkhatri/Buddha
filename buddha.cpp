//***********************************
//Buddha: A terminal-based meditation timer
//Author: Amit Khatri, February 7th, 2017
//***********************************
#include <iostream>
#include <fstream>
#include <string>
#include <curl/curl.h>
using namespace std;
void printBuddha();
void qotd();
void displayMenu();
int main(void)
{	int selection;
	printBuddha();
	qotd();
	displayMenu();
}

void printBuddha()
{
	string line;
	ifstream buddhaFile ("buddha.txt");
	if (buddhaFile.is_open())
	{
		while( getline (buddhaFile,line) )
		{
			cout<<line<<endl;
		}
		buddhaFile.close();
	}
	cout<<endl;
}
//First time using CURL
void qotd()
{
	CURL * curl;
	CURLcode res;

	//Start a libcurl session
	curl = curl_easy_init();
	if(curl)
	{	//Input URL for curl to work on
		curl_easy_setopt(curl,CURLOPT_URL,"http://tinybuddha.com/wp-content/plugins/tiny-buddha-host/wisdom.txt");
		//Perform URL request
		res = curl_easy_perform(curl);
		//End libcurl session
		curl_easy_cleanup(curl);
	}
	cout<<endl<<endl;
	return;
}

void displayMenu()
{
	cout<<"WELCOME TO BUDDHA: A TERMINAL-BASED MEDITATION TIMER"<<endl;
	cout<<"===================================================="<<endl;
	cout<<"PRESS 1 TO START A NEW TIMER"<<endl;
	cout<<"PRESS 2 TO EXIT"<<endl;
	cout<<"===================================================="<<endl;
}
