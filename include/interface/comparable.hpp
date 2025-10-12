#ifndef COMPARABLE
#define COMPARABLE
#include "../constants/types.hpp"

/**
 * Enforces implementation of equality checking for derived class
 */
template <class E>
struct Equals
{
    /**
     * checks if object is equal to another (MUST OVERRIDE)
     * @param e object to check against
     * @returns true if both classes are equal
     */
    virtual bool operator==(ReadOnly<E>) = 0;

    /**
     * checks if object is NOT equal to another
     * @param e object to check against
     * @returns true if both object are NOT equal
     */
    virtual bool operator!=(ReadOnly<E> e) { return !(*this == e); }
};

/**
 * Enforces implementation of comparison for derived class
 */
template <class E>
struct CompareTo : public Equals<E>
{
    /**
     * checks if object is less than another (MUST OVERRIDE)
     * @param e object to check against
     * @returns true if object is less than other
     */
    virtual bool operator<(ReadOnly<E>) = 0;

    /**
     * checks if object is greater than another (MUST OVERRIDE)
     * @param e object to check against
     * @returns true if object is greater than other
     */
    virtual bool operator>(ReadOnly<E>) = 0;

    /**
     * checks if object is less than or equal to another
     * @param e object to check against
     * @returns true if object is less than or equal to other
     */
    virtual bool operator<=(ReadOnly<E> e) { return *this < e || *this == e; }

    /**
     * checks if object is greater than or equal to another
     * @param e object to check against
     * @returns true if object is greater than or equal to other
     */
    virtual bool operator>=(ReadOnly<E> e) { return *this > e || *this == e; }
};

/**
 * Enforces converting derived class to bo0lean
 */
template <class E>
struct Boolean
{
    /**
     * Makes object a boolean during checks
     * @returns boolean representation of object
     */
    virtual explicit operator bool() = 0;
};

#endif