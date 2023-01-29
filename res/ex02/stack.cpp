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

    try {
        std::cout << "stack.top() = " << stack.top() << std::endl;
    } catch (const Stack::Error &error) {
        std::cout << "Stack::Error " << error.what() << std::endl;
    } catch (const std::exception &error) {
        std::cout << "std::exception " << error.what() << std::endl;
    }

    try {
        std::cout << "stack.pop()" << std::endl;
        stack.pop();
    } catch (const Stack::Error &error) {
        std::cout << "Stack::Error " << error.what() << std::endl;
    } catch (const std::exception &error) {
        std::cout << "std::exception " << error.what() << std::endl;
    }

    std::cout << "stack.push(1.2)" << std::endl;
    stack.push(1.2);
    std::cout << "stack.top() = " << stack.top() << std::endl;
    std::cout << "stack.push(3.4)" << std::endl;
    stack.push(3.4);
    std::cout << "stack.push(5.6)" << std::endl;
    stack.push(5.6);
    std::cout << "stack.pop() = " << stack.pop() << std::endl;
    std::cout << "stack.pop() = " << stack.pop() << std::endl;
    std::cout << "stack.top() = " << stack.top() << std::endl;

    return 0;
}
