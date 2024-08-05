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
     * @warning MUST USE rval-ref for allocator
     * @returns oconstructed object ptr
     */
    template <class E, class... Args>
    E *construct(allocator<E> &&, Args &&...);

    /**
     * destroys and deallocates an object using allocator
     * @param E object type
     * @param a allocator to use
     * @warning MUST USE rval-ref for allocator
     */
    template <class E>
    void destroy(allocator<E> &&, E *);

    /**
     * simple smart pointer that uses allocators
     * @warning only use if new/delete operators are deleted
     */
    template <class E, class Alloc = allocator<E>>
    class Ptr
    {
    public:
        /**
         * constructor
         */
        template <class... Args>
        explicit Ptr(Args &&...args) : p(construct<E>(Alloc(), forward<Args>(args)...)){};

        /**
         * destructor
         */
        ~Ptr() { destroy(Alloc(), p); }

        /**
         * derefrence operator
         * @returns ptr value
         */
        E &operator*() const { return *p; }

        /**
         * @returns stored ptr
         */
        E *operator->() const { return p; }

        // disable copy operations

        Ptr(const Ptr<E> &) = delete;
        Ptr & operator=(const Ptr<E>&) = delete;

    private:
        E *p;
    };
};

#include "objects.cpp"

#endif