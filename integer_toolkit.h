#ifndef INTEGER_TOOLKIT_H
#define INTEGER_TOOLKIT_H

// UTILITY FUNCTIONS
unsigned int length(int number);
int is_empty(int number);
int index_ok(int number, int index);
int with_zeros(int number, int quantity);

// PUSH AND POP
void push_front(int *number, int value);
void push_back(int *number, int value);
int pop_front_n(int *number, int n);
int pop_back_n(int *number, int n);
int pop_front(int *number);
int pop_back(int *number);
void insert(int *number, int index, int value);
void remove_subnumber(int *number, int value);

// PEEK FUNCTIONS
int front_n(int number, int n);
int back_n(int number, int n);
int front(int number);
int back(int number);
int at(int number, int index);

// UTILITY FUNCTIONS
int concat(int n, ...);
void set_value(int *number, int index, int value);
void swap(int *number, int i, int j);

// STRING-LIKE FUNCTIONS
int contains(int number, int value);
int startswith(int number, int value);
int endswith(int number, int value);
int reversed(int number);
int find(int number, int value);

// RANGE FUNCTIONS
int range(int start, int stop, int step);
int number_from_to(int number, int from, int to);

// SORTING FUNCTIONS
void bubble_sort(int *number);

#endif /* INTEGER_TOOLKIT_H */