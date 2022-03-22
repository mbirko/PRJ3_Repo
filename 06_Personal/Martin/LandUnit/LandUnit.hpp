/*
 * This class should be able to do the following:
 * 
 * Read some data from a wireless connection and save that data in a file data.txt following the 
 * current format: <dataValue> <data>
 *
 * Open data.txt file, copy current content and save ONLY the raw values for each of the datapoints
 * Then save that data in local variabels.
 *
 * Open index.html file, copy current content and save that as a string
 * Then find and replace the data values in above string, with the local variabels.
 * Finally write the new updated string to index.html file.
 *
 * Each of the above functionalities should run on seperate threads in order to avoid false readings
 *
 */ 

#include <fstream>
#include <iostream>
#include <istream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unistd.h>

// i am lazy
using std::cout;
using std::endl;
using std::fstream;
using std::string;
using std::to_string;

class LandUnit{

public:
	LandUnit(string pathToIndexhtml, string pathToDatafile) : 
			pathToIndexhtml_(pathToIndexhtml), pathToDataFile_(pathToDatafile)
	{
		setTemperature("10");
		setTomatoes("10");
		setTrees("10");
		setIndexHtmlString(pathToIndexhtml_);
		setDataTxtString(pathToDataFile_);

		cout << pathToIndexhtml_ << endl;
		cout << pathToIndexhtml_ << endl;
		cout << indexhtmlString_ << endl;
		cout << datatxtString_   << endl;
		cout << temperatureValue_<< endl;
		cout << tomatoesValue_   << endl;
		cout << treesValue_ 	 << endl;
	}
	
	void updateTUI(){
		// print out current indexhtml
		printFile(pathToIndexhtml_);
		// Opens data.txt and copies and set local datatxt 
		setDataTxtString(pathToDataFile_);
		// use the datatxt string to extract data values and set local data 
		updateLocalDataVariabels(datatxtString_);
		// Opens index.html and copies and set local indexhtml 
		setIndexHtmlString(pathToIndexhtml_);
		// use the indexhtml string to update data1 etc
		updateDataInString(indexhtmlString_, temperatureValue_, "data1");
		// Opens index.html and replaces with local indexhtml 
		openAndReplace(pathToIndexhtml_, indexhtmlString_);
		// print out updated indexhtml
		printFile(pathToIndexhtml_);
	}

	// opens file at full path and reads the content to stdout
	void printFile(string filename)
	{
  		fstream file_handler;
  		string  readFromFile;
  		file_handler.open(filename);

  		if (file_handler.is_open()){
    		cout << "Reading from file" << filename << endl;
    		while (getline(file_handler, readFromFile)){
      			cout << readFromFile << endl;
    		}

			file_handler.close();
  		}
  		else
  		{
    		cout << "Could not open file: " << filename << endl;
  		}	
}

private:
string pathToIndexhtml_;
string pathToDataFile_;
string temperatureValue_;
string tomatoesValue_;
string treesValue_;
string indexhtmlString_;
string datatxtString_;

	void setTemperature(string value){
		temperatureValue_ = value;	
	}

	void setTomatoes(string value){
		tomatoesValue_ = value;	
	}

	void setTrees(string value){
		treesValue_ = value;	
	}
	
	void setIndexHtmlString(string filename){
  		fstream file_handler;
  		string  line;
  		string  output;
  		file_handler.open(filename);
  		if (file_handler.is_open())
  		{
    		while (getline(file_handler, line))
    		{	
      			output += line + "\n";
    		}
    		file_handler.close();
  		}
  		else
  		{
    		cout << "Could not open file: " << filename << endl;
  		}
  		indexhtmlString_ = output;
	}
	
	void setDataTxtString(string filename){
  		fstream file_handler;
  		string  line;
  		string  output;
  		file_handler.open(filename);
  		if (file_handler.is_open())
  		{
    		while (getline(file_handler, line))
    		{	
      			output += line;
    		}
    		file_handler.close();
  		}
  		else
  		{
    		cout << "Could not open file: " << filename << endl;
  		}
  		datatxtString_ = output;
	}
	void updateLocalDataVariabels(string datatxtString_){
		// Format of data.txt <dataID> <data> etc.
		// find the <dataID> and save <data> them in local variabels
		setTemperature(datatxtString_.substr(datatxtString_.find("data1")+6, 2));	
		setTomatoes(datatxtString_.substr(datatxtString_.find("data2")+6, 2));	
		setTemperature(datatxtString_.substr(datatxtString_.find("data3")+6, 2));	
		cout << temperatureValue_ <<endl;
		cout << tomatoesValue_    << endl;
		cout << treesValue_       << endl;
		
	}

	void updateDataInString(string htmlstring, string data, string dataID){
  		int    startOfDataID  = htmlstring.find(dataID);
  		size_t lenghtOfDataID = dataID.length() + 1;
  		indexhtmlString_ = htmlstring.replace(startOfDataID + lenghtOfDataID, data.length(), data);
	}
	
	void openAndReplace(string filename, string htmlstring){
  		fstream file_handler;
  		file_handler.open(filename);
  		file_handler << htmlstring;
  		file_handler.close();
	}

	void readFromRemote(){
		// TO BE IMPLEMENTED	
		// do some stuff that gets the data from whereever
		// write this data to the data.txt file
	}			

};
