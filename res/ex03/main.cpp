/**
 * Copyright (c) Minimouli
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <iostream>
#include "UniquePointer.hpp"
#include "../Logger.hpp"

int main() {

    std::cout << "create ptr1 without value" << std::endl;
    UniquePointer<Logger> ptr1;

    std::cout << "ptr1.get() = " << (ptr1.get() == nullptr ? "nullptr" : "not null") << std::endl;

    std::cout << "set ptr1 with Logger(1)" << std::endl;
    ptr1 = new Logger(1);

    std::cout << "ptr1.get() = " << (ptr1.get() == nullptr ? "nullptr" : "not null") << std::endl;
    std::cout << "ptr1->sayHello()" << std::endl;
    ptr1->sayHello();

    std::cout << "---" << std::endl;

    std::cout << "create ptr2 with new Logger(2)" << std::endl;
    UniquePointer ptr2(new Logger(2));

    std::cout << "ptr2->sayHello()" << std::endl;
    ptr2->sayHello();
    std::cout << "ptr2.get()->sayHello()" << std::endl;
    ptr2.get()->sayHello();

    std::cout << "ptr2.get() = " << (ptr2.get() == nullptr ? "nullptr" : "not null") << std::endl;
    std::cout << "ptr2.reset()" << std::endl;
    ptr2.reset();
    std::cout << "ptr2.get() = " << (ptr2.get() == nullptr ? "nullptr" : "not null") << std::endl;

    std::cout << "---" << std::endl;

    std::cout << "create ptr3 with new Logger(3)" << std::endl;
    UniquePointer ptr3(new Logger(3));

    std::cout << "ptr3->sayHello()" << std::endl;
    ptr3->sayHello();

    std::cout << "set ptr3 with new Logger(4)" << std::endl;
    ptr3 = new Logger(4);

    std::cout << "ptr3->sayHello()" << std::endl;
    ptr3->sayHello();

    std::cout << "---" << std::endl;

    return 0;
}
