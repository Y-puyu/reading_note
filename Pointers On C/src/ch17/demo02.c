#if 0
void resize_stack(size_t new_size) {
    STACK_TYPE *old_stack;
    int i;

    assert(new_size > top_element);
    old_stack = stack;
    stack = (STACK_TYPE *)malloc(new_size * sizeof(STACK_TYPE));
    assert(stack != NULL);
    stack_size = new_size;

    for (i = 0; i <= top_element; i += 1)
        stack[i] = old_stack[i];
    free(old_stack);
}
#endif