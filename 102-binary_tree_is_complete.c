#include "binary_trees.h"
#include <stdbool.h>

bool check_leaf(const binary_tree_t *tree);

/**
 * binary_tree_is_complete - checks if a binary tree is complete.
 * @tree: a pointer to the root node of the tree to check.
 * Return: 0 if not complete or tree is NULL, 1 if complete.
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (check_leaf(tree))
		return (1);
	if (!check_leaf(tree->left) && !check_leaf(tree->right))
		if (tree->left->left && !tree->left->right)
			return (0);
	if (tree->left && tree->right && check_leaf(tree->left)
			&& check_leaf(tree->right))
		return (1);
	if (tree->left && !tree->right && check_leaf(tree->left))
		return (1);


	return (binary_tree_is_complete(tree->left) &&
			binary_tree_is_complete(tree->right));
}

/**
 * check_leaf - checks if a tree has no children including an empty tree.
 * @tree: pointer to the root node of the tree.
 * Return: true if has no children, false if has children.
 */

bool check_leaf(const binary_tree_t *tree)
{
	if (!tree)
		return (false);
	if (!tree->left && !tree->right)
		return (true);
	return (false);
}
