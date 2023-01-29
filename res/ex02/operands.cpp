/**
 * Copyright (c) Minimouli
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <iostream>
#include "Stack.hpp"

int main() {

    Stack stack;

    std::cout << "stack.push(8.4)" << std::endl;
    stack.push(8.4);

    try {
        std::cout << "stack.top() = " << stack.top() << std::endl;
        std::cout << "stack.add()" << std::endl;
        stack.add();
    } catch (const Stack::Error &error) {
        std::cout << "Stack::Error " << error.what() << std::endl;
    } catch (const std::exception &error) {
        std::cout << "std::exception " << error.what() << std::endl;
    }

    try {
        std::cout << "stack.top() = " << stack.top() << std::endl;
        std::cout << "stack.sub()" << std::endl;
        stack.sub();
    } catch (const Stack::Error &error) {
        std::cout << "Stack::Error " << error.what() << std::endl;
    } catch (const std::exception &error) {
        std::cout << "std::exception " << error.what() << std::endl;
    }

    try {
        std::cout << "stack.top() = " << stack.top() << std::endl;
        std::cout << "stack.mul()" << std::endl;
        stack.mul();
    } catch (const Stack::Error &error) {
        std::cout << "Stack::Error " << error.what() << std::endl;
    } catch (const std::exception &error) {
        std::cout << "std::exception " << error.what() << std::endl;
    }

    try {
        std::cout << "stack.top() = " << stack.top() << std::endl;
        std::cout << "stack.div()" << std::endl;
        stack.div();
    } catch (const Stack::Error &error) {
        std::cout << "Stack::Error " << error.what() << std::endl;
    } catch (const std::exception &error) {
        std::cout << "std::exception " << error.what() << std::endl;
    }

    std::cout << "stack.push(8.2)" << std::endl;
    stack.push(8.2);
    std::cout << "stack.push(2.4)" << std::endl;
    stack.push(2.4);
    std::cout << "stack.push(17)" << std::endl;
    stack.push(17);
    std::cout << "stack.push(7.6)" << std::endl;
    stack.push(7.6);

    std::cout << "stack.add()" << std::endl;
    stack.add();
    std::cout << "stack.top() = " << stack.top() << std::endl;

    std::cout << "stack.div()" << std::endl;
    stack.div();
    std::cout << "stack.top() = " << stack.top() << std::endl;

    std::cout << "stack.mul()" << std::endl;
    stack.mul();
    std::cout << "stack.top() = " << stack.top() << std::endl;

    std::cout << "stack.sub()" << std::endl;
    stack.sub();
    std::cout << "stack.pop() = " << stack.pop() << std::endl;

    try {
        std::cout << "stack.pop() = " << stack.pop() << std::endl;
    } catch (const Stack::Error &error) {
        std::cout << "Stack::Error " << error.what() << std::endl;
    } catch (const std::exception &error) {
        std::cout << "std::exception " << error.what() << std::endl;
    }

    return 0;
}
