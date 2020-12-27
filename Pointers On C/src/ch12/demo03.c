#if 0

/*
** Remove a specified node from a doubly linked list. The first argument points
** to the root node for the list, and the second points to the node to be
** removed. TRUE is returned if it can be removed, otherwise FALSE is returned.
*/
#include "doubly_linked_list_node.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE 1
int dll_remove(struct NODE *rootp, struct NODE *delete)
{
    register Node *this;
    assert(delete != NULL);
    /*
** Find the node in the list and return FALSE if it is not there.
** Otherwise, delete it and return TRUE.
*/
    for (this = rootp–> fwd; this != NULL; this = this–> fwd)
        if (this == delete)
            break;
    if (this == delete)
    {
        /*
** Update fwd pointer of the previous node.
*/
        if (this–> bwd == NULL)
            rootp–> fwd = this–> fwd;
        else
            this–> bwd–> fwd = this–> fwd;
        /*
** Update bwd pointer of the next node.
*/
        if (this–> fwd == NULL)
            rootp–> bwd = this–> bwd;
        else
            this–> fwd–> bwd = this–> bwd;
        free(this);
        return TRUE;
    }
    else
        return FALSE;
}

#endif