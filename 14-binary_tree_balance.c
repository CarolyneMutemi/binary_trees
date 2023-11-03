#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_balance - measures the balance factor of a binary tree.
 * @tree: a pointer to the root node of the tree to measure the balance factor.
 * Return: 0 if tree is NULL, balance factor of a binary tree(int).
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	printf("%d\n", height(tree->left));
	printf("%d\n", height(tree->right));

	return (height(tree->left) - height(tree->right));
}

/**
 * height - finds height of a tree.
 * @tree: pointer to the root node.
 * Return: height of the tree.
 */

int height(const binary_tree_t *tree)
{
	int h_left;
	int h_right;

	if (!tree)
		return (-1);
	if (!tree->left && !tree->right)
		return (0);

	h_left = height(tree->left);
	h_right = height(tree->right);

	return (((h_left > h_right) ? h_left : h_right) + 1);
}
