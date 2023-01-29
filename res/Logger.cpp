/**
 * Copyright (c) Minimouli
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <iostream>
#include "Logger.hpp"

Logger::Logger(int id) {
    std::cout << "#" << id << " -> construction" << std::endl;
    this->id = id;
}

Logger::~Logger() {
    std::cout << "#" << id << " -> destruction" << std::endl;
}

void Logger::sayHello() {
    std::cout << "#" << id << " -> wesh alors" << std::endl;
}
