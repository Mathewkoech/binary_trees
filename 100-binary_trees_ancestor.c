#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: If no common ancestors return NULL, else return common ancestor.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *current, *temp;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	current = first->parent, temp = second->parent;
	if (first == temp || !current || (!current->parent && temp))
		return (binary_trees_ancestor(first, temp));
	else if (current == second || !temp || (!temp->parent && current))
		return (binary_trees_ancestor(current, second));
	return (binary_trees_ancestor(current, temp));
}
