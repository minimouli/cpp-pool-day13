/**
 * Copyright (c) Minimouli
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

import { GPP, Path, expect, suite, test } from '@minimouli/framework'

suite('Exercise 04', () => {

    test('Command', async () => {

        const gpp = new GPP([
            Path.fromMoulinette('./res/ex04/main.cpp'),
            Path.fromProject('./Command.cpp'),
            Path.fromProject('./Stack.cpp')
        ])
        const exec = await gpp.execute([
            `-I${Path.fromProject().toString()}`,
            '-std=c++20'
        ])
        await exec.execute()

        expect(exec).toExitWith(0)
        await expect(exec).toOutput([
            'command.registerCommand("push", function)',
            'command.registerCommand("display", function)',
            'command.registerCommand("add", function)',
            'command.registerCommand("sub", function)',
            'command.registerCommand("mul", function)',
            'command.registerCommand("div", function)',
            'command.registerCommand("push", function)',
            'Command::Error Already registered command',
            'command.executeCommand("push")',
            'push 4.2 to the stack',
            'command.executeCommand("push")',
            'push 4.2 to the stack',
            'command.executeCommand("push")',
            'push 4.2 to the stack',
            'command.executeCommand("push")',
            'push 4.2 to the stack',
            'command.executeCommand("push")',
            'push 4.2 to the stack',
            'command.executeCommand("add")',
            'command.executeCommand("display")',
            '8.4',
            'command.executeCommand("mul")',
            'command.executeCommand("display")',
            '35.28',
            'command.executeCommand("sub")',
            'command.executeCommand("display")',
            '31.08',
            'command.executeCommand("div")',
            'command.executeCommand("display")',
            '7.4',
            'command.executeCommand("mod")',
            'Command::Error Unknow command',
            ''
        ])
    })

})
