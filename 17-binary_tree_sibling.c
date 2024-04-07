#include "binary_trees.h"

/**
 * binary_tree_sibling - this function finds the sibling of
 * a node in a binary tree
 * @node: this is the pointer to the node to find the sibling
 *
 * Return: Pointer to the sibling node, or NULL if no sibling or parent is NULL
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL ||
		node->parent->left == NULL || node->parent->right == NULL)
		return (NULL);

	if (node->parent->left == node)
		return (node->parent->right);
	else
		return (node->parent->left);
}
