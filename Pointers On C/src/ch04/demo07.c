#include <stdio.h>

int main() {
    int precipitating, temperature;
    scanf("%d%d", &precipitating, &temperature);

    if (precipitating) {
        if (temperature < 32)
            puts("snowing");
        else
            puts("raining");
    } else {
        if (temperature < 60)
            puts("cold");
        else
            puts("warm");
    }
    return 0;
}