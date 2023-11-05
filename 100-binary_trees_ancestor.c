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
	binary_tree_t **nodes_array_first = NULL;
	binary_tree_t *first_copy = (binary_tree_t *)(void *)first;
	binary_tree_t *second_copy = (binary_tree_t *)(void *)second;

	int index = 0;
	int size = 10;
	int i;

	if (!first || !second)
		return (NULL);

	nodes_array_first = malloc(sizeof(binary_tree_t *) * size);
	while (first_copy)
	{
		if (index >= size)
		{
			size = index + 10;
			nodes_array_first = realloc(nodes_array_first,
			sizeof(binary_tree_t *) * size);
		}
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
