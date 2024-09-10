#ifndef STRINGS
#define STRINGS
#include <vector>
#include <regex>
#include "types.hpp"

using std::vector;

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

}
#include "impl/strings.cpp"
#endif