/**
 * Copyright (c) Minimouli
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <iostream>
#include "Algorithm.hpp"

int main() {

    auto my_int_min = min<int>;
    std::cout << "min(24, 42) = " << my_int_min(24, 42) << std::endl;
    std::cout << "min(42, 24) = " << my_int_min(42, 24) << std::endl;
    std::cout << "min(10, -10) = " << my_int_min(10, -10) << std::endl;
    std::cout << "min(42, 42) = " << my_int_min(42, 42) << std::endl;

    const std::string hello = "hello";
    const std::string world = "world";

    auto my_string_min = min<std::string>;
    std::cout << "min(hello, world) = " << my_string_min(std::string("hello"), std::string("world")) << std::endl;
    std::cout << "min(world, hello) = " << my_string_min(std::string("world"), std::string("hello")) << std::endl;
    std::cout << "min(hello, hello) = " << my_string_min(std::string("hello"), std::string("hello")) << std::endl;

    return 0;
}
