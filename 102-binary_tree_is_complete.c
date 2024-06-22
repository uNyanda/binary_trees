#include "binary_trees.h"

/**
 * count_nodes - function counts the number of nodes in a binary tree.
 *
 * @root: a pointer to the root node.
 *
 * Return: the number of nodes in the tree.
 */
int count_nodes(const binary_tree_t *root)
{
	if (root == NULL)
	{
		return (0);
	}

	return (1 + count_nodes(root->left) + count_nodes(root->right));
}

/**
 * is_complete - recursive function checks if a binary tree is complete.
 *
 * @root: pointer to the root node.
 * @index: the index of the node.
 * @count: the count to use.
 *
 * Return: 1 if complete, otherwise 0.
 */
int is_complete(const binary_tree_t *root, int index, int count)
{
	int left, right;

	/* an empty tree is complete */
	if (root == NULL)
	{
		return (1);
	}

	/* if index to curr. node > no. of nodes in tree, then tree !complete */
	if (index >= count)
	{
		return (0);
	}

	/* recur for left and right subtrees */
	left = is_complete(root->left, 2 * index + 1, count);
	right = is_complete(root->right, 2 * index + 2, count);

	return (left && right);
}

/**
 * binary_tree_is_complete - function checks if a binary tree is complete.
 *
 * @tree: a pointer to the root node of the tree to check.
 *
 * Return: 1 if 'tree' is full, 0 otherwise.
 *
 * If 'tree' is NULL, function must return 0.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	/* calculate the total number of nodes */
	int count = count_nodes(tree);

	if (tree == NULL)
	{
		return (0);
	}

	/* check if a binary tree is complete */
	return (is_complete(tree, 0, count));
}
