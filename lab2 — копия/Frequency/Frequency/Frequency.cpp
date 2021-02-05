#include "functions.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	counting freq = Frequency(cin);
	if (freq.size() == 0)
	{
		cout << "empty input" << endl;
		return 0;
	}
	for (auto i : freq)
	{
		cout << i.first << " встречается " << i.second << " раз " << endl;
	}
	return 0;
}
