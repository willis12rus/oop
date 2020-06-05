#include "ReplaceCodeFromLab1.h"
#include <string>
#include <map>

 using namespace std;

 map<std::string, string> HTMLList =
{
        {"&quot;", "\""},
        {"&apos;", "`"},
        {"&lt;", "<"},
        {"&gt;", ">"},
        {"&amp;", "&"}
};

string HtmlDecode(const string& htmlString)
{
    string resultString = htmlString;

    for (auto & it : HTMLList)
    {
        resultString = ReplaceString(resultString, it.first, it.second);

    }

    return resultString;
}