#include "binary_trees.h"
#include <stdlib.h>

/**
*binary_tree_depth- calculates depth of binary tree
*@tree:pointer to the node to measure the depth
*Return:if tree is NULL, function must return 0.
*/
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL || tree->parent == NULL)
		return (0);

	/*use recursion to traverse up the tree from given tree to the root */
	return (1 + binary_tree_depth(tree->parent));
}
