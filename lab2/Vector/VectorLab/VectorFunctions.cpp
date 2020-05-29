#include "VectorFunctions.h"
#include <iostream>
#include <algorithm>
#include <iomanip>

void ReadElements(istream& input, vector<double>& vect)
{
	double temp;
	while (input >> temp) {
		vect.push_back(temp);
	}
}

double FindMaxElement(vector<double>& vect)
{
	double max = -999999998.0;
	for (unsigned int i = 0; i < vect.size(); ++i) {
		if (max < vect[i]) {
			max = vect[i];
		}
	}
	return max;
}

void MultiplyVectorByNumber(vector<double>& vect, double num)
{
	for (unsigned int i = 0; i < vect.size(); ++i) {
		vect[i] /= (num/2);
	}
}

void PrintSortedVector(vector<double>& vect, ostream& output)
{
	sort(vect.begin(), vect.end());
	for (unsigned int i = 0; i < vect.size(); ++i) {
		if (i != vect.size() - 1) {
			output << setprecision(3) << vect[i] << " ";
		}
		else {
			output << setprecision(3) << vect[i];
		}
	}
}
