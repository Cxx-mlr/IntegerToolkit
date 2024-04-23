```c
#include "integer_toolkit.c"
#include <stdio.h>

int main() {
    int number = 183726945;
    printf("before bubble sort: %d\n", number); // 183726945
    bubble_sort(&number);
    printf("after bubble sort: %d\n", number); // 123456789
    return 0;
}
```
