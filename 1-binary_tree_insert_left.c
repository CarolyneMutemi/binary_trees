#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node.
 * If parent already has a left-child, the new node takes its place,
 * and the old left-child is set as the left-child of the new node.
 * @parent: pointer to the node to insert the left-child in
 * @value: value to store in the new node.
 * Return: pointer to the created node,
 * or NULL on failure or if parent is NULL.
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *p_node;

	if (!parent)
		return (NULL);

	p_node =  malloc(sizeof(binary_tree_t));

	if (!p_node)
	{
		return (NULL);
	}

	p_node->n = value;
	p_node->parent = parent;
	p_node->left = parent->left;
	p_node->right = NULL;

	if (parent->left)
		parent->left->parent = p_node;

	parent->left = p_node;
	return (p_node);
}
