#include <iostream>
#include <sstream>
#include <vector>
#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../VectorLab/VectorFunctions.h"

using namespace std;

SCENARIO("ReadElements")
{
	vector<double> temp;
	WHEN("No elements") {
		istringstream input("");
		THEN("Vector is empty") {
			ReadElements(input, temp);
			CHECK(input.eof());
			CHECK(temp.size() == 0);
		}
	}

	WHEN("One element") {
		istringstream input("1.25");
		THEN("Vector have 1 element") {
			ReadElements(input, temp);
			CHECK(input.eof());
			CHECK(temp.size() == 1);
		}
	}

	WHEN("Two element") {
		istringstream input("1.25 2.25");
		THEN("Vector have 2 element") {
			ReadElements(input, temp);
			CHECK(input.eof());
			CHECK(temp.size() == 2);
		}
	}

	WHEN("Elements on different lines") {
		istringstream input("1.25\n2.25");
		THEN("Vector have 2 element") {
			ReadElements(input, temp);
			CHECK(input.eof());
			CHECK(temp.size() == 2);
		}
	}
}

SCENARIO("FindMaxElement") {
	double maxElem;
	WHEN("Vector is empty") {
		vector<double> temp;
		THEN("No found max element") {
			maxElem = FindMaxElement(temp);
			CHECK(maxElem == -999999998.0);
		}
	}

	WHEN("Vector have 1 element") {
		vector<double> temp{ 1.2 };
		THEN("This element is max element") {
			maxElem = FindMaxElement(temp);
			CHECK(maxElem == 1.2);
		}
	}

	WHEN("Vector have several element") {
		vector<double> temp{ 1.2, 1.3, 1.4, 0.2, 5.6 };
		THEN("Found max element") {
			maxElem = FindMaxElement(temp);
			CHECK(maxElem == 5.6);
		}
	}
}

SCENARIO("MultiplyVectorByNumber") {
	WHEN("Vector is empty") {
		vector<double> temp;
		THEN("Same empty vector") {
			vector<double> tempCopy = temp;
			MultiplyVectorByNumber(temp, 2);
			CHECK(temp == tempCopy);
		}
	}

	WHEN("Vector have 1 element") {
		vector<double> temp{1.2};
		THEN("Correct multiply vector's element") {
			vector<double> answer{1.2};
			MultiplyVectorByNumber(temp, 2);
			CHECK(temp == answer);
		}
	}

	WHEN("Vector have several elements") {
		vector<double> temp{ 1.2, 1.0, 2.2, 4.0 };
		THEN("Correct multiply vector's elements") {
			vector<double> answer{ 1.2, 1.0, 2.2, 4.0 };
			MultiplyVectorByNumber(temp, 2);
			CHECK(temp == answer);
		}
	}
}

SCENARIO("PrintSortedVector") {
	ostringstream output;

	WHEN("Vector is empty") {
		vector<double> temp;
		THEN("Nothing to print") {
			PrintSortedVector(temp, output);
			CHECK(output.str() == "");
		}
	}

	WHEN("Vector have 1 element") {
		vector<double> temp{1.2};
		THEN("Print one element") {
			PrintSortedVector(temp, output);
			CHECK(output.str() == "1.2");
		}
	}

	WHEN("Vector is sorted") {
		vector<double> temp{ 1.2, 1.3, 1.4, 1.5 };
		THEN("Print this vector without changes") {
			PrintSortedVector(temp, output);
			CHECK(output.str() == "1.2 1.3 1.4 1.5");
		}
	}

	WHEN("Vector is not sorted") {
		vector<double> temp{ 1.4, 1.5, 1.2, 1.3, 1.1 };
		THEN("Print sorted vector") {
			PrintSortedVector(temp, output);
			CHECK(output.str() == "1.1 1.2 1.3 1.4 1.5");
		}
	}
}