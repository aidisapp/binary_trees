#include "binary_trees.h"

/**
 * binary_tree_height_b - this measures height of a binary tree for a bal tree
 * @tree: tree to go through
 * Return: the height
 */

size_t binary_tree_height_b(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);

	left_height = tree->left ? 1 + binary_tree_height_b(tree->left) : 1;
	right_height = tree->right ? 1 + binary_tree_height_b(tree->right) : 1;

	return (left_height > right_height ? left_height : right_height);
}

/**
 * binary_tree_balance - this measures balance factor of a binary tree
 * @tree: tree to go through
 * Return: balanced factor
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height, right_height, balance_factor;

	if (tree == NULL)
		return (0);

	left_height = (int)binary_tree_height_b(tree->left);
	right_height = (int)binary_tree_height_b(tree->right);

	balance_factor = left_height - right_height;

	return (balance_factor);
}
