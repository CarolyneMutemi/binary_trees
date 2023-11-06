#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes.
 * @first: a pointer to the first node.
 * @second: a pointer to the second node.
 * Return: pointer to the lowest common ancestor of the nodes.
*/

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
	binary_tree_t *nodes_array_first[100];
	binary_tree_t *first_copy;
	binary_tree_t *second_copy;
	int index;
	int i;

	if (!first || !second)
		return (NULL);

	first_copy = (binary_tree_t *)(void *)first;
	second_copy = (binary_tree_t *)(void *)second;

	index = 0;
	while (first_copy)
	{
		nodes_array_first[index] = first_copy;
		first_copy = first_copy->parent;
		index += 1;
	}

	while (second_copy)
	{
		for (i = 0; i < index; i++)
		{
			if (second_copy == nodes_array_first[i])
				return (second_copy);
		}
		second_copy = second_copy->parent;
	}
	return (NULL);
}
