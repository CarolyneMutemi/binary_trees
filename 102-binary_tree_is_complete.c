#include "binary_trees.h"
#include <stdbool.h>
#include <stdio.h>

int add_kids(const binary_tree_t *tree, binary_tree_t *array[], int index);
int family_number(binary_tree_t *node);
int siblings(binary_tree_t *node_a, binary_tree_t *node_b);
int grandparent(binary_tree_t *node);

/**
 * binary_tree_is_complete - checks if a binary tree is complete.
 * @tree: a pointer to the root node of the tree to check.
 * Return: 0 if not complete or tree is NULL, 1 if complete.
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t *array[100];
	int index, i, len;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);

	/* Adding the nodes pointers to the array in level order.*/
	array[0] = (binary_tree_t *)(void *)tree;
	index = add_kids(tree, array, 1);
	i = 1;

	while (array[i])
	{
		index = add_kids(array[i], array, index);
		i++;
	}

	/* Checking if complete.*/
	len = i;
	i = 1;
	while (i < len)
	{
		if (siblings(array[i], array[i + 1]))
		{
			if (grandparent(array[i]) && family_number(array[i + 1]) < 3)
				return (0);
			if (family_number(array[i]) < family_number(array[i + 1]))
				return (0);
		}
		else
		{
			if ((array[i] == array[i]->parent->right && !array[i + 1])
			|| (array[i] && array[i + 1]))
				return (0);
		}
		i += 2;
	}

	return (1);
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
	{
		array[index] = tree->right;
		index++;
	}

	array[index] = NULL;
	return (index);
}


/**
 * siblings - checks whether two nodes are siblings.
 * @node_a: first node.
 * @node_b: second node.
 * Return: 0 if not siblings, 1 if siblings.
*/

int siblings(binary_tree_t *node_a, binary_tree_t *node_b)
{
	if (!node_a || !node_b)
		return (0);
	if (node_a->parent == node_b->parent)
		return (1);
	return (0);
}

/**
 * family_number - checks the number of nodes in a family
 * starting from the given node.
 * @node: the first member of the family.
 * Return: number of nodes in the family.
*/

int family_number(binary_tree_t *node)
{
	if (!node)
		return (0);
	return (1 + family_number(node->left) + family_number(node->right));
}

/**
 * grandparent - checks if it's a grandparent or much older.
 * @node: the node we are checking.
 * Return: 1 if it's a grandparent, 0 if not.
*/

int grandparent(binary_tree_t *node)
{
	if (!node)
		return (0);
	if (family_number(node->left) > 1 || family_number(node->right) > 1)
		return (1);
	return (0);
}
