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
    array[0] = 68;
    array[1] = 94;
    array[2] = 50;
    array[3] = 32;
    array[4] = 98;

    std::cout << array << std::endl;

    auto floatArray = array.convert<float>([](const int &value) {
        return static_cast<float>(value) / 10.f;
    });

    std::cout << floatArray << std::endl;

    return 0;
}
