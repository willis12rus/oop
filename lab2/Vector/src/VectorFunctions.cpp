#include "VectorFunctions.h"
#include <iostream>
#include <algorithm>
#include <iomanip>

void ReadElements(istream& input, vector<double>& vect)
{
	double temp;
	while (input >> temp)
	{
		vect.push_back(temp);
	}
}

void DivideVectorByHalfMax(vector<double>& vect)
{
    if (vect.empty()) return;

    const auto max = std::max_element(vect.begin(), vect.end());


    if (*max == 0.0)
    {
        return;
    }

    for (double& element : vect)
    {
        element /= (*max/2);
    }
}

void PrintSortedVector(vector<double>& vect, ostream& output)
{
	sort(vect.begin(), vect.end());
    for (const double& element : vect)
    {
        output << setprecision(3) << element << " ";
    }
}
