

// https://www.lihaoyi.com/post/BuildyourownCommandLinewithANSIescapecodes.html
#ifndef CONSOLE_H
#define CONSOLE_H
#include <iostream>
#include <sstream>
#include <chrono>
#include <ctime>
#include <string>
#include <algorithm>

using namespace std;
using namespace chrono;

#define SPACE " "
#define COLON ":"
#define NEWLINE "\n"[0]

// colors

#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define BLUE "\x1B[34m"
#define PURPLE "\x1B[35m"
#define BLACK "\u001b[41m"
#define RESET "\u001b[0m"

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

// only use these for printing

/**
 * default logging
 * @param ... arguments
 */
#define LOG(...) log(clog, __VA_ARGS__) << endl

/**
 * trace log level
 * @param ... arguments
 */
#define TRACE(...) print(clog, PURPLE, "TRACE", __FILE__, __LINE__, __VA_ARGS__)

/**
 * debug log level
 * @param ... arguments
 */
#define DEBUG(...) print(clog, GREEN, "DEBUG", __FILE__, __LINE__, __VA_ARGS__)

/**
 * info log level
 * @param ... arguments
 */
#define INFO(...) print(clog, BLUE, "INFO", __FILE__, __LINE__, __VA_ARGS__)

/**
 * warning log level
 * @param ... arguments
 */
#define WARN(...) print(clog, YELLOW, "WARN", __FILE__, __LINE__, __VA_ARGS__)

/**
 * error log level (uses stderr)
 * @param ... arguments
 */
#define ERROR(...) print(cerr, RED, "ERROR", __FILE__, __LINE__, __VA_ARGS__)

/**
 * fatal log level (uses stderr)
 * @param ... arguments
 */
#define FATAL(...) print(cerr, BLACK, "FATAL", __FILE__, __LINE__, __VA_ARGS__)

#endif

