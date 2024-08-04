#include "input.hpp"
#include <limits>

using std::unique_ptr;
using objects::construct;
using std::cin;
using std::cout;

template <class E, class... Args>
E input(str prompt, Args &&...args)
{
    unique_ptr<E> up(construct<E>(forward<Args>(args)...));
    cout << prompt;
    cin >> *up;
    return *up;
}

using std::numeric_limits;
using std::streamsize;
using std::getline;

template <class E = string, class... Args>
E inputline(str prompt, Args &&...args)
{
    unique_ptr<E> up(construct<E>(forward<Args>(args)...));
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << prompt;
    getline(cin, *up);
    cin.clear();
    return *up;
}