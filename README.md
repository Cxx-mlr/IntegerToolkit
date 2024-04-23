# Integer Toolkit

Integer Toolkit is a C library providing a comprehensive set of functions for manipulating and performing operations on integers. Whether you need to inspect, manipulate, search, or sort integers, this toolkit has you covered.

## Overview

The library is organized into several categories of functions:

1. **Integer Properties and Validation Functions**: Functions to determine properties of integers and validate their correctness.
2. **Integer Manipulation Functions**: Functions to manipulate the digits of integers, such as pushing, popping, inserting, and swapping.
3. **Integer Inspection Functions**: Functions to inspect the digits of integers, including peeking at digits and accessing digits at specific indices.
4. **Utility Functions**: General-purpose utility functions for integer manipulation, concatenation, and appending zeros.
5. **String-Like Functions**: Functions to treat integers as strings, such as checking for containment, checking prefixes/suffixes, and reversing.
6. **Search Functions**: Functions to search for specific digits or numbers within integers.
7. **Remove Functions**: Functions to remove digits or numbers from integers, including removing specific occurrences or based on custom conditions.
8. **Reduction Functions**: Functions to reduce integers to single values, such as summing digits or applying custom reduction operations.
9. **Range Functions**: Functions to generate ranges of integers or extract sub-integers from existing integers.
10. **Sorting Functions**: Functions to sort the digits of integers.
11. **Divisibility Functions**: Functions to check the divisibility of integers by specific numbers.

## Function Categories

### Integer Properties and Validation Functions

These functions allow you to determine properties of integers and validate their correctness:
- `length`: Calculate the number of digits in an integer.
- `is_empty`: Check if an integer is empty (zero).
- `in_range`: Check if an integer is within a specified range.
- `index_ok`: Check if an index is valid for a given integer.

### Integer Manipulation Functions

These functions allow you to manipulate the digits of integers:
- `push_front`: Insert a digit or number at the front of an integer.
- `push_back`: Insert a digit or number at the back of an integer.
- `pop_front_n`: Remove a specified number of digits from the front of an integer.
- `pop_back_n`: Remove a specified number of digits from the back of an integer.
- `pop_front`: Remove a digit from the front of an integer.
- `pop_back`: Remove a digit from the back of an integer.
- `insert`: Insert a digit or number at a specified index of an integer.

### Integer Inspection Functions

These functions allow you to inspect the digits of integers:
- `front_n`: Get the first n digits of an integer.
- `back_n`: Get the last n digits of an integer.
- `front`: Get the first digit of an integer.
- `back`: Get the last digit of an integer.
- `at`: Get the digit at a specified index of an integer.

### Utility Functions

These functions provide general-purpose utility for integer manipulation:
- `concat`: Concatenate multiple integers into a single integer.
- `with_zeros`: Append zeros to an integer.
- `set_digit`: Set the digit at a specified index of an integer.
- `swap`: Swap the digits at specified indices of an integer.

### String-Like Functions

These functions treat integers as strings:
- `contains`: Check if an integer contains a specific digit or number.
- `startswith`: Check if an integer starts with a specific digit or number.
- `endswith`: Check if an integer ends with a specific digit or number.
- `reversed`: Reverse the digits of an integer.

### Search Functions

These functions allow you to search for specific digits or numbers within integers:
- `find_first_of`: Find the index of the first occurrence of a specific digit or number.
- `find_last_of`: Find the index of the last occurrence of a specific digit or number.

### Remove Functions

These functions allow you to remove digits or numbers from integers:
- `remove_first_of`: Remove the first occurrence of a specific digit or number.
- `remove_last_of`: Remove the last occurrence of a specific digit or number.
- `remove_all`: Remove all occurrences of a specific digit or number.
- `remove_digit_if`: Remove digits based on custom conditions.
- `count_occurrences_of`: Count the number of occurrences of a specific digit or number.
- `max_digit`: Find the maximum digit in an integer.
- `min_digit`: Find the minimum digit in an integer.

### Reduction Functions

These functions allow you to reduce integers to single values:
- `reduce`: Reduce an integer using a binary operation and initial value.
- `sum_digits`: Calculate the sum of digits in an integer.

### Range Functions

These functions allow you to generate ranges of integers or extract sub-integers:
- `range`: Generate a range of integers with a specified start, stop, and step size.
- `number_from_to`: Extract a sub-integer from an existing integer.

### Sorting Functions

These functions allow you to sort the digits of integers:
- `bubble_sort`: Sort the digits of an integer using the bubble sort algorithm.

### Divisibility Functions

These functions allow you to check the divisibility of integers by specific numbers:
- `divisible_by_2`: Check if an integer is divisible by 2.
- `divisible_by_3`: Check if an integer is divisible by 3.
- `divisible_by_4`: Check if an integer is divisible by 4.
- `divisible_by_5`: Check if an integer is divisible by 5.

## Usage

To use the Integer Toolkit library in your C project, simply include the `integer_toolkit.h` header file and link against the corresponding `integer_toolkit.c` source file. Then, you can call any of the provided functions as needed to perform integer manipulation and operations.

```c
#include "integer_toolkit.h"
#include <stdio.h>

int main() {
    int number = 12345;
    printf("Number of digits: %u\n", length(number));
    // Other function calls...
    return 0;
}
