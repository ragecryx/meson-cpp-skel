#ifndef TEST_LIBRARY_H
#define TEST_LIBRARY_H

class TestClass {
public:
    TestClass ();
    TestClass (int initialCount);
private:
    unsigned int mCount;
public:
    void Increment ();
    unsigned int GetCount () const;
};

TestClass MakeObject ();

#endif

