#include "objects.hpp"

template <class E, class... Args>
E *objects::construct(Args &&...args) { return new E(forward<Args>(args)...); }

template <class E>
void objects::destroy(E *ptr)
{
    delete ptr;
    ptr = nullptr;
}

template <class E>
using Alloc = allocator_traits<allocator<E>>;

template <class E, class... Args>
E *objects::construct(allocator<E> &a, Args &&...args)
{
    E *ret = Alloc<E>::allocate(a, 1);
    Alloc<E>::construct(a, ret, forward<Args>(args)...);
    return ret;
}

template <class E>
void objects::destroy(allocator<E> &a, E *ptr)
{
    Alloc<E>::destroy(a, ptr);
    Alloc<E>::deallocate(a, ptr, 1);
    ptr = nullptr;
}
