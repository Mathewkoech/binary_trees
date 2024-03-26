#include "binary_trees.h"

/**
 * binary_tree_node_count - Counts the number of nodes in a binary tree.
 * @tree: A pointer to the binary tree to count.
 *
 * Return: The number of nodes in the binary tree.
 */
size_t binary_tree_node_count(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_node_count(tree->left) +
			binary_tree_node_count(tree->right));
}
