#ifndef ARRAY_H
#define ARRAY_H

struct Array {
    int size;
    int *values;
    int next_index;
};

struct Array create_array(int size);
void array_realloc(struct Array *array);
int array_push(struct Array *array, int value);
int array_pop(struct Array *array);
int array_shift(struct Array *array);

#endif