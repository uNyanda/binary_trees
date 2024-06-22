#include "binary_trees.h"

int height(const binary_tree_t *tree);
void print_level(const binary_tree_t *root, int level, void (*func)(int));

/**
 * binary_tree_levelorder - function traverses a binary tree using level-order
 *			traversal.
 *
 * @tree: a pointer to the root node of the tree to traverse.
 * @func: a pointer to a function that is called for each node during the
 *	traversal. The value in the node is passed as a parameter to this
 *	function.
 *
 * Return: void.
 *
 * This function does nothing if either 'tree' or 'func' is NULL.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int i;
	int m_height = height(tree);

	if (tree == NULL || func == NULL)
	{
		return;
	}

	for (i = 1; i <= m_height; i++)
	{
		print_level(tree, i, func);
	}
}

/**
 * height - function computes the height of a binary tree.
 *
 * @tree: a pointer to the tree.
 *
 * Return: the height of a tree.
 */
int height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		left_height = height(tree->left);
		right_height = height(tree->right);

		if (left_height > right_height)
		{
			return (left_height + 1);
		}
		else
		{
			return (right_height + 1);
		}
	}
}

/**
 * print_level - This is a helper function that prints the nodes at a given
 *		level in the tree.
 *              The nodes are printed in order from left to right.
 *
 * @root: This is a pointer to the root node of the tree.
 * @level: This is the level at which the nodes are to be printed.
 *	   The root node is at level 1.
 * @func: This is a pointer to a function that is called for each node at
 *	 the given level. The value in the node is passed as a parameter
 *	 to this function.
 *
 * Return: void.
 *
 * This function does nothing if 'root' is NULL.
 */
void print_level(const binary_tree_t *root, int level, void (*func)(int))
{
	if (root == NULL)
	{
		return;
	}

	if (level == 1)
	{
		func(root->n);
	}
	else if (level > 1)
	{
		print_level(root->left, level - 1, func);
		print_level(root->right, level - 1, func);
	}
}
