#include "binary_trees.h"
#include <stdlib.h>

/**
*binary_tree_uncle- finds uncle of a node
*@node:pointer to the node to find the uncle
*Return:NULL If node has no uncle or node is NULL
*/
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	if (node->parent->parent)
		if (node->parent->parent->left == node->parent)
			return (node->parent->parent->right);
		else
			return (node->parent->parent->left);
	else
		return (NULL);

}
