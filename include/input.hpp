#ifndef INPUT
#define INPUT
#include <iostream>
#include <string>
#include <memory>
#include "objects.hpp"

using objects::construct;
using std::cin;
using std::cout;
using std::string;
using str = const string &;

/**
 * gets input from keyboard, stores it in ptr and returns it
 * @param prompt interactive prompt, (defaults to blank string)
 * @param args used to construct temp object if necesarry
 * @returns value stored 
 */
template <class E, class... Args>
E input(str = "", Args &&...);

#include "input.cpp"
#endif