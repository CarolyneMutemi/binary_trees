#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_node - creates a binary tree node.
 * @parent: a pointer to the parent node of the node to create.
 * @value: value to put in the new node.
 * Return: a pointer to the new node, or NULL on failure.
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *p_node = malloc(sizeof(binary_tree_t));

	if (!p_node)
		return (NULL);

	p_node->parent = parent;
	p_node->left = NULL;
	p_node->right = NULL;
	p_node->n = value;

	return (p_node);
}
