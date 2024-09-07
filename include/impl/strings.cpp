#include "strings.hpp"
#include <sstream>
vector<string> strings::split(str s, str delim)
{
    vector<string> ret;
    if (delim == "")
    {
        for (const char &c : s)
            ret.push_back(string(1, c));
    }
    else
    {
        size_t start = 0;
        string token;

        for (size_t end = s.find(delim); end != string::npos; end = s.find(delim, start))
        {
            token = s.substr(start, (end - start));
            start = end + delim.length();
            ret.push_back(token);
        }
        ret.push_back(s.substr(start));
    }
    return ret;
}

using std::stringstream;
string strings::join(args strList, str delim)
{
    stringstream ss;
    size_t i = 0;
    for (const string &elem : strList)
    {
        ss << elem << (i == strList.size() - 1 ? "" : delim);
        i++;
    }
    return move(ss.str());
}