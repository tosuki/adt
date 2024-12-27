#include <malloc.h>

#include "./lib/error.h"

#include "./linkedlist.h"

struct Node *create_linkedlist(int value, struct Node *tail) {
    struct Node* node = malloc(sizeof(struct Node));

    if (node == NULL) {
        abort("Failed to allocate memory to the list", 1);
    }

    node -> value = value;
    node -> tail = tail;

    return node;
}

short list_has(struct Node* list, int value) {
    if (list == NULL) {
        return 0;
    }

    if (list -> value == value) {
        return 1;
    }

    if (list -> tail == NULL) {
        return 0;
    }

    return list_has(list -> tail, value);
}

struct Node *list_push(struct Node* list, int value) {
    if (list == NULL) {
        abort("Tried to push a value in null", 1);
    }

    if (list->tail != NULL) {
        return list_push(list -> tail, value);
    }

    list -> tail = create_linkedlist(value, NULL);

    return list -> tail;
}
