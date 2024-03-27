#include "binary_trees.h"

/**
 *binary_tree_insert_right- inserts node at right child of another node
 *@parent:pointer to the node to insert the right-child in
 *@value:value to store in the new node
 *Return:Return a pointer to the created node, or NULL
 * on failure or if parent is NULL
*/

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);
	if (parent->right != NULL)
	{
		new_node->right = parent->right;
		parent->right->parent = new_node;
	}

	/*sets the new node as the right child of the parent.*/
	parent->right = new_node;

	return (new_node);
}
