#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include "VectorFunctions.h"

using namespace std;

int main()
{
	vector<double> inVector;
	ReadElements(cin, inVector);
	if (inVector.size() != 0) {
		double maxElem = FindMaxElement(inVector);
		MultiplyVectorByNumber(inVector, maxElem);
		PrintSortedVector(inVector, cout);
	}
	else {
		cout << "Vector is empty" << endl;
		return 0;
	}
	return 0;
}
