/**
 @file Color4uint8.cpp
 
 @author Morgan McGuire, http://graphics.cs.williams.edu
  
 @created 2003-04-07
 @edited  2006-01-07
 */
#include "G3DLite/platform.h"
#include "G3DLite/g3dmath.h"
#include "G3DLite/Color4uint8.h"
#include "G3DLite/Color4.h"
#include "G3DLite/BinaryInput.h"
#include "G3DLite/BinaryOutput.h"

namespace G3DLite {

Color4uint8::Color4uint8(const class Color4& c) {
    r = iMin(255, iFloor(c.r * 256));
    g = iMin(255, iFloor(c.g * 256));
    b = iMin(255, iFloor(c.b * 256));
    a = iMin(255, iFloor(c.a * 256));
}


Color4uint8::Color4uint8(class BinaryInput& bi) {
    deserialize(bi);
}


void Color4uint8::serialize(class BinaryOutput& bo) const {
    bo.writeUInt8(r);
    bo.writeUInt8(g);
    bo.writeUInt8(b);
    bo.writeUInt8(a);
}


void Color4uint8::deserialize(class BinaryInput& bi) {
    r = bi.readUInt8();
    g = bi.readUInt8();
    b = bi.readUInt8();
    a = bi.readUInt8();
}


}
