#pragma once
#include <iostream>
#include <map>
#include <string>
#include <locale.h>
#include <algorithm>
#include <windows.h>

using namespace std;

typedef map<string, int> counting;
counting Frequency(istream& input);