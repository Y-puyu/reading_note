#if 0
int count_nodes(TreeNode *tree)
{
    if (tree == NULL)
        return 0;
    return 1 + count_nodes(tree–> left) + count_nodes(tree–> right);
}
int number_of_nodes()
{
    return count_nodes(tree);
}
#endif