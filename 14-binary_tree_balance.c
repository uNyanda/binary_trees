#include "binary_trees.h"

/**
 * binary_tree_height - function measures the height of a binary tree.
 *
 * @tree: a pointer to the root node of the tree to measure the height.
 *
 * Return: the height of the tree.
 *
 * If 'tree' is NULL, return 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		left_height = binary_tree_height(tree->left);
		right_height = binary_tree_height(tree->right);
		return ((left_height > right_height ? left_height : right_height) + 1);
	}
}

/**
 * binary_tree_balance - function measures the balance factor of a binary tree.
 *
 * @tree: a pointer to the root node of the tree to measure the balance factor.
 *
 * Return: the balance factor.
 *
 * If 'tree' is NULL, return 0.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
	}
}
