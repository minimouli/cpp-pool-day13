/**
 * Copyright (c) Minimouli
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

import { GPP, Path, expect, suite, test } from '@minimouli/framework'

suite('Exercise 00', () => {

    test('swap', async () => {

        const gpp = new GPP([
            Path.fromMoulinette('./res/ex00/swap.cpp')
        ])
        const exec = await gpp.execute([
            `-I${Path.fromProject().toString()}`,
            '-std=c++20'
        ])
        await exec.execute()

        expect(exec).toExitWith(0)
        await expect(exec).toOutput([
            'a = 24, b = 42',
            'swap(a, b)',
            'a = 42, b = 24',
            'c = hello, d = world',
            'swap(c, d)',
            'c = world, d = hello',
            ''
        ])
    })

    test('min', async () => {

        const gpp = new GPP([
            Path.fromMoulinette('./res/ex00/min.cpp')
        ])
        const exec = await gpp.execute([
            `-I${Path.fromProject().toString()}`,
            '-std=c++20'
        ])
        await exec.execute()

        expect(exec).toExitWith(0)
        await expect(exec).toOutput([
            'min(24, 42) = 24',
            'min(42, 24) = 24',
            'min(10, -10) = -10',
            'min(42, 42) = 42',
            'min(hello, world) = hello',
            'min(world, hello) = hello',
            'min(hello, hello) = hello',
            ''
        ])
    })

    test('max', async () => {

        const gpp = new GPP([
            Path.fromMoulinette('./res/ex00/max.cpp')
        ])
        const exec = await gpp.execute([
            `-I${Path.fromProject().toString()}`,
            '-std=c++20'
        ])
        await exec.execute()

        expect(exec).toExitWith(0)
        await expect(exec).toOutput([
            'max(24, 42) = 42',
            'max(42, 24) = 42',
            'max(10, -10) = 10',
            'max(42, 42) = 42',
            'max(hello, world) = world',
            'max(world, hello) = world',
            'max(hello, hello) = hello',
            ''
        ])
    })

    test('clamp', async () => {

        const gpp = new GPP([
            Path.fromMoulinette('./res/ex00/clamp.cpp')
        ])
        const exec = await gpp.execute([
            `-I${Path.fromProject().toString()}`,
            '-std=c++20'
        ])
        await exec.execute()

        expect(exec).toExitWith(0)
        await expect(exec).toOutput([
            'clamp(10, 24, 42) = 24',
            'clamp(24, 24, 42) = 24',
            'clamp(35, 24, 42) = 35',
            'clamp(42, 24, 42) = 42',
            'clamp(50, 24, 42) = 42',
            'clamp(arriba, hello, world) = hello',
            'clamp(hello, hello, world) = hello',
            'clamp(tchikita, hello, world) = tchikita',
            'clamp(world, hello, world) = world',
            'clamp(yogurt, hello, world) = world',
            ''
        ])
    })

})
