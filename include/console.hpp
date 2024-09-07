#ifndef CONSOLE_H
#define CONSOLE_H
#include "impl/console.cpp"
#include "colors.hpp"

using std::clog;
using std::cerr;

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

