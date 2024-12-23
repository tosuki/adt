#include <malloc.h>

#include <stdio.h>
#include <stdlib.h>

#define DYNAMIC_ARRAY_REALLOC 2 //previous size * 2

struct Array {
    int size;
    int *values;
    int next_index;
};

struct Array create_array(int size) {
    struct Array array;

    array.values = malloc(sizeof(int)*size);

    if (array.values == NULL) {
        printf("Couldn't allocate memory for the array");
        exit(EXIT_FAILURE);
    }

    array.size = size;
    array.next_index = 0;

    return array;
}

void array_realloc(struct Array *array) {
    array -> size = array -> size * DYNAMIC_ARRAY_REALLOC;
    array -> values = realloc(array -> values, sizeof(int)*(array -> size));

    if (array -> values == NULL) {
        printf("Couldn't reallocate memory to the array");
        exit(EXIT_FAILURE);
    }
}

int array_push(struct Array *array, int value) {
    if (array -> next_index >= array -> size) {
        array_realloc(array);
    }

    array -> values[array -> next_index] = value;
    array -> next_index += 1;

    return array -> next_index;
}

int array_pop(struct Array *array) {
    if (array -> next_index == 0) {
        printf("Couldn't remove item from an empty array");
        exit(EXIT_FAILURE);
    }

    int last_used_index = array -> next_index - 1;
    int value = array -> values[last_used_index];

    array -> values[last_used_index] = 0;
    array -> next_index -= 1;

    return value;
}
