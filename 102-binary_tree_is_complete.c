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
 * binary_tree_is_leaf - checks if a node is a leaf
 * @node: pointer to the node to check
 *
 * Return: 1 if node is a leaf, and 0 otherwise. If node is NULL, return 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node != NULL && node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}
/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if perfect, 0 otherwise. If tree is NULL, return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	binary_tree_t *l, *r;

	if (tree == NULL)
		return (1);
	l = tree->left;
	r = tree->right;
	if (binary_tree_is_leaf(tree))
		return (1);
	if (l == NULL || r == NULL)
		return (0);
	if (binary_tree_height(l) == binary_tree_height(r))
	{
		if (binary_tree_is_perfect(l) && binary_tree_is_perfect(r))
			return (1);
	}
	return (0);
}
/**
 * binary_tree_is_complete -  checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if complete, 0 otherwise. If tree is NULL, return 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t left_height, right_height;
	binary_tree_t *l, *r;

	if (tree == NULL)
		return (0);
	if (binary_tree_is_leaf(tree))
		return (1);
	l = tree->left;
	r = tree->right;
	left_height = binary_tree_height(l);
	right_height = binary_tree_height(r);
	if (left_height == right_height)
	{
		if (binary_tree_is_perfect(l) && binary_tree_is_complete(r))
			return (1);
	}
	else if (left_height == right_height + 1)
	{
		if (binary_tree_is_complete(l) && binary_tree_is_perfect(r))
			return (1);
	}
	return (0);
}
