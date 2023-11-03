#include "binary_trees.h"
#include <stdio.h>

int number_of_nodes(const binary_tree_t *tree);
int height_of_tree(const binary_tree_t *tree);
int perfect_nodes(int level);

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect.
 * @tree: a pointer to the root node of the tree to check.
 * Return: 0 if perfect and 1 if not.
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int actual_nodes;
	int levels;
	int perfect_number;

	if (!tree)
		return (0);

	actual_nodes = number_of_nodes(tree);
	levels = height_of_tree(tree);
	perfect_number = perfect_nodes(levels);

	if (actual_nodes != perfect_number)
		return (0);
	return (1);
}

/**
 * number_of_nodes - counts the number of nodes in a tree.
 * @tree: a pointer to root node.
 * Return: number of nodes.
 */

int number_of_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + number_of_nodes(tree->left) + number_of_nodes(tree->right));
}

/**
 * height_of_tree - returns the height of a tree(levels).
 * @tree: a pointer to the root node.
 * Return: height of the tree.
 */

int height_of_tree(const binary_tree_t *tree)
{
	int height_left;
	int height_right;

	if (!tree || (!tree->left && !tree->right))
		return (0);

	height_left = height_of_tree(tree->left);
	height_right = height_of_tree(tree->right);

	return (((height_left > height_right) ? height_left : height_right) + 1);
}

/**
 * perfect_nodes - finds the number of nodes a perfect tree
 * is supposed to have.
 * @level: number of levels in a tree.
 * Return: number of nodes.
 */

int perfect_nodes(int level)
{
	if (level == 0)
		return (1);

	return ((1 << level) + perfect_nodes(level - 1));
}
