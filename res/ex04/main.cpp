/**
 * Copyright (c) Minimouli
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <iostream>
#include "Command.hpp"
#include "Stack.hpp"

int main() {

    Command command;
    Stack stack;

    try {

        std::cout << "command.registerCommand(\"push\", function)" << std::endl;
        command.registerCommand("push", [&stack]() {
            std::cout << "push 4.2 to the stack" << std::endl;
            stack.push(4.2);
        });

        std::cout << "command.registerCommand(\"display\", function)" << std::endl;
        command.registerCommand("display", [&stack]() {
            std::cout << stack.top() << std::endl;
        });

        std::cout << "command.registerCommand(\"add\", function)" << std::endl;
        command.registerCommand("add", [&stack]() {
            stack.add();
        });

        std::cout << "command.registerCommand(\"sub\", function)" << std::endl;
        command.registerCommand("sub", [&stack]() {
            stack.sub();
        });

        std::cout << "command.registerCommand(\"mul\", function)" << std::endl;
        command.registerCommand("mul", [&stack]() {
            stack.mul();
        });

        std::cout << "command.registerCommand(\"div\", function)" << std::endl;
        command.registerCommand("div", [&stack]() {
            stack.div();
        });

        std::cout << "command.registerCommand(\"push\", function)" << std::endl;
        command.registerCommand("display", [&stack]() {
            std::cout << stack.top() << std::endl;
        });

    } catch (const Command::Error &error) {
        std::cout << "Command::Error " << error.what() << std::endl;
    } catch (const std::exception &error) {
        std::cout << "std::exception " << error.what() << std::endl;
    }

    std::cout << "command.executeCommand(\"push\")" << std::endl;
    command.executeCommand("push");
    std::cout << "command.executeCommand(\"push\")" << std::endl;
    command.executeCommand("push");
    std::cout << "command.executeCommand(\"push\")" << std::endl;
    command.executeCommand("push");
    std::cout << "command.executeCommand(\"push\")" << std::endl;
    command.executeCommand("push");
    std::cout << "command.executeCommand(\"push\")" << std::endl;
    command.executeCommand("push");

    std::cout << "command.executeCommand(\"add\")" << std::endl;
    command.executeCommand("add");
    std::cout << "command.executeCommand(\"display\")" << std::endl;
    command.executeCommand("display");

    std::cout << "command.executeCommand(\"mul\")" << std::endl;
    command.executeCommand("mul");
    std::cout << "command.executeCommand(\"display\")" << std::endl;
    command.executeCommand("display");

    std::cout << "command.executeCommand(\"sub\")" << std::endl;
    command.executeCommand("sub");
    std::cout << "command.executeCommand(\"display\")" << std::endl;
    command.executeCommand("display");

    std::cout << "command.executeCommand(\"div\")" << std::endl;
    command.executeCommand("div");
    std::cout << "command.executeCommand(\"display\")" << std::endl;
    command.executeCommand("display");

    try {
        std::cout << "command.executeCommand(\"mod\")" << std::endl;
        command.executeCommand("mod");
    } catch (const Command::Error &error) {
        std::cout << "Command::Error " << error.what() << std::endl;
    } catch (const std::exception &error) {
        std::cout << "std::exception " << error.what() << std::endl;
    }

    return 0;
}
