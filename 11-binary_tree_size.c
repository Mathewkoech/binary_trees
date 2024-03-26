#include "binary_trees.h"
#include <stdlib.h>

/**
 *binary_tree_size- calculates size if the binary tree
 *@tree:pointer to the root node of the tree to measure the size
 *Return: Size or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	/*Recursively calculate the size of the tree and left and right subtrees*/
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}
