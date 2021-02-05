#include <iostream>
#include <sstream>
#include <vector>
#include "../src/HTMLDecodeFunction.h"
#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
using namespace std;

SCENARIO("HTMLDecode")
{
    WHEN("HTML string is empty")
    {
        const string temp;
        THEN("Same empty HTML string")
        {
            string tempCopy = HtmlDecode(temp);
            CHECK(temp == tempCopy);
        }
    }

    WHEN("HTML string without special symbols")
    {
        const string temp = "2";
        THEN("Same HTML string")
        {
            string tempCopy = HtmlDecode(temp);
            CHECK(temp == tempCopy);
        }
    }

    WHEN("HTML string with special symbols")
    {
        const string temp = "Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s";
        THEN("Correct decode in HTML string")
        {
            string answer = "Cat <says> \"Meow\". M&M`s";
            string tempCopy = HtmlDecode(temp);
            CHECK(tempCopy == answer);
        }
    }

    WHEN("HTML string with ampersand")
    {
        const string temp = "&amp;lt;";
        THEN("Correct decode in HTML string")
        {
            string answer = "&lt;";
            string tempCopy = HtmlDecode(temp);
            CHECK(tempCopy == answer);
        }
    }
}