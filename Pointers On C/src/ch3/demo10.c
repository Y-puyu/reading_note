#include <stdio.h>

extern int X ;
extern int Y ;

int max() {
    return (X > Y ? X : Y);
}