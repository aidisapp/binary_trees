#include "binary_trees.h"

/**
 * binary_tree_size - this is the function that measures the
 * size of a binary tree
 * @tree: this is the pointer to the root node of the tree to measure the size
 *
 * Return: this will be size of the tree, 0 if tree is NULL
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}
