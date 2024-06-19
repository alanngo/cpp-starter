
#include <iostream>
#include <sstream>
#include <chrono>
#include <ctime>
#include <string>
#include <algorithm>
#include <colors.hpp>
#include <chars.hpp>

using namespace std;
using namespace chrono;
string getTime()
{
    // Some computation here
    auto end = system_clock::now();
    time_t end_time = system_clock::to_time_t(end);

    // to string
    stringstream ss;
    ss << ctime(&end_time);
    string ret = "[ " + ss.str();
    ret.erase(std::remove(ret.begin(), ret.end(), NEWLINE), ret.cend());
    ret += SPACE;
    return ret + "]";
}

using str = const string &;
using num = const int &;

/**
 * basic logging
 * @param o output stream
 * @param args variadic printable arguments
 * @return output stream
 */
template <class... Args>
ostream &log(ostream &o, Args &&...args)
{
    ([&]
     { o << forward<Args>(args) << " "; }(),
     ...);
    return o;
}
/**
 * prints date, time, calling file, log level and args
 * @param o output stream
 * @param color color of text
 * @param type TRACE | DEBUG | INFO | WARN |ERROR | FATAL
 * @param fi current file that is calling
 * @param line line number from callee
 * @param args variadic printable arguments
 * @example [ Wed Feb 14 05:56:58 2024 ] --- [src/tests/file_logger_tests.cpp:7] TRACE: im a pickle 2
 */
template <class... Args>
void print(ostream &o, str color, str type, str fi, num line, Args &&...args)
{
    o << color << getTime() << " --- "
      << "[" << fi << ":" << line << "] " << type << COLON << SPACE;
    log(o, args...);
    o << RESET << endl;
}