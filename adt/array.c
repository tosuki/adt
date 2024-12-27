#include <malloc.h>

#include "./lib/error.h"

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
        abort("Couldn't allocate memory for the array", 1);
    }

    array.size = size;
    array.next_index = 0;

    return array;
}

void array_realloc(struct Array *array) {
    array -> size = array -> size * DYNAMIC_ARRAY_REALLOC;
    array -> values = realloc(array -> values, sizeof(int)*(array -> size));

    if (array -> values == NULL) {
        abort("Couldn't reallocate memory to the array", 1);
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
        abort("Couldn't remove item from an empty array", 1);
    }

    int last_used_index = array -> next_index - 1;
    int value = array -> values[last_used_index];

    array -> values[last_used_index] = 0;
    array -> next_index -= 1;

    return value;
}

int array_shift(struct Array *array) {
    if (array -> next_index == 0) {
        abort("Couldn't remove item from an empty array", 1);
    }

    int first_index = array -> values[0];
    int *new_values = malloc(sizeof(int)*array -> size);

    if (new_values == NULL) {
        abort("Couldn't allocate memory to the array", 1);
    }

    for (short i = 1; i < array -> size; i++) {
        new_values[i] = array -> values[i];
    }

    free(array -> values);

    array -> values = new_values;
    array -> next_index -= 1;

    return first_index;
}
