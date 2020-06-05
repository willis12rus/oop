#include <iostream>
#include <sstream>
#include <vector>
#include "../src/ReplaceCodeFromLab1.h"
#include "../src/HTMLDecodeFunction.h"
#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#define CATCH_CONFIG_MAIN

using namespace std;

SCENARIO("ReplaceString")
{
    const string searchString = "1";
    const string replacementString = "2";
    WHEN("Subject string is empty")
    {
        const string temp;
        THEN("Same empty subject string")
        {
            string tempCopy = ReplaceString(temp, searchString, replacementString);
            CHECK(temp == tempCopy);
        }
    }

    WHEN("Search string is not in subject string")
    {
        const string temp = "2";
        THEN("Same subject string")
        {
            string tempCopy = ReplaceString(temp, searchString, replacementString);
            CHECK(temp == tempCopy);
        }
    }

    WHEN("Search string is in subject string")
    {
        const string temp = "1";
        THEN("Correct replacement in subject string")
        {
            string answer = "2";
            string tempCopy = ReplaceString(temp, searchString, replacementString);
            CHECK(tempCopy == answer);
        }
    }
}

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
}