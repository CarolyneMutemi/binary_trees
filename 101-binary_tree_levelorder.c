#include "binary_trees.h"

int add_kids(const binary_tree_t *tree, binary_tree_t *array[], int index);

/**
 * binary_tree_levelorder - goes through a binary tree
 * using level-order traversal.
 * @tree: a pointer to the root node of the tree to traverse.
 * @func: a pointer to a function to call for each node.
 * Return: nothing.
*/

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *array[100];
	int index;
	int i;

	if (!tree || !func)
		return;

	array[0] = (binary_tree_t *)(void *)tree;
	index = add_kids(tree, array, 1);
	i = 1;
	while (array[i])
	{
		index = add_kids(array[i], array, index);
		i++;
	}

	i = 0;
	while (array[i])
	{
		func(array[i]->n);
		i++;
	}
}

/**
 * add_kids - adds the pointers to the node's children to an array.
 * @tree: the possible parent node.
 * @array: an array of pointers to store the pointers to the children.
 * @index: index to add the 1st child at.
 * Return: nothing.
*/

int add_kids(const binary_tree_t *tree, binary_tree_t *array[], int index)
{
	if (!tree)
		return (index);
	if (tree->left)
	{
		array[index] = tree->left;
		index++;
	}
	if (tree->right)
		array[index] = tree->right;

	index++;
	array[index] = NULL;
	return (index);
}
