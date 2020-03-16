#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <fstream>
#include <string>
#include <SDKDDKVer.h>

using namespace std;

string ReplaceString(const string& subject, const string& searchString, const string& replacementString)
{
	if (searchString == replacementString)
	{
		return replacementString;
	}
	size_t pos = 0;
	string result;
	while (pos < subject.length())
	{
		size_t foundPos = subject.find(searchString, pos);
		result.append(subject, pos, foundPos - pos);
		if (foundPos != string::npos) 
		{
			result.append(replacementString);
			pos = foundPos + searchString.length();
		}
		else
		{
			break;
		}
	}
	return result;
}

void CopyTextWithReplace(istream& input, ostream& output, const string& searchString, const string& replaceString)
{
	if (searchString.empty())
	{
		return;
	}
	string line;
	while (getline(input, line))
	{
		output << ReplaceString(line, searchString, replaceString) << "\n";
	}
}

int main(int argc, char* argv[])
{
	if (argc != 5)
	{
		cout << "Invalid argument count\n"
				  << "Usage: replace.exe <inputFile> <outputFile> <searchString> <replacementString>\n";
		return 1;
	}

	ifstream fileIn;
	fileIn.open(argv[1]);

	ofstream fileOut;
	fileOut.open(argv[2]);
	
	if (!fileIn.is_open() || !fileOut.is_open()){
		cout << "Can't find input/output file\n"
			 << "Please, enter correct file names\n";
		return 1;
	}
	
	string search = argv[3];
	string replace = argv[4];
	CopyTextWithReplace(fileIn, fileOut, search, replace);
	if (!fileOut.flush())
	{
		cout << "Error with writing in output file: please check buffer\n";
		return 1;
	}
	
	return 0;
}
