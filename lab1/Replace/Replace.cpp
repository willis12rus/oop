#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <fstream>
#include <string>
#include <SDKDDKVer.h>

using namespace std;

int main(int argc, char** argv)
{
	if (argc != 5)
	{
		cout << "Invalid argument count\n"
				  << "Usage: replace.exe <inputFile> <outputFile> <searchString> <replacementString>\n";
		return 1;
	}

	ifstream inputFile;
	inputFile.open(argv[1]);

	ofstream outputFile;
	outputFile.open(argv[2]);
	if ((inputFile.is_open()) and (outputFile.is_open())){
		string searchString = argv[3];
		string replaceString = argv[4];
		string line;
		while (getline(inputFile, line))
		{
			size_t pos = 0;
			string result;
			while (pos < line.length())
			{
				size_t foundPos = line.find(searchString, pos);
				result.append(line, pos, foundPos - pos);
				if (foundPos != string::npos) 
				{
					result.append(replaceString);
					pos = foundPos + searchString.length();
				}
				else
				{
					break;
				}	
			}
			outputFile << result << "\n";
		}
		if (!outputFile.flush()){
			cout << "Error with writing in output file: please check buffer\n";
		}
	} else {
		cout << "Can''t find input/output file\n"
				  << "Please, enter correct file names\n";
		return 1;
	}

	return 0;
}
