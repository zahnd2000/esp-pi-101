# Test Driven Development (TDD)

In Test Driven Development (TDD) you create code and test this code immediately.

For example, we want to create a `Calculator` class that does these arithmetic operations:
* `add` 
* `subtract`
* `multiply`
* `divide`.

In addition, we want to:
* get the `result` of the last operation
* `clear` any errors that have occurred
* use the `result` with the four arithmetic operations.

First, when we examine the requirements, we find this out:
* The class is *stateful* (*not stateless*), because it can remember the last result of any operation.
* The class can possibly support different data types (for example: `int`, `float`, `double`, `real`).

Then, we find this out:
* all arithmetic operations have 2 operands when they do not use the `result`.
* all arithmetic operations have 1 operand when they do *not* use the `result`.
* the `clear` method does not have any operands.

