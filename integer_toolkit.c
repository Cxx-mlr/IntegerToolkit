#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <stdarg.h>

// UTILITY FUNCTIONS

unsigned int length(int number) {
    if (number == 0) return 1;
    return (unsigned int) floor(log10(fabs(number))) + 1;
}

int is_empty(int number) {
    return number == 0;
}

int index_ok(int number, int index) {
    return index >= 0 && index < length(number);
}

int with_zeros(int number, int quantity) {
    assert(quantity >= 0);
    return number * (int) floor(pow(10, quantity));
}

// PUSH AND POP

void push_front(int *number, int digit_or_number) {
    if (!is_empty(*number)) {
        *number += with_zeros(digit_or_number, length(*number));
    }
    else {
        *number = digit_or_number;
    }
}

void push_back(int *number, int digit_or_number) {
    *number = with_zeros(*number, length(digit_or_number)) + digit_or_number;
}

int pop_front_n(int *number, int n) {
    int popped_value = front_n(*number, n);
    *number = back_n(*number, (int) fdim(length(*number), n));
    return popped_value;
}

int pop_back_n(int *number, int n) {
    int popped_value = back_n(*number, n);
    *number = front_n(*number, (int) fdim(length(*number), n));
    return popped_value;
}

int pop_front(int *number) {
    return pop_front_n(number, 1);
}

int pop_back(int *number) {
    return pop_back_n(number, 1);
}

void insert(int *number, int index, int digit_or_number) {
    unsigned int number_length = length(*number);
    assert((index >= 0 && index <= number_length));
    int popped_value = pop_back_n(number, number_length - index);

    push_back(number, digit_or_number);
    if (!is_empty(popped_value)) {
        push_back(number, popped_value);
    }
}

// PEEK FUNCTIONS

int front_n(int number, int n) {
    return (int) floor(number / pow(10, fdim(length(number), n)));
}

int back_n(int number, int n) {
    return number % (int) pow(10, n);
}

int front(int number) {
    return front_n(number, 1);
}

int back(int number) {
    return back_n(number, 1);
}

int at(int number, int index) {
    assert(index_ok(number, index));
    return back(front_n(number, index + 1));
}

// UTILITY FUNCTIONS

int concat(int argc, ...){
    va_list argv;
    va_start(argv, argc);

    int result = 0;

    for (int i = 0; i < argc; ++i) {
        int number = va_arg(argv, int);
        if (number < 0) continue;

        push_back(&result, number);
    }

    va_end(argv);
    return result;
}

void set_digit(int *number, int index, int digit_or_number) {
    assert(index_ok(*number, index));
    int number_length = length(*number);
    int bn = back_n(*number, fdim(length(*number), index + 1));
    int fn = front_n(*number, index);
    if (is_empty(bn)) {
        bn = -1;
    }
    *number = concat(3, fn, digit_or_number, bn);
    *number = with_zeros(*number, (int) fdim(number_length, length(*number)));
}

void swap(int *number, int i, int j) {
    assert(index_ok(*number, i));
    assert(index_ok(*number, j));

    int tmp_i = at(*number, i);

    set_digit(number, i, at(*number, j));
    set_digit(number, j, tmp_i);
}

// STRING-LIKE FUNCTIONS

int contains(int number, int digit_or_number) {
    return find_first_of(number, digit_or_number) != -1;
}

int startswith(int number, int digit_or_number) {
    return front_n(number, length(digit_or_number)) == digit_or_number;
}

int endswith(int number, int digit_or_number) {
    return back_n(number, length(digit_or_number)) == digit_or_number;
}

int reversed(int number) {
    int result = 0;
    while (!is_empty(number)) {
        push_back(&result, pop_back(&number));
    }
    return result;
}

// SEARCH FUNCTIONS

int find_last_of(int number, int digit_or_number) {
    int number_length = length(number);
    int digit_or_number_length = length(digit_or_number);
    
    for (int to = number_length; to - digit_or_number_length >= 0; to -= 1) {
        if (number_from_to(number, to - digit_or_number_length, to) == digit_or_number) {
            return to - digit_or_number_length;
        }
    }
    return -1;
}

int find_first_of(int number, int digit_or_number) {
    int number_length = length(number);
    int digit_or_number_length = length(digit_or_number);
    for (int from = 0; from + digit_or_number_length <= number_length; from += 1) {
        if (number_from_to(number, from, from + digit_or_number_length) == digit_or_number) {
            return from;
        }
    }
    return -1;
}

// REMOVE FUNCTIONS

void remove_first_of(int *number, int digit_or_number) {
    int index = find_first_of(*number, digit_or_number);
    assert(index != -1);

    int fn = number_from_to(*number, 0, index);
    int bn = number_from_to(*number, index + length(digit_or_number), length(*number));
    if (is_empty(bn)) {
        bn = -1;
    }
    *number = concat(2, fn, bn);
}

void remove_last_of(int *number, int digit_or_number) {
    int index = find_last_of(*number, digit_or_number);
    assert(index != -1);

    int fn = number_from_to(*number, 0, index);
    int bn = number_from_to(*number, index + length(digit_or_number), length(*number));
    if (is_empty(bn)) {
        bn = -1;
    }
    *number = concat(2, fn, bn);
}

void remove_all(int *number, int digit_or_number) {
    while (contains(*number, digit_or_number)) {
        remove_first_of(number, digit_or_number);
    }
}

int remove_digit_if(int number, int(*predicate)(int)) {
    int result = 0;
    while (!is_empty(number)) {
        int popped_value = pop_back(&number);
        if (predicate(popped_value)) continue;
        else {
            push_front(&result, popped_value);
        }
    }
    return result;
}

int count_occurrences_of(int number, int digit_or_number) {
    int number_length = length(number);
    int digit_or_number_length = length(digit_or_number);
    int counter = 0;
    for (int from = 0; from + digit_or_number_length <= number_length; ++from) {
        if (number_from_to(number, from, from + digit_or_number_length) == digit_or_number) {
            counter += 1;
        }
    }
    return counter;
}

int min_digit(int number) {
    int number_length = length(number);
    int min_digit = 9;
    for (int index = 0; index < number_length; ++index) {
        int current_digit = at(number, index);
        if (current_digit < min_digit) {
            min_digit = current_digit;
        }
    }
    return min_digit;
}

int max_digit(int number) {
    int number_length = length(number);
    int max_digit = 0;
    for (int index = 0; index < number_length; ++index) {
        int current_digit = at(number, index);
        if (current_digit > max_digit) {
            max_digit = current_digit;
        }
    }
    return max_digit;
}

// ARITHMETIC FUNCTIONS

int reduce(int number, int(*func)(int, int), int initial) {
    while (!is_empty(number)) {
        int number_length = length(number);
        int popped_value = pop_front(&number);
        initial = func(initial, popped_value);
        if (length(number) < number_length - 1) {
            initial = func(initial, 0);
        }
    }
    return initial;
}

int sum_digits(int number) {
    int result = 0;
    while (!is_empty(number)) {
        result += pop_back(&number);
    }
    return result;
}

// RANGE FUNCTIONS

int range(int start, int stop, int step) {
    assert(start >= 0);
    assert(step > 0);
    assert(start <= stop);
    int result = 0;

    int index = start;
    while (index < stop) {
        push_back(&result, index);
        index += step;
    }

    return result;
}

int number_from_to(int number, int from, int to) {
    int number_length = length(number);
    assert(from >= 0 && from <= number_length);
    assert(to >= 0 && to <= number_length);
    assert(from <= to);

    (void) pop_back_n(&number, length(number) - to);
    return back_n(number, (int) fabs(to - from));
}

// SORTING FUNCTIONS

void bubble_sort(int *number) {
    remove_all(number, 0);

    int iterations = length(*number);
    for (int i = 0; i < iterations - 1; ++i) {
        for (int j = 0; j < iterations - 1; ++j) {
            if (at(*number, j) > at(*number, j + 1)) {
                swap(number, j, j + 1);
            }
        }
    }
}

// DIVISIBILITY FUNCTIONS

int divisible_by_2(int number) {
    if (back(number) % 2 == 0) {
        return 1;
    }
    return 0;
}

int divisible_by_3(int number) {
    if (sum_digits(number) % 3 == 0) {
        return 1;
    }
    return 0;
}

int divisible_by_4(int number) {
    if (back_n(number, 2) % 4 == 0) {
        return 1;
    }
    return 0;
}

int divisible_by_5(int number) {
    if (back(number) % 5 == 0) {
        return 1;
    }
    return 0;
}
