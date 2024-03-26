#include "binary_trees.h"
#include <stdlib.h>

/**
*binary_tree_height- calculate the height of binary tree
*@tree:pointer to the root node of the tree to measure the height.
*Return:0 If tree is NULL
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t right_height = 0;
	size_t left_height = 0;

	if (tree == NULL)
		return (0);
	left_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	right_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return (left_height > right_height ? left_height : right_height);
}

/**
* binary_tree_node_count - Counts the number of nodes in a binary tree.
* @tree: A pointer to the binary tree to count.
* Return: The number of nodes in the binary tree.
*/
size_t binary_tree_node_count(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_node_count(tree->left) +
			binary_tree_node_count(tree->right));
}
/**
* binary_tree_is_perfect - Check if a binary tree is perfect
* @tree: Pointer to the root node of the tree
* Return: true if the tree is perfect, otherwise false
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return ((int)binary_tree_node_count(tree) ==
			(1 << (binary_tree_height(tree) + 1)) - 1);
}
