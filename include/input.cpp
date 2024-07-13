#include "input.hpp"

template <class E, class... Args>
E input(str prompt, Args &&...args)
{
    unique_ptr<E> up(construct<E>(forward<E>(args)...));
    cout << prompt;
    cin >> *up;
    return *up;
}