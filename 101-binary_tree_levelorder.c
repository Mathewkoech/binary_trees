#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_levelorder - Perform level-order traversal of a binary tree
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 * Return: nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int front = 0, rear = 0;
	const binary_tree_t **queue;
	const binary_tree_t *current;

	if (tree == NULL || func == NULL)
		return;
	queue = malloc(sizeof(binary_tree_t *) * 1024);
	if (!queue)
		return;

	queue[rear++] = tree;
	while (front < rear)
	{
		current = queue[front++];

		func(current->n);
		if (current->left != NULL)
			queue[rear++] = current->left;
		if (current->right != NULL)
			queue[rear++] = current->right;
	}
	free(queue);
}
