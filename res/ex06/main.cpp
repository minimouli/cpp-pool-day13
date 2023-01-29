/**
 * Copyright (c) Minimouli
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <iostream>
#include <string>
#include "Shell.hpp"
#include "Stack.hpp"
#include "Command.hpp"

int main() {

    Shell shell(std::cin);
    Stack stack;
    Command command;

    command.registerCommand("push", [&shell, &stack]() {
        stack.push(shell.extract<double>());
    });
    command.registerCommand("pop", [&shell, &stack]() {
        stack.pop();
    });
    command.registerCommand("display", [&stack]() {
        std::cout << stack.top() << std::endl;
    });
    command.registerCommand("add", [&stack]() {
        stack.add();
    });
    command.registerCommand("sub", [&stack]() {
        stack.sub();
    });
    command.registerCommand("mul", [&stack]() {
        stack.mul();
    });
    command.registerCommand("div", [&stack]() {
        stack.div();
    });
    command.registerCommand("echo-int", [&shell]() {
        std::cout << shell.extract<int>() << std::endl;
    });
    command.registerCommand("echo-string", [&shell]() {
        std::cout << shell.extract<std::string>() << std::endl;
    });

    while (true) {

        try {

            std::cout << "> " << std::flush;
            shell.next();

            command.executeCommand(shell.extract<std::string>());

        } catch (const Shell::Error &error) {
            std::cout << "Shell:Error " << error.what() << std::endl;
            break;
        } catch (const Shell::Warning &warning) {
            std::cout << "Shell:Warning " << warning.what() << std::endl;
            continue;
        } catch (const std::exception &error) {
            std::cout << "std::exception " << error.what() << std::endl;
            continue;
        }

    }

    return 0;
}
