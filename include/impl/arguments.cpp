#include "arguments.hpp"

using std::move;
class Arguments::Iterator
{
public:
    Iterator(Ptr<string> a) : ptr(a) {}

    Iterator &operator++()
    {
        ptr++;
        return *this;
    }

    Iterator operator++(int)
    {
        Iterator tmp = *this;
        ++(*this);
        return tmp;
    }

    Iterator &operator--()
    {
        ptr--;
        return *this;
    }

    Iterator operator--(int)
    {
        Iterator tmp = *this;
        --(*this);
        return tmp;
    }

    bool operator==(const Iterator &i) const { return ptr == i.ptr; }
    bool operator!=(const Iterator &i) const { return !(*this == i); }

    ReadOnly<string> operator*() const { return *ptr; }
    Ptr<string> operator->() const { return ptr; }

private:
    Ptr<string> ptr;
    size_t len;
};

Arguments::Arguments(ReadOnly<int> count, char **vec) noexcept
    : self(count - 1)
{
    for (int i = 1; i < count; i++)
        args[i - 1] = string(vec[i]);
}

Arguments::~Arguments()
{
    delete[] args;
    args = nullptr;
}

ostream &operator<<(ostream &o, ReadOnly<Arguments> a)
{
    o << "[ ";
    size_t len = a.length();
    for (size_t i = 0; i < len; i++)
        o << a[i] << (i < len - 1 ? ", " : "");
    return o << " ]";
}

Arguments::Iterator Arguments::begin() const { return Iterator(&args[0]); }

Arguments::Iterator Arguments::end() const { return Iterator(&args[len]); }