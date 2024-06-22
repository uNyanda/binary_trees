#include "binary_trees.h"

/**
 * binary_tree_insert_right - function inserts a node as the right-child
 *			      of another node.
 *
 * @parent: a pointer to the node to insert the right-child in.
 * @value: the value to store in the new node.
 *
 * Return: a pointer to the created node, or NULL on failure or
 *	   if 'parent' is NULL.
 *
 * If the 'parent' already has a right-child, the new node must take its
 * place, and the old right-child must be set as the right-child of the new
 * node.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *newnode;

	if (parent == NULL)
	{
		return (NULL);
	}

	newnode = binary_tree_node(parent, value);
	if (newnode == NULL)
	{
		return (NULL);
	}

	if (parent->right)
	{
		newnode->right = parent->right;
		parent->right->parent = newnode;
	}

	parent->right = newnode;

	return (newnode);
}
