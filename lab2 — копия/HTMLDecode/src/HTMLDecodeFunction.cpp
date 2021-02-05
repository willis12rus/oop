#include <string>
#include <map>
#include "HTMLDecodeFunction.h"

using namespace std;

map<string, string> HTMLList =
{
        {"&quot;", "\""},
        {"&apos;", "`"},
        {"&lt;", "<"},
        {"&gt;", ">"},
        {"&amp;", "&"}
};

string HtmlDecode(const string& htmlString)
{
    string resultString;
    string copyHtmlString = htmlString;
    size_t posAmp = 0;
    size_t pos = 0;
    while (posAmp < copyHtmlString.length())
    {
        size_t foundPos = copyHtmlString.find('&', posAmp);
        resultString.append(copyHtmlString, posAmp, foundPos - posAmp);
        if (foundPos != string::npos)
        {
            copyHtmlString.erase(0, foundPos);
            size_t posTemp = 0;
            for (auto & it : HTMLList)
            {
                posTemp = copyHtmlString.find(it.first, pos);
                if (posTemp == 0)
                {
                    resultString.append(it.second);
                    posTemp = pos + it.first.length();
                    break;
                }
            }
            copyHtmlString.erase(0, posTemp);
        }
        else
        {
            break;
        }
    }
    return resultString;
}