#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes.
 * @first: a pointer to the first node.
 * @second: a pointer to the second node.
 * Return: pointer to the lowest common ancestor of the nodes.
*/

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
	if (!first || !second)
		return (NULL);

	if (first == second)
		return (binary_tree_t *)((void *)(first));
	else if (first == second->parent)
		return (binary_tree_t *)((void *)(first));
	else if (second == first->parent)
		return (binary_tree_t *)((void *)(second));

	return (binary_trees_ancestor(first->parent, second->parent));
}
