#include <stdio.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} Node;

int count(Node *node) {
    int cnt = 0;
    for (cnt; node; node = node->next) {
        cnt++;
    }
    return cnt;
}

