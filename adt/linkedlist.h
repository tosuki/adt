#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node {
    struct Node *tail;
    int value;
};

struct Node *create_linkedlist(int value, struct Node* tail);
struct Node *list_push(struct Node *list, int value);
short list_has(struct Node *list, int value);

#endif