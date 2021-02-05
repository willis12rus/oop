#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include "VectorFunctions.h"

using namespace std;

int main() {
    vector<double> inVector;
    ReadElements(cin, inVector);
    if (!inVector.empty())
    {
        DivideVectorByHalfMax(inVector);
        PrintSortedVector(inVector, cout);
    }
    else
    {
        cout << "Vector is empty" << endl;
        return 1;
    }
    return 0;
}
