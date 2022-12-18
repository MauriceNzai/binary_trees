#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 *
 * @tree: pointer to the root node of the binary tree to check
 *
 * Return: 1 if tree is complete, 0 if tree is not complete
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	int index;
	int node_count;

	index = 0;
	node_count = count_number_of_nodes(tree);

	if (!tree)
		return (0);
	if (check_complete_tree(tree, index, node_count))
		return (1);
	else
		return (0);
}

/**
 * count_number_of_nodes - counts the number of nodes in a binary tree
 *
 * @tree: the binary tree to count nodes of
 *
 * Return: the number of node
 */

int count_number_of_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + count_number_of_nodes(tree->left) +
			count_number_of_nodes(tree->right));
}

/**
 * check_complete_tree - checks if a binary tree is complete
 *
 * @tree: pointer to the root node of the binary tree to check
 * @index: the index representation
 * @num_nodes: the number of nodes in the binary tree
 *
 * Return: true if complete, false if not complete
 */

int check_complete_tree(const binary_tree_t *tree, int index, int num_nodes)
{
	if (!tree)
		return (1);
	if (index >= num_nodes)
		return (0);

	return (check_complete_tree(tree->left, (2 * index) + 1, num_nodes) &&
		check_complete_tree(tree->right, (2 * index) + 2, num_nodes));
}
