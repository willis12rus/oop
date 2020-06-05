#include <string>
#include "ReplaceCodeFromLab1.h"

using namespace std;

string ReplaceString(const string& subject, const string& searchString, const string& replacementString)
{
    if (searchString.empty())
    {
        return replacementString;
    }
    size_t pos = 0;
    string result;
    while (pos < subject.length())
    {
        size_t foundPos = subject.find(searchString, pos);
        result.append(subject, pos, foundPos - pos);
        if (foundPos != string::npos)
        {
            result.append(replacementString);
            pos = foundPos + searchString.length();
        }
        else
        {
            break;
        }
    }
    return result;
}