/* LIST OF THINGS TO ADD
 * - data validation
 * - please just add default values if data is wrong 
*/


#include <istream>
#include <fstream>
#include <iostream>
#include <string>

// i am lazy
using std::string;
using std::cout;
using std::endl;
using std::fstream;

// opens file at full path and reads the content to stdout
void printFile(string filename){

	fstream file_handler;
	string readFromFile;
	file_handler.open(filename);
		
	if(file_handler.is_open())
	{
		cout << "Reading from file" << filename << endl;
		while(getline(file_handler, readFromFile))
		{
			cout << readFromFile << endl;
		}
		file_handler.close();
	}
	else {
		cout << "Could not open file: "<< filename << endl;
	}		
}

// open file at full path and copy content into a string that returns
string openAndCopy(string filename){
 	fstream file_handler;
	string line;
	string output;
	file_handler.open(filename);
	if (file_handler.is_open())
	{
		while(getline(file_handler, line))
		{
			output+= line + "\n";
		}
		file_handler.close();
	}
	else {
		cout << "Could not open file: "<< filename << endl;
	}
	return output;
}

// open file and replace with content of a string
void openAndReplace(string filename, string htmlstring){
	fstream file_handler;
	file_handler.open(filename);
	file_handler << htmlstring;
	file_handler.close();
}

// replace data at x in string y
// Ex: data = "temperature", dataValue = "30", htmlstring = openAndCopy("index.html);
string updateData(string htmlstring, string data, string dataValue){

	int startOfDataPoint = htmlstring.find(dataValue);
	size_t lenghtOfDataPoint = dataValue.length()+1;	
	return htmlstring.replace(startOfDataPoint + lenghtOfDataPoint, data.length(), data);
}
// updates all data points in filepath
void updateAll(string temperatureValue, string tomatoesValue, string treesValue, string filepath){
	
	string indexhtml = filepath;
	
	// TODO implement as recursive function
	string temp1 = updateData(openAndCopy(indexhtml), temperatureValue, "Temperature");
	string temp2 = updateData(temp1, tomatoesValue, "Tomatoes");
	string temp3 = updateData(temp2, treesValue, "Trees");
	openAndReplace(indexhtml, temp3);

}

int main(){
	string indexhtml = "/var/www/html/index.html";
	updateAll("255","255","255", indexhtml);
	printFile(indexhtml);
}
