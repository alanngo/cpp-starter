#ifndef ARGS
#define ARGS
#include "constants/types.hpp"
#include <string>
#include <ostream>
using std::out_of_range;
using std::to_string;

#define IN_RANGE(i, len) (i >= 0 && i < len)
class Arguments
{
protected:
    using idx = const size_t &;
    using self = Arguments;

public:
    class Iterator;

    /**
     * constructor
     * @param count argument count
     * @param vec argument vector
     */
    Arguments(ReadOnly<int>, char **) noexcept;

    /**
     * destructor
     */
    ~Arguments();

    /**
     * checks if program arguments are present
     * @returns true if there are more than 1 argument
     */
    operator bool() const { return len > 1; }

    /**
     * gets length of argument array
     */
    ReadOnly<size_t> length() const { return len; }

    /**
     * accesses argument at specific index
     * @param i index to access at
     * @returns argument at specified index
     * @throws out_of_range if i<0 or i>= argc
     */
    ReadOnly<string> operator[](idx i) const { return IN_RANGE(i, len) ? args[i] : outOfRange(i); }

    /**
     * make iterable from
     * @return iterator pointing to start argument
     */
    Iterator begin() const;

    /**
     * make  iterable until end
     * @return iterator pointing to end argument
     */
    Iterator end() const;

    /**
     * makes arguments streamable
     * @param o output stream
     * @param a arguments to stream
     * @returns streamed argument vector
     */
    friend ostream &operator<<(ostream &, ReadOnly<Arguments>);

    /**
     * deleted copy constructor
     */
    Arguments(ReadOnly<Arguments>) = delete;

    /**
     * deleted move constructor
     */

    Arguments(Tmp<Arguments>) = delete;
    /**
     * delete copy assignment
     */
    Arguments &operator=(ReadOnly<Arguments>) = delete;

    /**
     * delete move assignment
     */
    Arguments &operator=(Tmp<Arguments>) = delete;

private:
    static ReadOnly<string> outOfRange(idx i) { throw out_of_range(to_string(i)); }
    string *args;
    size_t len;

    Arguments(ReadOnly<int> count) : args(new string[count]), len(count) {}
};

#include "impl/arguments.cpp"
#undef IN_RANGE
#endif