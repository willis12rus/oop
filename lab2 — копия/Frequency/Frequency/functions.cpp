#include "functions.h"


using namespace std;

counting Frequency(istream& input)
{
	counting freq;
	string word;
	while (!input.eof())
	{
		input >> word;
		if (word[0] != '\0')
		{
			for_each(word.begin(), word.end(), [](char& ch)
				{
					ch = tolower(ch);
				});
			freq[word]++;
		}
	}
	return freq;
}