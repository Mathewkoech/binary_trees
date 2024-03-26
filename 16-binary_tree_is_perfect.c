#include "binary_tree.h"
#include <stdlib.h>
#include <math.h>
/**
*binary_tree_size- calculates size if the binary tree
*@tree:pointer to the root node of the tree to measure the size
*Return: Size or 0 if tree is NULL
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/*Recursively calculate the size of the tree*/
	return (1 + binary_tree_size(tree->left) + binary_tree_size
		(tree->right));
}

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
* binary_tree_is_perfect - Check if a binary tree is perfect
* @tree: Pointer to the root node of the tree
* Return: true if the tree is perfect, otherwise false
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height = binary_tree_height(tree);
	size_t node_count = binary_tree_size(tree);
	size_t perfect_node_count = pow(2, height) - 1;

	if (tree == NULL)
		return (0);

	return node_count == perfect_node_count ? 1 : 0;

}
