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
    return number * (int) floor(pow(10, quantity));
}

// PUSH AND POP

void push_front(int *number, int value) {
    if (!is_empty(*number)) {
        *number += with_zeros(value, length(*number));
    }
    else {
        *number = value;
    }
}

void push_back(int *number, int value) {
    *number = with_zeros(*number, length(value)) + value;
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

void insert(int *number, int index, int value) {
    unsigned int number_length = length(*number);
    assert((index >= 0 && index <= number_length));
    int popped_value = pop_back_n(number, number_length - index);

    push_back(number, value);
    if (!is_empty(popped_value)) {
        push_back(number, popped_value);
    }
}

void remove_subnumber(int *number, int value) {
    int index = find(*number, value);
    assert(index != -1);

    int fn = number_from_to(*number, 0, index);
    int bn = number_from_to(*number, index + length(value), length(*number));

    if (is_empty(bn)) bn = -1;
    *number = concat(2, fn, bn);
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
    return front(back_n(number, length(number) - index));
}

// UTILITY FUNCTIONS

int concat(int n, ...){
    va_list args;
    va_start(args, n);

    int result = 0;

    for (int i = 0; i < n; ++i) {
        int number = va_arg(args, int);
        if (number < 0) continue;

        push_back(&result, number);
    }

    va_end(args);
    return result;
}

void set_value(int *number, int index, int value) {
    assert(index_ok(*number, index));
    int bn = back_n(*number, fdim(length(*number), index + 1));
    if (is_empty(bn)) bn = -1;
    *number = concat(3, front_n(*number, index), value, bn);
}

void swap(int *number, int i, int j) {
    assert(index_ok(*number, i));
    assert(index_ok(*number, j));

    unsigned const int size = length(*number);
    int result = 0;

    for (unsigned int k = 0; k < size; ++k) {
        if (k == i) {
            push_back(&result, at(*number, j));
        }
        else if (k == j) {
            push_back(&result, at(*number, i));
        }
        else {
            push_back(&result, at(*number, k));
        }
    }

    *number = result;
}

// STRING-LIKE FUNCTIONS

int contains(int number, int value) {
    while (!is_empty(number)) {
        if (pop_back(&number) == value) {
            return 1;
        }
    }
    return 0;
}

int startswith(int number, int value) {
    return front_n(number, length(value)) == value;
}

int endswith(int number, int value) {
    return back_n(number, length(value)) == value;
}

int reversed(int number) {
    int result = 0;
    while (!is_empty(number)) {
        push_back(&result, pop_back(&number));
    }
    return result;
}

int find(int number, int value) {
    int value_length = length(value);
    int index = 0;

    while (!is_empty(number) && length(number) >= value_length) {
        if (front_n(number, value_length) == value) {
            return index;
        }
        else {
            (void) pop_front(&number);
        }
        ++index;
    }

    return -1;
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

    (void) pop_front_n(&number, from);
    
    return front_n(number, to - from);
}

// SORTING FUNCTIONS

void bubble_sort(int *number) {
    int iterations = length(*number);
    for (int i = 0; i < iterations - 1; ++i) {
        for (int j = 0; j < iterations - 1; ++j) {
            if (at(*number, j) > at(*number, j + 1)) {
                swap(number, j, j + 1);
            }
        }
    }
}