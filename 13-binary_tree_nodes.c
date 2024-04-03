#include "binary_trees.h"

/**
 * binary_tree_nodes - this function counts the nodes with at least
 *
 * 1 child in a binary tree
 *
 * @tree: this is the pointer to the root node of the tree to count the nodes
 *
 * Return: this will be the number of nodes with
 *
 * at least 1 child, 0 if tree is NULL
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left != NULL || tree->right != NULL)
		return (1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));
	else
		return (0);
}
