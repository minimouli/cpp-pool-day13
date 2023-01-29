/**
 * Copyright (c) Minimouli
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

import { GPP, Path, expect, suite, test } from '@minimouli/framework'

suite('Exercise 02', () => {

    test('Stack', async () => {

        const gpp = new GPP([
            Path.fromProject('./Stack.cpp'),
            Path.fromMoulinette('./res/ex02/stack.cpp')
        ])
        const exec = await gpp.execute([
            `-I${Path.fromProject().toString()}`,
            '-std=c++20'
        ])
        await exec.execute()

        expect(exec).toExitWith(0)
        await expect(exec).toOutput([
            'stack.top() = Stack::Error Empty stack',
            'stack.pop()',
            'Stack::Error Empty stack',
            'stack.push(1.2)',
            'stack.top() = 1.2',
            'stack.push(3.4)',
            'stack.push(5.6)',
            'stack.pop() = 5.6',
            'stack.pop() = 3.4',
            'stack.top() = 1.2',
            ''
        ])
    })

    test('Operands', async () => {

        const gpp = new GPP([
            Path.fromProject('./Stack.cpp'),
            Path.fromMoulinette('./res/ex02/operands.cpp')
        ])
        const exec = await gpp.execute([
            `-I${Path.fromProject().toString()}`,
            '-std=c++20'
        ])
        await exec.execute()

        expect(exec).toExitWith(0)
        await expect(exec).toOutput([
            'stack.push(8.4)',
            'stack.top() = 8.4',
            'stack.add()',
            'Stack::Error Not enough operands',
            'stack.top() = 8.4',
            'stack.sub()',
            'Stack::Error Not enough operands',
            'stack.top() = 8.4',
            'stack.mul()',
            'Stack::Error Not enough operands',
            'stack.top() = 8.4',
            'stack.div()',
            'Stack::Error Not enough operands',
            'stack.push(8.2)',
            'stack.push(2.4)',
            'stack.push(17)',
            'stack.push(7.6)',
            'stack.add()',
            'stack.top() = 24.6',
            'stack.div()',
            'stack.top() = 10.25',
            'stack.mul()',
            'stack.top() = 84.05',
            'stack.sub()',
            'stack.pop() = 75.65',
            'stack.pop() = Stack::Error Empty stack',
            ''
        ])
    })

})
