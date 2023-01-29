/**
 * Copyright (c) Minimouli
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

import { GPP, Path, expect, suite, test } from '@minimouli/framework'

suite('Exercise 05', () => {

    test('Shared Pointer', async () => {

        const gpp = new GPP([
            Path.fromMoulinette('./res/ex05/main.cpp'),
            Path.fromMoulinette('./res/Logger.cpp')
        ])
        const exec = await gpp.execute([
            `-I${Path.fromProject().toString()}`,
            '-std=c++20'
        ])
        await exec.execute()

        expect(exec).toExitWith(0)
        await expect(exec).toOutput([
            'create ptr1 without value',
            'ptr1.get() = nullptr',
            'set ptr1 with Logger(1)',
            '#1 -> construction',
            'ptr1.get() = not null',
            'ptr1->sayHello()',
            '#1 -> wesh alors',
            '---',
            'create ptr2 with new Logger(2)',
            '#2 -> construction',
            'ptr2->sayHello()',
            '#2 -> wesh alors',
            'ptr2.get()->sayHello()',
            '#2 -> wesh alors',
            'ptr2.get() = not null',
            'ptr2.reset()',
            '#2 -> destruction',
            '---',
            'create ptr3 with new Logger(3)',
            '#3 -> construction',
            'ptr3->sayHello()',
            '#3 -> wesh alors',
            'set ptr3 with new Logger(4)',
            '#4 -> construction',
            '#3 -> destruction',
            'ptr3->sayHello()',
            '#4 -> wesh alors',
            '---',
            'create ptr4 with new Logger(5)',
            '#5 -> construction',
            'create ptr5 with ptr4',
            'create ptr6 without value',
            'ptr4->sayHello()',
            '#5 -> wesh alors',
            'ptr5->sayHello()',
            '#5 -> wesh alors',
            'ptr6.get() = nullptr',
            'set ptr6 with ptr5',
            'ptr4->sayHello()',
            '#5 -> wesh alors',
            'ptr5->sayHello()',
            '#5 -> wesh alors',
            'ptr6->sayHello()',
            '#5 -> wesh alors',
            'ptr5.reset()',
            'ptr4->sayHello()',
            '#5 -> wesh alors',
            'ptr6->sayHello()',
            '#5 -> wesh alors',
            'set ptr4 with new Logger(6)',
            '#6 -> construction',
            'ptr4->sayHello()',
            '#6 -> wesh alors',
            'ptr6->sayHello()',
            '#5 -> wesh alors',
            'set ptr6 with nullptr',
            '#5 -> destruction',
            'ptr4->sayHello()',
            '#6 -> wesh alors',
            'ptr6.get() = nullptr',
            '---',
            '#6 -> destruction',
            '#4 -> destruction',
            '#1 -> destruction',
            ''
        ])
    })

})
