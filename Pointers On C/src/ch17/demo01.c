#include <stdio.h>

int main() {
    if (front <= rear)
        n_values = rear – front + 1;
    else
        n_values = queue_size – front + rear + 1;
    n_values %= QUEUE_SIZE;
}