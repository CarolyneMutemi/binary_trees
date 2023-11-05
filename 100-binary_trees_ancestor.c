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
	binary_tree_t *result_1;
	binary_tree_t *result_2;
	if (!first || !second)
		return (NULL);

	if (first == second->parent)
		return ((binary_tree_t *)((void *)(first)));
	if (second == first->parent)
		return ((binary_tree_t *)((void *)(second)));
	if (first == second)
		return ((binary_tree_t *)((void *)(first)));

	result_1 = binary_trees_ancestor(first, second->parent);
	result_2 = binary_trees_ancestor(second, first->parent);
	if (result_1)
		return (result_1);
	if (result_2)
		return (result_2);
	
	return (binary_trees_ancestor(first->parent, second->parent));
}
