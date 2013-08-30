/**
 @file uint128.h
 
 @maintainer Morgan McGuire, http://graphics.cs.williams.edu
 @author Kyle Whitson
 
 @created 2008-07-17
 @edited  2008-07-17
 */

#ifndef G3DLITE_UINT128_H
#define G3DLITE_UINT128_H

#include "G3DLite/g3dmath.h"

namespace G3DLite {

/** Limited functionality 128-bit unsigned integer. This is primarily to support FNV hashing and other
    cryptography applications.  See the GMP library for high-precision C++ math support. */
class uint128 {
public:

	G3DLite::uint64 hi;
	G3DLite::uint64 lo;

    uint128(const uint64& lo);

	uint128(const uint64& hi, const uint64& lo);

	uint128& operator+=(const uint128& x);

	uint128& operator*=(const uint128& x);

	uint128& operator^=(const uint128& x);

	uint128& operator&=(const uint128& x);

	uint128& operator|=(const uint128& x);

	bool operator==(const uint128& x);

    uint128& operator>>=(const int x);

    uint128& operator<<=(const int x);

    uint128 operator&(const uint128& x);

};
}

#endif