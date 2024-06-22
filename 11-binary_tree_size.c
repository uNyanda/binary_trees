#include "binary_trees.h"

/**
 * binary_tree_size - function measures the size of a binary tree.
 *
 * @tree: a pointer to the root node of the tree to measure the size.
 *
 * Return: the size of the binary tree.
 *
 * If 'tree' is NULL, function must return 0.
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
	}
}
