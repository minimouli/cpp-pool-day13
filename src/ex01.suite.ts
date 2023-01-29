/**
 * Copyright (c) Minimouli
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

import { GPP, Path, expect, suite, test } from '@minimouli/framework'

suite('Exercise 01', () => {

    test('Setter and Getter', async () => {

        const gpp = new GPP([
            Path.fromMoulinette('./res/ex01/setter_getter.cpp')
        ])
        const exec = await gpp.execute([
            `-I${Path.fromProject().toString()}`,
            '-std=c++20'
        ])
        await exec.execute()

        expect(exec).toExitWith(0)
        await expect(exec).toOutput([
            '[0, 0, 0, 0, 0]',
            '[54, 75, 29, 63, 97]',
            'size: 5',
            'array[0] = 54',
            'array[1] = 75',
            'array[2] = 29',
            'array[3] = 63',
            'array[4] = 97',
            'array[5] = Out of range',
            '[54, 75, 29, 63, 97]',
            ''
        ])
    })

    test('For each', async () => {

        const gpp = new GPP([
            Path.fromMoulinette('./res/ex01/for_each.cpp')
        ])
        const exec = await gpp.execute([
            `-I${Path.fromProject().toString()}`,
            '-std=c++20'
        ])
        await exec.execute()

        expect(exec).toExitWith(0)
        await expect(exec).toOutput([
            '[81, 38, 69, 93, 18]',
            '81',
            '38',
            '69',
            '93',
            '18',
            '[81, 38, 69, 93, 18]',
            ''
        ])
    })

    test('Convert', async () => {

        const gpp = new GPP([
            Path.fromMoulinette('./res/ex01/convert.cpp')
        ])
        const exec = await gpp.execute([
            `-I${Path.fromProject().toString()}`,
            '-std=c++20'
        ])
        await exec.execute()

        expect(exec).toExitWith(0)
        await expect(exec).toOutput([
            '[68, 94, 50, 32, 98]',
            '[6.8, 9.4, 5, 3.2, 9.8]',
            ''
        ])
    })

})
