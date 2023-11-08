#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_rotate_left -  performs a left-rotation on a binary tree.
 * @tree: a pointer to the root node of the tree to rotate.
 * Return: a pointer to the new root node of the tree once rotated.
*/

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (!tree)
		return (NULL);
	if (!tree->right)
		return (tree);

	new_root = tree->right;
	new_root->parent = NULL;
	tree->right = new_root->left;
	if (tree->right)
	{
		tree->right->parent = tree;
	}
	tree->parent = new_root;
	new_root->left = tree;
	return (new_root);
}
