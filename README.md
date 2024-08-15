# BigInt Library

## Overview

The BigInt library provides functionality for performing arithmetic, bitwise operations, and number theory computations on arbitrarily large integers represented as strings. It offers both a function-based API and a class-based implementation, allowing flexibility in how you interact with the library.

### Key Features
- **Basic Arithmetic Operations**: Addition, subtraction, multiplication, and division.
- **Bitwise Operations**: AND, OR, XOR, NOT, and bit shifts.
- **Number Theory Functions**: Prime checking, GCD, LCM, and modular exponentiation.
- **Comparison Functions**: Greater than, less than, equal to, and their variants.

## Function-Based API

These functions can be used without instantiating the `BigInt` class. All inputs and outputs are strings unless specified otherwise.

### Basic Operations
- **Add(A, B)**: Returns the sum of `A` and `B`.
- **Subtract(A, B)**: Returns the difference between `A` and `B`.
- **Multiply(A, B)**: Returns the product of `A` and `B`.
- **Divide(A, B)**: Returns the integer division of `A` by `B`.
- **Pow(A, B)**: Returns `A` raised to the power of `B`.
- **Abs(A)**: Returns the absolute value of `A`.

### Bitwise Operations
- **AND(A, B)**: Returns the bitwise AND of `A` and `B`.
- **OR(A, B)**: Returns the bitwise OR of `A` and `B`.
- **XOR(A, B)**: Returns the bitwise XOR of `A` and `B`.
- **NOT(A)**: Returns the bitwise NOT of `A`.
- **Left_Shift(A, B)**: Shifts `A` left by `B` places. `B` can be an integer.
- **Right_Shift(A, B)**: Shifts `A` right by `B` places. `B` can be an integer.

### Number Theory
- **Is_Prime(A)**: Checks if `A` is a prime number using a probabilistic algorithm.
- **GCD(A, B)**: Returns the greatest common divisor of `A` and `B`.
- **LCM(A, B)**: Returns the least common multiple of `A` and `B`.
- **Pow_Mod(A, B, N)**: Returns `A` raised to the power of `B` modulus `N`.
- **Rand(length)**: Generates a random number string with a length up to `length`.

### Comparison Functions
- **Greater_Than_Equal(A, B)**: Returns `True` if `A` is greater than or equal to `B`.
- **Greater_Than(A, B)**: Returns `True` if `A` is greater than `B`.
- **Equal(A, B)**: Returns `True` if `A` is equal to `B`.
- **Less_Than_Equal(A, B)**: Returns `True` if `A` is less than or equal to `B`.
- **Less_Than(A, B)**: Returns `True` if `A` is less than `B`.

## Class-Based API

Using the `BigInt` class allows you to encapsulate the operations in a more object-oriented manner.

### Basic Operations
- **add(A, B)**: Returns the sum of `A` and `B`.
- **subtract(A, B)**: Returns the difference between `A` and `B`.
- **multiply(A, B)**: Returns the product of `A` and `B`.
- **divide(A, B)**: Returns the integer division of `A` by `B`.
- **Pow(A, B)**: Returns `A` raised to the power of `B`.
- **ABS(A)**: Returns the absolute value of `A`.

### Bitwise Operations
- **bin_AND(A, B)**: Returns the bitwise AND of `A` and `B`.
- **bin_OR(A, B)**: Returns the bitwise OR of `A` and `B`.
- **bin_XOR(A, B)**: Returns the bitwise XOR of `A` and `B`.
- **bin_NOT(A)**: Returns the bitwise NOT of `A`.
- **bin_left_shift(A, B)**: Shifts `A` left by `B` places. `B` can be an integer.
- **bin_right_shift(A, B)**: Shifts `A` right by `B` places. `B` can be an integer.

### Number Theory
- **IS_PRIME(A)**: Checks if `A` is a prime number using a probabilistic algorithm.
- **GCD(A, B)**: Returns the greatest common divisor of `A` and `B`.
- **LCM(A, B)**: Returns the least common multiple of `A` and `B`.
- **Pow_Mod(A, B, N)**: Returns `A` raised to the power of `B` modulus `N`.
- **Rand(length)**: Generates a random number string with a length up to `length`.

### Comparison Functions
- **Greater_Than_Equal(A, B)**: Returns `True` if `A` is greater than or equal to `B`.
- **Greater_Than(A, B)**: Returns `True` if `A` is greater than `B`.
- **Equal(A, B)**: Returns `True` if `A` is equal to `B`.
- **Less_Than_Equal(A, B)**: Returns `True` if `A` is less than or equal to `B`.
- **Less_Than(A, B)**: Returns `True` if `A` is less than `B`.

## License

This project is licensed under the MIT License. See the LICENSE file for details.

---

This README provides an overview of the BigInt library's capabilities and instructions for its use. Feel free to expand upon this document based on your project needs.
