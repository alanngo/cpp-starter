#ifndef STRINGS
#define STRINGS
#include <vector>
#include <regex>
#include <sstream>

#include "types.hpp"

using std::vector;
using std::stringstream;
namespace
{
#define LOWERCASE true
#define UPPERCASE false
    string convertString(str s, flag f)
    {
        stringstream ss;
        for (size_t i = 0; i < s.length(); i++)
            ss << (char)(f ? towlower(s[i]) : toupper(s[i]));
        return ss.str();
    }
}
/**
 * string utility file w/ advanced operations
 */
namespace strings
{
    using args = const vector<string> &;

    /**
     * splits a string based on delimeter
     * @param s base string to split
     * @param delim delimeter to split by
     * @returns vector of seperate strings
     */
    vector<string> split(str, str = "");

    /**
     * join set of strings w/ delimeter
     * @param strList strings to use
     * @param delim delimeter to join
     * @returns joined string
     */
    string join(args, str = "");

    /**
     * case-insensitive comparison
     * @param a lhs string
     * @param b rhs string
     * @return true if lhs and rhs values are equal ignoring case
     */
    bool equalsIgnoreCase(str, str);

    using std::regex;
    using std::regex_constants::icase;

    /**
     * case-insensitive regex matching
     * @param s reference string
     * @param p regex pattern
     * @return true if match exist
     */
    inline bool matchIgnoreCase(str s, str p) { return regex_match(s, regex(p, icase)); }

    /**
     * converts string to uppercase
     * @param s input string
     * @return uppercase version of input string
     */
    inline string toUppercase(str s) { return convertString(s, UPPERCASE); }

    /**
     * converts string to lowercase
     * @param s input string
     * @return lowercase version of input string
     */
    inline string toLowercase(str s) { return convertString(s, LOWERCASE); }
}
#include "impl/strings.cpp"
#endif