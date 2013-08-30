/**
 @file debug.h

 @maintainer Morgan McGuire, http://graphics.cs.williams.edu

 @created 2001-08-26
 @edited  2006-02-16

  Copyright 2000-2006, Morgan McGuire.
 All rights reserved.
*/

#ifndef G3DLITE_DEBUG_H
#define G3DLITE_DEBUG_H

#include "G3DLite/platform.h"
#ifdef _MSC_VER
    #include <crtdbg.h>
#endif

#include "G3DLite/debugPrintf.h"
//#include "G3DLite/debugAssert.h"

namespace G3DLite {

#ifdef _MSC_VER
    // Turn off 64-bit warnings
#   pragma warning(push)
#   pragma warning( disable : 4312)
#   pragma warning( disable : 4267)
#   pragma warning( disable : 4311)
#endif


/**
 Useful for debugging purposes.
 */
inline bool isValidHeapPointer(const void* x) {
    #ifdef _MSC_VER
        return 
            (x != (void*)0xcccccccc) && (x != (void*)0xdeadbeef) && (x != (void*)0xfeeefeee);
    #else
        return x != NULL;
    #endif
}

/**
 Returns true if the pointer is likely to be
 a valid pointer (instead of an arbitrary number). 
 Useful for debugging purposes.
 */
inline bool isValidPointer(const void* x) {
    #ifdef _MSC_VER
        return x != ((void*)0xcccccccc) && (x != (void*)0xdeadbeef) && (x != (void*)0xfeeefeee);
    #else
        return x != NULL;
    #endif
}

#ifdef _MSC_VER
#   pragma warning(pop)
#endif

}

#endif