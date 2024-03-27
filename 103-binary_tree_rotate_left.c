#include "binary_trees.h"
#include <stdlib.h>

/**
*binary_tree_rotate_left-performs a left-rotation on a binary tree
*@tree:pointer to the root node of the tree to rotate
*Return:pointer to new root node once rotated
*/
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root, *temp;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	/*the right child of the current root node becomes the new root*/
	new_root = tree->right;
	temp = new_root->left;
	new_root->left = tree;
	tree->right = temp;/*point to the left child of the new root (temp)*/
	return (new_root);
}
