/**
 * Copyright (c) Minimouli
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <iostream>
#include "Array.hpp"

int main() {

    Array<int, 5> array;
    std::cout << array << std::endl;

    array[0] = 54;
    array[1] = 75;
    array[2] = 29;
    array[3] = 63;
    array[4] = 97;
    std::cout << array << std::endl;
    std::cout << "size: " << array.size() << std::endl;

    try {
        std::cout << "array[0] = " << array[0] << std::endl;
        std::cout << "array[1] = " << array[1] << std::endl;
        std::cout << "array[2] = " << array[2] << std::endl;
        std::cout << "array[3] = " << array[3] << std::endl;
        std::cout << "array[4] = " << array[4] << std::endl;
        std::cout << "array[5] = " << array[5] << std::endl;
    } catch (const std::exception &error) {
        std::cout << error.what() << std::endl;
    }

    std::cout << array << std::endl;

    return 0;
}
