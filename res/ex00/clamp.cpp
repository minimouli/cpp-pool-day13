/**
 * Copyright (c) Minimouli
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <iostream>
#include "Algorithm.hpp"

int main() {

    auto my_int_clamp = clamp<int>;
    std::cout << "clamp(10, 24, 42) = " << my_int_clamp(10, 24, 42) << std::endl;
    std::cout << "clamp(24, 24, 42) = " << my_int_clamp(24, 24, 42) << std::endl;
    std::cout << "clamp(35, 24, 42) = " << my_int_clamp(35, 24, 42) << std::endl;
    std::cout << "clamp(42, 24, 42) = " << my_int_clamp(42, 24, 42) << std::endl;
    std::cout << "clamp(50, 24, 42) = " << my_int_clamp(50, 24, 42) << std::endl;

    auto my_string_clamp = clamp<std::string>;
    std::cout << "clamp(arriba, hello, world) = " << my_string_clamp(std::string("arriba"), std::string("hello"), std::string("world")) << std::endl;
    std::cout << "clamp(hello, hello, world) = " << my_string_clamp(std::string("hello"), std::string("hello"), std::string("world")) << std::endl;
    std::cout << "clamp(tchikita, hello, world) = " << my_string_clamp(std::string("tchikita"), std::string("hello"), std::string("world")) << std::endl;
    std::cout << "clamp(world, hello, world) = " << my_string_clamp(std::string("world"), std::string("hello"), std::string("world")) << std::endl;
    std::cout << "clamp(yogurt, hello, world) = " << my_string_clamp(std::string("yogurt"), std::string("hello"), std::string("world")) << std::endl;

    return 0;
}
