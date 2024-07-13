#ifndef OBJECTS
#define OBJECTS
#include <memory>

using std::allocator;

namespace objects
{
    // new and delete

    /**
     * constructs an object using new
     * @param args varargs for constructing anonymous object
     * @returns oconstructed object ptr
     */
    template <class E, class... Args>
    inline E *construct(Args &&...);

    /**
     * destroys and nullifies object using delete
     * @param ptr object to destroy
     */
    template <class E>
    void destroy(E *);

    // allocator related
    /**
     * constructs and allocates an object using allocator
     * @param E object type
     * @param a allocator to use
     * @param args varargs for constructing anonymous object
     * @returns oconstructed object ptr
     */
    template <class E, class... Args>
    E *construct(allocator<E>&, Args &&...);

    /**
     * destroys and deallocates an object using allocator
     * @param E object type
     * @param a allocator to use
     */
    template <class E>
    void destroy(allocator<E>&, E *);
};

#include "objects.cpp"

#endif