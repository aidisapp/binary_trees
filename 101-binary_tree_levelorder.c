#include "binary_trees.h"

/**
 * binary_tree_levelorder - Traverses a binary tree using level-order traversal
 * @tr: Pointer to the root node of the tree to traverse
 * @f: Pointer to a function to call for each node
 */

void binary_tree_levelorder(const binary_tree_t *tr, void (*f)(int))
{
	size_t level, maxlevel;

	if (!tr || !f)
		return;

	maxlevel = binary_tree_height(tr) + 1;

	for (level = 1; level <= maxlevel; level++)
		btlo_helper(tr, f, level);
}

/**
 * btlo_helper - Goes through a binary tree using level-order traversal
 * @tr: Pointer to the root node of the tree to traverse
 * @f: Pointer to a function to call for each node
 * @lvl: The level of the tree to call f upon
 */

void btlo_helper(const binary_tree_t *tr, void (*f)(int), size_t lvl)
{
	if (lvl == 1)
		f(tr->n);
	else
	{
		btlo_helper(tr->left, f, lvl - 1);
		btlo_helper(tr->right, f, lvl - 1);
	}
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tr: Pointer to the root node of the tree to measure the height of
 *
 * Return: Height of the tree
 *         0 if tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tr)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (!tr)
		return (0);

	left_height = tr->left ? 1 + binary_tree_height(tr->left) : 0;
	right_height = tr->right ? 1 + binary_tree_height(tr->right) : 0;
	return (left_height > right_height ? left_height : right_height);
}
