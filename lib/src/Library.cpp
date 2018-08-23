#include "Library.h"

TestClass::TestClass () : mCount(0) { }
TestClass::TestClass (int initialCount) : mCount(initialCount) { }

void TestClass::Increment () {
    ++mCount;
}

unsigned int TestClass::GetCount () const {
    return mCount;
}

