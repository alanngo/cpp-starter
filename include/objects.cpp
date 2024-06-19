#include "objects.hpp"


template <class E, class... Args>
E *construct(Args &&...args) { return new E(forward<Args>(args)...); }

template <class E>
void destroy(E *ptr)
{
    delete ptr;
    ptr = nullptr;
}


template <class E, class... Args>
E *construct(allocator<E> a, Args &&...args)
{
    using Alloc = allocator_traits<allocator<E>>;
    E *ret = Alloc::allocate(a, 1);
    Alloc::construct(a, ret, forward<Args>(args)...);
    return ret;
}


template <class E>
void destroy(allocator<E> a, E *ptr)
{
    using Alloc = allocator_traits<allocator<E>>;
    Alloc::destroy(a, ptr);
    Alloc::deallocate(a, ptr, 1);
    ptr = nullptr;
}
