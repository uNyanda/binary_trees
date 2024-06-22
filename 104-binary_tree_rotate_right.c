#include "binary_trees.h"

/**
 * binary_tree_rotate_right - function performs a right-rotation on a binary
 *				tree.
 *
 * @tree: pointer to the root node of the tree to rotate.
 *
 * Return: pointer to the new root node of the tree once rotated.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	/* check if the tree is NULL || if root has no left child */
	if (tree == NULL || tree->left == NULL)
	{
		return (tree); /* if so, return the tree as is */
	}
	/* set new_root to be the left child of the current root */
	new_root = tree->left;
	/* update the left child of the current root to be the right child new_root */
	tree->left = new_root->right;

	if (new_root->right != NULL) /* if new_root has right child */
	{
		/* update the parent of new_root's right child to be the current root */
		new_root->right->parent = tree;
	}
	/* update the parent of new_root to be the parent of the current root */
	new_root->parent = tree->parent;

	if (tree->parent == NULL) /* if the current root was the root of the tree */
	{
		/* set the parent of new_root to NULL */
		new_root->parent = NULL;
	}
	else if (tree == tree->parent->left) /* if current root was a left child */
	{
		/* update the left child of the parent to be new_root */
		tree->parent->left = new_root;
	}
	else /* if the current root was a right child */
		/* update the right child of the parent to be new_root */
		tree->parent->right = new_root;

	/* update the right child of new_root to be the current root */
	new_root->right = tree;
	/* update the parent of the current root to be new_root */
	tree->parent = new_root;
	/* return new_root, which is the new root of the tree after rotation */
	return (new_root);
}
