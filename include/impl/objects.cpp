#include "objects.hpp"
#include <type_traits>
#include <stdexcept>

using std::allocator_traits;
using std::is_destructible;
using std::runtime_error;
template <class E>
using Alloc = allocator_traits<allocator<E>>;

template<class E>
inline void checkDestructible()
{
    static_assert(is_destructible<E>(), "Object has a deleted destructor!");
}

template <class E, class... Args>
Ptr<E> objects::construct(Args &&...args)
{
    checkDestructible<E>();
    return new E(forward<Args>(args)...);
}

template <class E, class... Args>
Ptr<E> objects::construct(Tmp<allocator<E>> a, Args &&...args)
{
    checkDestructible<E>();
    Ptr<E> ret = Alloc<E>::allocate(a, 1);
    Alloc<E>::construct(a, ret, forward<Args>(args)...);
    return ret;
}

template <class E>
void objects::destroy(Tmp<allocator<E>> a, Ptr<E> ptr)
{
    Alloc<E>::destroy(a, ptr);
    Alloc<E>::deallocate(a, ptr, 1);
    ptr = nullptr;
}

template <class E>
void objects::destroy(Ptr<E> ptr)
{
    delete ptr;
    ptr = nullptr;
}
