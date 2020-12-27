#if 0

/*
** Insert a value into a doubly linked list. frontp is a pointer to the root
** pointer to the first node; rearp is a pointer to the root pointer to the last
** node; and value is the new value to be inserted. Returns: 0 if the value is
** already in the list, –1 if there was no memory to create a new node, 1 if the
** value was added successfully.
*/
#include "doubly_linked_list_node.h"
#include <stdio.h>
#include <stdlib.h>
int dll_insert(Node **frontp, Node **rearp, int value)
{
    register Node **fwdp;
    register Node *next;
    register Node *newnode;
    /*
** See if value is already in the list; return if it is. Otherwise,
** allocate a new node for the value ("newnode" will point to it), and
** "next" will point to the one after where the new node goes.
*/
    fwdp = frontp;
    while ((next = *fwdp) != NULL)
    {
        if (next–> value == value)
            return 0;
        if (next–> value > value)
            break;
        fwdp = &next–> fwd;
    }
    newnode = (Node *)malloc(sizeof(Node));
    if (newnode == NULL)
        return –1;
    newnode–> value = value;
    /*
** Add the new node to the list.
*/
    newnode–> fwd = next;
    *fwdp = newnode;
    if (fwdp != frontp)
        if (next != NULL)
            newnode–> bwd = next–> bwd;
        else
            newnode–> bwd = *rearp;
    else
        newnode–> bwd = NULL;
    if (next != NULL)
        next–> bwd = newnode;
    else
        *rearp = newnode;
    return 1;
}

#endif 