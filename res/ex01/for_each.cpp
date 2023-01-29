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
    array[0] = 81;
    array[1] = 38;
    array[2] = 69;
    array[3] = 93;
    array[4] = 18;

    std::cout << array << std::endl;

    array.forEach([](const int &value) {
        std::cout << value << std::endl;
    });

    std::cout << array << std::endl;

    return 0;
}
