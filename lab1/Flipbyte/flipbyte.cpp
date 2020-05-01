include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <fstream>
#include <string>
#include <SDKDDKVer.h>

using namespace std;

string ReplaceString(const string& subject,	const string& searchString, const string& replacementString)
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

void CopyTextWithReplace(ifstream& input, ofstream& output, const string& searchString, const string& replaceString)
{
	if (!input.is_open() || !output.is_open()){
		cout << "Can't find input/output file\n"
			 << "Please, enter correct file names\n";
		return;
	}
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
	if (argc != 2)
	{
		cout << "Invalid argument count\n"
				  << "Usage: flipbyte.exe <input byte>\n";
		return 1;
	}
	
							
	CopyTextWithReplace(FileIn, FileOut, search, replace);
	if (!FileOut.flush())
	{
		cout << "Error with writing in output file: please check buffer\n";
	}
	
	return 0;
}
