#include "binary_trees.h"

/**
 * binary_tree_sibling - function finds the sibling of a node.
 *
 * @node: a pointer to the node to find the sibling.
 *
 * Return: a pointer to the sibling node.
 *
 * If 'node' is NULL or the parent is NULL, return NULL.
 * If 'node' has no sibling, return NULL.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
	{
		return (NULL);
	}

	if (node->parent->left == node)
	{
		return (node->parent->right);
	}
	else
	{
		return (node->parent->left);
	}
}

/**
 * binary_tree_uncle - function finds the uncle of a node.
 *
 * @node: a pointer to the node to find the uncle.
 *
 * Return: a pointer to the uncle node.
 *
 * If 'node' is NULL, return NULL.
 * If 'node' has no uncle, return NULL.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
	{
		return (NULL);
	}

	return (binary_tree_sibling(node->parent));
}
