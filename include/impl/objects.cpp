#include "objects.hpp"

using std::allocator_traits;

template <class E>
using Alloc = allocator_traits<allocator<E>>;

template <class E, class... Args>
Ptr<E> objects::construct(Tmp<allocator<E>> a, Args &&...args)
{
    E *ret = Alloc<E>::allocate(a, 1);
    Alloc<E>::construct(a, ret, forward<Args>(args)...);
    return ret;
}

template <class E>
void objects::destroy(Tmp<allocator<E>> a, E *ptr)
{
    Alloc<E>::destroy(a, ptr);
    Alloc<E>::deallocate(a, ptr, 1);
    ptr = nullptr;
}

template <class E, class... Args>
Ptr<E> objects::construct(Args &&...args) { return new E(forward<Args>(args)...); }

template <class E>
void objects::destroy(Ptr<E> ptr)
{
    delete ptr;
    ptr = nullptr;
}
