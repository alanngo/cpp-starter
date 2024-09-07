#ifndef STRINGS
#define STRINGS
#include <vector>
#include <string>
#include <regex>
#include "types.hpp"

using std::string;
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

}
#include "impl/strings.cpp"
#endif