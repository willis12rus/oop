#define CATCH_CONFIG_MAIN
#include "../../../../catch/catch.hpp"
#include "../Frequency/functions.h"
#include <iostream>
#include <sstream>
#include <iostream>

TEST_CASE("Empty input")
{
	istringstream input("\n   \t   \n");
	counting TrueOutput;
	counting result = Frequency(input);
	CHECK(result == TrueOutput);
}

TEST_CASE("Normal work")
{
	istringstream input("Hello world \n World is good \n hello good people");
	counting TrueOutput = { { "hello", 2 }, {"world", 2}, {"is", 1 }, {"good", 2}, {"people", 1} };
	counting result = Frequency(input);
	CHECK(result == TrueOutput);
}