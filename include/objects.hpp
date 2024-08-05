#ifndef OBJECTS
#define OBJECTS
#include <memory>
#include "types.hpp"
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
    inline Ptr<E> construct(Args &&...);

    /**
     * destroys and nullifies object using delete
     * @param ptr object to destroy
     */
    template <class E>
    void destroy(Ptr<E>);

    // allocator related
    /**
     * constructs and allocates an object using allocator
     * @param E object type
     * @param a allocator to use
     * @param args varargs for constructing anonymous object
     * @warning MUST USE rval-ref for allocator
     * @returns oconstructed object ptr
     */
    template <class E, class... Args>
    Ptr<E> construct(Tmp<allocator<E>> a, Args &&...);

    /**
     * destroys and deallocates an object using allocator
     * @param E object type
     * @param a allocator to use
     * @warning MUST USE rval-ref for allocator
     */
    template <class E>
    void destroy(Tmp<allocator<E>> a, E *);

    /**
     * simple smart pointer that uses allocators
     * @warning only use if new/delete operators are deleted
     */
    template <class E, class Alloc = allocator<E>>
    class SmartPtr
    {
    public:
        /**
         * constructor
         */
        template <class... Args>
        explicit SmartPtr(Args &&...args) : p(construct<E>(Alloc(), forward<Args>(args)...)){};

        /**
         * destructor
         */
        ~SmartPtr() { destroy(Alloc(), p); }

        /**
         * derefrence operator
         * @returns ptr value
         */
        Ref<E> operator*() const { return *p; }

        /**
         * @returns stored ptr
         */
        Ptr<E> operator->() const { return p; }

        // disable copy operations

        SmartPtr(ReadOnly<SmartPtr<E>>) = delete;
        SmartPtr &operator=(ReadOnly<SmartPtr<E>>) = delete;

    private:
        Ptr<E> p;
    };
};

#include "objects.cpp"

#endif