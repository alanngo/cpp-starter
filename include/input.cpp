#include "input.hpp"
#include <limits>

using objects::Ptr;
using std::cin;
using std::cout;

template <class E, class Alloc, class... Args>
E input(str prompt, Args &&...args)
{
    Ptr<E, Alloc> p(forward<Args>(args)...);
    cout << prompt;
    cin >> *p;
    return *p;
}

using std::numeric_limits;
using std::streamsize;
using std::getline;

template <class E, class Alloc, class... Args>
E inputline(str prompt, Args &&...args)
{
    Ptr<E, Alloc> p(forward<Args>(args)...);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << prompt;
    getline(cin, *p);
    cin.clear();
    return *p;
}