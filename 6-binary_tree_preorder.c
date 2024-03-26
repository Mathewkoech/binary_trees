#include "binary_trees.h"
#include <stdlib.h>

/**
 *binary_tree_preorder- goes through a binary tree using pre-order traversal
 *@tree:pointer to the root node of the tree to traverse
 *@func:pointer to a function to call for each node
 *Return:If tree or func is NULL, do nothing
 */

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
        return;

	/* Call the function with the value of the current node */
	func(tree->n);

	/* Traverse the left subtree recursively */
	binary_tree_preorder(tree->left, func);

	/* Traverse the right subtree recursively */
	binary_tree_preorder(tree->right, func);
}
