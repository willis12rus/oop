

#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <fstream>
#include <string>
#include <SDKDDKVer.h>

using namespace std;

unsigned char ReverseByte(unsigned char number)
{
    unsigned char revNum = 0;
    for (int i = 0; i < 8; i++) {
        revNum <<= 1;
        revNum |= number & 1;
        number >>= 1;
    }
    return revNum;
}

int FlipByte(char* numberGiven)
{
	unsigned char inputByte;
    int num;
	string number = numberGiven;
    try
    {
        num = stoi(number);
    }
    catch (const exception& err)
    {
        cout << err.what() << endl;
        return 1;
    }

    if ((num < 0) || (num > 255))
    {
        cout << "Invalid argument. Range of numbers: 0 - 255" << endl;
        return 1;
    }
	inputByte = static_cast<unsigned int>(num);

	cout << static_cast<int>(ReverseByte(inputByte)) << endl;
	return 0;

}


int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Invalid argument count\n"
			<< "Usage: flipbyte.exe <input byte>\n";
		return 1;
	}


	FlipByte(argv[1]);
	return 0;
}

