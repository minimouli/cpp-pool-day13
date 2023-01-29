/**
 * Copyright (c) Minimouli
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <iostream>
#include <string>
#include "Algorithm.hpp"

int main() {

    int a = 24;
    int b = 42;

    auto my_int_swap = swap<int>;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "swap(a, b)" << std::endl;
    my_int_swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;

    std::string c = "hello";
    std::string d = "world";

    auto my_string_swap = swap<std::string>;
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "swap(c, d)" << std::endl;
    my_string_swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;

    return 0;
}
