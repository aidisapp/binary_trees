#include "binary_trees.h"

/**
 * binary_tree_is_full - this function checks if a binary tree is full
 * @tree: this is the pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is full, 0 otherwise
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
	return (0);

	/* If both children are NULL, it's a leaf (full node) */
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/* If both children are present, check recursively */
	if (tree->left != NULL && tree->right != NULL)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));

	/* If only one child is present, tree is not full */
	return (0);
}
