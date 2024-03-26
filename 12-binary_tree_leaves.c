#include "binary_trees.h"
#include <stdlib.h>

/**
*binary_tree_leaves-cunt the number of leaves in binary tree
*@tree: pointer to the root node of the tree to count the number of leaves
*Return:0 if tree is NULL
*/

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t right_leaves = 0;
	size_t left_leaves = 0;

	/*check if tree is NULL*/
	if (tree == NULL)
		return (0);

	/*check if node is leaf node*/
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/*count leaves recursively*/
	right_leaves = tree->right ? binary_tree_leaves(tree->right) : 0;
	left_leaves = tree->left ? binary_tree_leaves(tree->left) : 0;

	return (left_leaves + right_leaves);
}
