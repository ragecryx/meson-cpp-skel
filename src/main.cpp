#include <iostream>

#include <Library.h>

int main (int argc, char const *argv[]) {
    TestClass tc;
    std::cout << "Count is " << tc.GetCount () << std::endl;

    tc.Increment ();
    std::cout << "Count is " << tc.GetCount () << std::endl;

    return 0;
}

