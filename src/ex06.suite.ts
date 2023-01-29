/**
 * Copyright (c) Minimouli
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

import { GPP, Path, expect, suite, test } from '@minimouli/framework'

suite('Exercise 06', () => {

    test('Types', async () => {

        const gpp = new GPP([
            Path.fromMoulinette('./res/ex06/main.cpp'),
            Path.fromProject('./Command.cpp'),
            Path.fromProject('./Shell.cpp'),
            Path.fromProject('./Stack.cpp')
        ])
        const exec = await gpp.execute([
            `-I${Path.fromProject().toString()}`,
            '-std=c++20'
        ])

        exec.setStdin([
            'echo-int 0',
            'echo-int 42',
            'echo-int +42',
            'echo-int -42',
            'echo-int 2147483648',
            'echo-int hello',
            'echo-int',
            'echo-string hello',
            'echo-string hello 42',
            'echo-string',
            ''
        ])

        await exec.execute()

        expect(exec).toExitWith(0)
        await expect(exec).toOutput([
            '> 0',
            '> 42',
            '> 42',
            '> -42',
            '> Shell:Warning Invalid conversion',
            '> Shell:Warning Invalid conversion',
            '> Shell:Warning Invalid conversion',
            '> hello',
            '> hello',
            '> Shell:Warning Invalid conversion',
            '> Shell:Error End of input',
            ''
        ])
    })

    test('Rigor', async () => {

        const gpp = new GPP([
            Path.fromMoulinette('./res/ex06/main.cpp'),
            Path.fromProject('./Command.cpp'),
            Path.fromProject('./Shell.cpp'),
            Path.fromProject('./Stack.cpp')
        ])
        const exec = await gpp.execute([
            `-I${Path.fromProject().toString()}`,
            '-std=c++20'
        ])

        exec.setStdin([
            'magic',
            'magic power',
            '   echo-int 42',
            'echo-int    42',
            'echo-int 42    ',
            '   echo-int    42   ',
            ''
        ])

        await exec.execute()

        expect(exec).toExitWith(0)
        await expect(exec).toOutput([
            '> std::exception Unknow command',
            '> std::exception Unknow command',
            '> 42',
            '> 42',
            '> 42',
            '> 42',
            '> Shell:Error End of input',
            ''
        ])
    })

    test('Stack', async () => {

        const gpp = new GPP([
            Path.fromMoulinette('./res/ex06/main.cpp'),
            Path.fromProject('./Command.cpp'),
            Path.fromProject('./Shell.cpp'),
            Path.fromProject('./Stack.cpp')
        ])
        const exec = await gpp.execute([
            `-I${Path.fromProject().toString()}`,
            '-std=c++20'
        ])

        exec.setStdin([
            'display',
            'push 8.4',
            'display',
            'add',
            'push 8.2',
            'push 2.4',
            'push 17',
            'push +7.6',
            'add',
            'display',
            'div',
            'display',
            'mul',
            'display',
            'sub',
            'display',
            'mod',
            'display',
            'add',
            'pop',
            'display',
            ''
        ])

        await exec.execute()

        expect(exec).toExitWith(0)
        await expect(exec).toOutput([
            '> std::exception Empty stack',
            '> > 8.4',
            '> std::exception Not enough operands',
            '> > > > > > 24.6',
            '> > 10.25',
            '> > 84.05',
            '> > 75.65',
            '> std::exception Unknow command',
            '> 75.65',
            '> std::exception Not enough operands',
            '> > std::exception Empty stack',
            '> Shell:Error End of input',
            ''
        ])
    })

})
