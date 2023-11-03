#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes.
 * @first: a pointer to the first node.
 * @second: a pointer to the second node.
 * Return: pointer to the lowest common ancestor of the nodes.
*/

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
    binary_tree_t *ancestor_1 = NULL;
    binary_tree_t *ancestor_2 = NULL;

    if (!first || !second || !first->parent || !second->parent)
        return (NULL);

    ancestor_1 = first->parent;
    ancestor_2 = second->parent;

    while (ancestor_1)
    {
        if (ancestor_1 == ancestor_2 || second == ancestor_1)
            return ancestor_1;
        ancestor_1 = ancestor_1->parent;
    }

    ancestor_1 = first->parent;
    while (ancestor_2)
    {
        if (ancestor_2 == ancestor_1 || first == ancestor_2)
            return (ancestor_2);
        ancestor_2 = ancestor_2->parent;
    }
    return (NULL);
}
