#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child
 * of another node.
 * If parent already has a right-child, the new node takes its place,
 * and the old right-child is set as the right-child of the new node.
 * @parent: a pointer to the node to insert the right-child in.
 * @value: the value to store in the new node.
 * Return: a pointer to the created node,
 * or NULL on failure or if parent is NULL.
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *p_node = malloc(sizeof(binary_tree_t));

	if (!p_node)
		free(p_node);

	if (!p_node || !parent)
		return (p_node);

	p_node->n = value;
	p_node->parent = parent;
	p_node->left = NULL;
	p_node->right = parent->right;

	if (p_node->right)
		p_node->right->parent = p_node;

	parent->right = p_node;

	return (p_node);
}
