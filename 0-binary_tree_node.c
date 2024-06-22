#include "binary_trees.h"

/**
 * binary_tree_node - function creates a binary tree node
 *
 * @parent: a pointer to the parent node of the node to create
 * @value: the value to put in the new node
 *
 * Description: This function creates a new binary tree node.
 *              It takes two parameters:
 * a pointer to the parent node ('parent'), and the value to be stored in the
 * node ('value').
 * The function allocates memory for the new node and assigns the 'value' to
 * the 'n' member of the node.
 * The 'parent' pointer is assigned to the 'parent' member of the new node.
 * The 'left' and 'right' pointers of the new node are initialized to 'NULL',
 * indicating that the new node does not have any children yet.
 *
 * Return: a pointer to the new node, or NULL on failure.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *newnode;

	newnode = malloc(sizeof(binary_tree_t));
	/* if allocation fails */
	if (newnode == NULL)
	{
		return (NULL);
	}
	newnode->n = value;
	newnode->parent = parent;
	newnode->left = NULL;
	newnode->right = NULL;

	return (newnode);
}
