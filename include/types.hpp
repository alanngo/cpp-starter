#ifndef TYPES
#define TYPES

// pointers and references

/**
 * pointer type
 */
template <class E>
using Ptr = E *;

/**
 * reference type, for modifiable l-values
 */
template <class E>
using Ref = E &;

/**
 * const reference type, for non-modifiable lvalues or rvalues
 */
template <class E>
using ReadOnly = const E &;

/**
 * rval reference type, for modifiable rvalues
 */
template <class E>
using Tmp = E &&;

// strings

using cstring = const char *;

#endif