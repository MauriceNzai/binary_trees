#include "binary_trees.h"

/**
 * binary_tree_nodes - counts nodes with at lease 1 child in a binary tree
 *
 * @tree: poninter to the root node of the tree to count number of nodes
 *
 * Return: the number of nodes
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0;

	if (!tree)
		return (0);
	if (tree->left || tree->right)
		nodes += 1;

	nodes += binary_tree_nodes(tree->left);
	nodes += binary_tree_nodes(tree->right);

	return (nodes);
}
