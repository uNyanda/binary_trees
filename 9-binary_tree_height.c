#include "binary_trees.h"

/**
 * max - function takes 2 arguments, and returns the largest of the two
 *		 arguments.
 *
 * @a: first argument.
 * @b: second argument.
 *
 * Return: the largest argument.
 */
int max(int a, int b)
{
	return ((a > b) ? a : b);
}

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: height of the binary tree.
 *
 * If 'tree' is NULL, function must return 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	/* Base case: If tree is NULL, return 0 */
	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		/* Recursively calculate the height of the left and right subtrees */
		if (tree->left != NULL)
		{
			left_height = binary_tree_height(tree->left) + 1;
		}
		if (tree->right != NULL)
		{
			right_height = binary_tree_height(tree->right) + 1;
		}

		/* The height of the tree is the maximum height of the subtrees */
		return (max(left_height, right_height));
	}
}
