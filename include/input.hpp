#ifndef INPUT
#define INPUT
#include <iostream>
#include <string>
#include <memory>
#include "objects.hpp"

using std::string;
using str = const string &;
using std::allocator;

/**
 * gets input from keyboard and returns it
 * @param prompt interactive prompt, (defaults to blank string)
 * @param args used to construct temp object if necesary
 * @warning will discard spaces, use 'inputline' instead
 * @returns value stored
 */
template <class E, class Alloc = allocator<E>,
          class... Args>
E input(str = "", Args &&...);

/**
 * gets whole line from input through keyboard and returns it
 * @param prompt interactive prompt, (defaults to blank string)
 * @param args used to construct temp object if necesary
 * @returns value stored
 */
template <class E = string, class Alloc = allocator<E>,
          class... Args>
E inputline(str = "", Args &&...);

#include "input.cpp"
#endif