/**
 * Copyright (c) Minimouli
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <iostream>
#include "SharedPointer.hpp"
#include "../Logger.hpp"

int main() {

    std::cout << "create ptr1 without value" << std::endl;
    SharedPointer<Logger> ptr1;

    std::cout << "ptr1.get() = " << (ptr1.get() == nullptr ? "nullptr" : "not null") << std::endl;

    std::cout << "set ptr1 with Logger(1)" << std::endl;
    ptr1 = new Logger(1);

    std::cout << "ptr1.get() = " << (ptr1.get() == nullptr ? "nullptr" : "not null") << std::endl;
    std::cout << "ptr1->sayHello()" << std::endl;
    ptr1->sayHello();

    std::cout << "---" << std::endl;

    std::cout << "create ptr2 with new Logger(2)" << std::endl;
    SharedPointer ptr2(new Logger(2));

    std::cout << "ptr2->sayHello()" << std::endl;
    ptr2->sayHello();
    std::cout << "ptr2.get()->sayHello()" << std::endl;
    ptr2.get()->sayHello();

    std::cout << "ptr2.get() = " << (ptr2.get() == nullptr ? "nullptr" : "not null") << std::endl;
    std::cout << "ptr2.reset()" << std::endl;
    ptr2.reset();

    std::cout << "---" << std::endl;

    std::cout << "create ptr3 with new Logger(3)" << std::endl;
    SharedPointer ptr3(new Logger(3));

    std::cout << "ptr3->sayHello()" << std::endl;
    ptr3->sayHello();

    std::cout << "set ptr3 with new Logger(4)" << std::endl;
    ptr3 = new Logger(4);

    std::cout << "ptr3->sayHello()" << std::endl;
    ptr3->sayHello();

    std::cout << "---" << std::endl;

    std::cout << "create ptr4 with new Logger(5)" << std::endl;
    SharedPointer ptr4(new Logger(5));
    std::cout << "create ptr5 with ptr4" << std::endl;
    SharedPointer ptr5 = ptr4;
    std::cout << "create ptr6 without value" << std::endl;
    SharedPointer<Logger> ptr6;

    std::cout << "ptr4->sayHello()" << std::endl;
    ptr4->sayHello();
    std::cout << "ptr5->sayHello()" << std::endl;
    ptr5->sayHello();
    std::cout << "ptr6.get() = " << (ptr6.get() == nullptr ? "nullptr" : "not null") << std::endl;

    std::cout << "set ptr6 with ptr5" << std::endl;
    ptr6 = ptr5;

    std::cout << "ptr4->sayHello()" << std::endl;
    ptr4->sayHello();
    std::cout << "ptr5->sayHello()" << std::endl;
    ptr4->sayHello();
    std::cout << "ptr6->sayHello()" << std::endl;
    ptr4->sayHello();

    std::cout << "ptr5.reset()" << std::endl;
    ptr5.reset();

    std::cout << "ptr4->sayHello()" << std::endl;
    ptr4->sayHello();
    std::cout << "ptr6->sayHello()" << std::endl;
    ptr6->sayHello();

    std::cout << "set ptr4 with new Logger(6)" << std::endl;
    ptr4 = new Logger(6);

    std::cout << "ptr4->sayHello()" << std::endl;
    ptr4->sayHello();
    std::cout << "ptr6->sayHello()" << std::endl;
    ptr6->sayHello();

    std::cout << "set ptr6 with nullptr" << std::endl;
    ptr6 = nullptr;

    std::cout << "ptr4->sayHello()" << std::endl;
    ptr4->sayHello();
    std::cout << "ptr6.get() = " << (ptr6.get() == nullptr ? "nullptr" : "not null") << std::endl;

    std::cout << "---" << std::endl;

    return 0;
}
