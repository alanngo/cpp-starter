
#include <iostream>
#include <sstream>
#include <chrono>
#include <ctime>
#include <string>
#include <algorithm>
#include "constants/chars.hpp"
#include "constants/colors.hpp"
#include "constants/types.hpp"

using std::ostream;
using std::stringstream;

using std::endl;
using std::string;
using std::forward;
using std::remove;

using namespace std::chrono;
string getTime()
{
    // Some computation here
    auto end = system_clock::now();
    time_t end_time = system_clock::to_time_t(end);

    // to string
    stringstream ss;
    ss << ctime(&end_time);
    string ret = "[ " + ss.str();
    ret.erase(remove(ret.begin(), ret.end(), NEWLINE), ret.cend());
    ret += SPACE;
    return ret + "]";
}

using num = ReadOnly<int>;

template <class... Args>
ostream &log(ostream &o, Args &&...args)
{
    ([&]
     { o << forward<Args>(args) << " "; }(),
     ...);
    return o;
}

template <class... Args>
void print(ostream &o, str color, str type, str fi, num line, Args &&...args)
{
    o << color << getTime() << " --- "
      << "[" << fi << ":" << line << "] " << type << COLON << SPACE;
    log(o, args...);
    o << RESET << endl;
}