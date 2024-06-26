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
