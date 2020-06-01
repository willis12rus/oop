#pragma once
#include <iostream>
#include <vector>
using namespace std;

void ReadElements(istream& input, std::vector<double>& vect);

void DivideVectorByHalfMax(std::vector<double>& vect);

void PrintSortedVector(std::vector<double>& vect, ostream& output);