#if 0

#include <stdio.h>

typedef struct {
    int x;
    int y;
} Point;

int main() {
    Point p;
    p.x = 1, p.y = 2;

    Point *a = &p;
    Point **b = &a;

    printf("%d\n", a);
    printf("%d\n", *a);
    printf("%d\n", a->x);
    printf("%d\n", b);
    printf("%d\n", b->a);
    printf("%d\n", b->x);
    printf("%d\n", *b);
    printf("%d\n", *b->a);
    printf("%d\n", *b->x);
    printf("%d\n", b->a->x);
    printf("%d\n", (*b)->a);
    printf("%d\n", (*b)->x);
    printf("%d\n", **b);
}

#endif
