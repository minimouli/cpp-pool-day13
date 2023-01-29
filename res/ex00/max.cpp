/**
 * Copyright (c) Minimouli
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <iostream>
#include "Algorithm.hpp"


int main() {

    auto my_int_max = max<int>;
    std::cout << "max(24, 42) = " << my_int_max(24, 42) << std::endl;
    std::cout << "max(42, 24) = " << my_int_max(42, 24) << std::endl;
    std::cout << "max(10, -10) = " << my_int_max(10, -10) << std::endl;
    std::cout << "max(42, 42) = " << my_int_max(42, 42) << std::endl;

    const std::string hello = "hello";
    const std::string world = "world";

    auto my_string_max = max<std::string>;
    std::cout << "max(hello, world) = " << my_string_max(hello, world) << std::endl;
    std::cout << "max(world, hello) = " << my_string_max(world, hello) << std::endl;
    std::cout << "max(hello, hello) = " << my_string_max(hello, hello) << std::endl;

    return 0;
}
