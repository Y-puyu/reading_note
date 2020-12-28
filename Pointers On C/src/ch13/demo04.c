#include <stdio.h>

typedef struct  Node {
    int val;
    struct Node *next;
} Node;


void traverse(Node *cur, void (*func)(Node *node)) {
    while (cur != NULL) {
        func(cur);
        cur = cur->next;
    }
}