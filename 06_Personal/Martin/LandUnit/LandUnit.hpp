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
	LandUnit(string pathToIndexhtml) : pathToIndexhtml_(pathToIndexhtml)
	{
		setTemperature("--");
		setTomatoes("--");
		setTrees("--");
	}
	
	void updateTUI(){
		readFromRemote();	
		readFromDataFile();
		string temp = openAndCopy(pathToIndexhtml_);
		string temp1 = updateData(temp, "Temperature", temperatureValue_);
		string temp2 = updateData(temp1, "Tomatoes", tomatoesValue_);
		string updatedString = updateData(temp2, "Trees", treesValue_);
		openAndReplace(pathToIndexhtml_, updatedString);
	}

private:
string pathToIndexhtml_;
string temperatureValue_;
string tomatoesValue_;
string treesValue_;
	
	void setTemperature(string value){
		temperatureValue_ = value;	
	}

	void setTomatoes(string value){
		tomatoesValue_ = value;	
	}

	void setTrees(string value){
		treesValue_ = value;	
	}
	
	void readFromDataFile(string pathToDatafile){
		// Open data.txt and read the hole string
		// find the dataValues and save them in local variabels
		setTemperature("new value");
		setTomatoes("new value");
		setTrees("new value");	
	}

	void readFromRemote(){
		// TO BE IMPLEMENTED	
		// do some stuff that gets the data from whereever
		// write this data to the data.txt file
	}			

	string updateData(string htmlstring, string data, string dataValue){
  		if (data.length() > 3)
  		{
    		data = "--";
  		}
  		int    startOfDataPoint  = htmlstring.find(dataValue);
  		size_t lenghtOfDataPoint = dataValue.length() + 1;
  		return htmlstring.replace(startOfDataPoint + lenghtOfDataPoint, 
												  data.length(), data);
	}

	string openAndCopy(string filename){
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
  		return output;
	}
	
	void openAndReplace(string filename, string htmlstring){
  		fstream file_handler;
  		file_handler.open(filename);
  		file_handler << htmlstring;
  		file_handler.close();
	}
};
