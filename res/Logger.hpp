/**
 * Copyright (c) Minimouli
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#ifndef LOGGER_HPP
#define LOGGER_HPP

class Logger {
public:
    Logger(int id);
    ~Logger();

    void sayHello();

private:
    int id;
};

#endif
