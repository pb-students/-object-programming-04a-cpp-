#include <iostream>
#include "array.h"

int main() {
    Array ar1(5);
    ar1.set(0, 3);
    ar1.set(1, 7);
    ar1.set(2, 5);
    ar1.print();

    // What kind of person one has to be to not use std:: ?
    // "\n" is faster to type than std::endl though...
    std::cout << ar1.get(1) << std::endl;
    std::cout << ar1.size() << std::endl;

    std::cout << sum(ar1) << std::endl;

    auto ar2 = create(5);
    ar2.print();

    ar2 = create(5);
    ar2 = ar1;

    Array ar(5);
    ar[0] = 1;
    std::cout << ar[0] << std::endl;
    std::cout << ar << std::endl;
}
