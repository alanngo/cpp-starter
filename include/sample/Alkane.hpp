#ifndef ALKANE_HPP
#define ALKANE_HPP
#include <string>
#include <ostream>
#include "../constants/types.hpp"
#include "../interface/comparable.hpp"

using std::string;
using std::to_string;
using std::ostream;
class Alkane : public Equals<Alkane>
{
public:
    Alkane(ReadOnly<int> c) : carbon(c > 1 ? c : 1), hydrogen(2 * (c + 1)) {}
    string getName() const
    {
        string table[10] = {"meth", "eth", "prop", "but",
                            "pent", "hex", "hept", "oct", "non", "dec"};
        if (carbon > 10)
            return "";
        return table[carbon - 1] + "ane";
    }
    friend ostream &operator<<(Output o, ReadOnly<Alkane> a)
    {
        return o << "C" << (a.carbon > 1 ? to_string(a.carbon) : "") << "H" << a.hydrogen;
    }

    bool operator==(ReadOnly<Alkane> a) const override { return carbon == a.carbon && hydrogen == a.hydrogen; }

private:
    const int carbon;
    const int hydrogen;
};
#endif // ALKANE_HPP