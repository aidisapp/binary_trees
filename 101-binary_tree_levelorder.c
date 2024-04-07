#include "binary_trees.h"

/**
 * level_order_queue_enqueue - Enqueues a node into the level-order
 *                             traversal queue
 * @q: The current level-order traversal queue
 * @nd: The node to enqueue
 *
 * Return: A pointer to the updated level-order traversal queue
 */

level_order_queue_t *level_order_queue_enqueue(level_order_queue_t *q,
                                                binary_tree_t *nd)
{
	level_order_queue_t *new_nd, *tmp;

	new_nd = malloc(sizeof(level_order_queue_t));
	if (new_nd == NULL)
		return (NULL);

	new_nd->node = nd;
	new_nd->next = NULL;

	if (q == NULL)
		return (new_nd);

	tmp = q;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = new_nd;
	return (q);
}

/**
 * level_order_queue_dequeue - Dequeues a node from the level-order
 *                             traversal queue
 * @q: The current level-order traversal queue
 *
 * Return: A pointer to the updated level-order traversal queue
 */

level_order_queue_t *level_order_queue_dequeue(level_order_queue_t *q)
{
	level_order_queue_t *tmp;

	if (q == NULL)
		return (NULL);

	tmp = q;
	q = q->next;
	free(tmp);

	return (q);
}

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order
 *                          traversal
 * @tr: A pointer to the root node of the tree to traverse
 * @f: A pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tr, void (*f)(int))
{
	level_order_queue_t *q = NULL;
	const binary_tree_t *cur;

	if (tr == NULL || f == NULL)
		return;

	q = level_order_queue_enqueue(q, (binary_tree_t *)tr);

	while (q != NULL)
	{
		cur = q->node;
		f(cur->n);

		if (cur->left != NULL)
			q = level_order_queue_enqueue(q, cur->left);
		if (cur->right != NULL)
			q = level_order_queue_enqueue(q, cur->right);

		q = level_order_queue_dequeue(q);
	}
}
