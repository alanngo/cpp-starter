#ifndef OBJECTS
#define OBJECTS
#include <memory>
#include "types.hpp"
using std::allocator;
using std::forward;


/**
 * quick and simple object creation file
 */
namespace objects
{
    // new and delete

    /**
     * constructs an object using new
     * @param args varargs for constructing anonymous object
     * @returns constructed object ptr
     */
    template <class E, class... Args>
    Ptr<E> construct(Args &&...args);

    /**
     * destroys and nullifies object using delete
     * @param ptr object to destroy
     */
    template <class E>
    void destroy(Ptr<E>);

    // allocator related

    /**
     * constructs and allocates an object using temp allocator
     * @param a allocator to use
     * @param args varargs for constructing anonymous object
     * @returns oconstructed object ptr
     */
    template <class E, class... Args>
    Ptr<E> construct(Tmp<allocator<E>>, Args &&...);

    /**
     * constructs and allocates an object using allocator
     * @param a allocator to use
     * @param args varargs for constructing anonymous object
     * @returns oconstructed object ptr
     */
    template <class E, class... Args>
    inline Ptr<E> construct(Ref<allocator<E>> a, Args &&...args) { return construct<E>(move(a), forward<Args>(args)...); }

    /**
     * destroys and deallocates an object using temp allocator
     * @param a allocator to use
     * @param ptr pointer to kill and nullify
     */
    template <class E>
    void destroy(Tmp<allocator<E>>, Ptr<E>);

    /**
     * destroys and deallocates an object using allocator
     * @param a allocator to use
     * @param ptr pointer to kill and nullify
     */
    template <class E>
    inline void destroy(Ref<allocator<E>> a, Ptr<E> ptr) { destroy(move(a), ptr); }

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
         * @param args arguments to forward in object constructor
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

        // disable move operations

        SmartPtr(Tmp<SmartPtr<E>>) = delete;
        SmartPtr &operator=(Tmp<SmartPtr<E>>) = delete;

    private:
        Ptr<E> p;
    };

};

#include "impl/objects.cpp"

#endif