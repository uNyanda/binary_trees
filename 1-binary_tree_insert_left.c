#include "binary_trees.h"

/**
 * binary_tree_insert_left - function inserts a node as the left-child of
 *			     another node.
 *
 * @parent: the pointer to the node to insert the left-child in.
 * @value: the value to store in the new node.
 *
 * Return: a pointer to the created node, or NULL on failure or if 'parent'
 *	   NULL.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *newnode;

	/* check if there's a parent node */
	if (parent == NULL)
	{
		return (NULL);
	}

	newnode = binary_tree_node(parent, value);
	/* if allocation fails */
	if (newnode == NULL)
	{
		return (NULL);
	}

	/* check if the parent node already has a left child */
	if (parent->left)
	{
		newnode->left = parent->left;
		parent->left->parent = newnode;
	}

	parent->left = newnode;

	return (newnode);
}
