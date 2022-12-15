#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if a binary tree is full
 *
 * @tree: pointer to the root node of the binary tree to check
 *
 * Return: 1 if tree is full, 0 if tree is not full
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if ((binary_tree_is_full(tree) == 1) &&
			(binary_tree_balance(tree) == 0))
		return (1);
	
	return (0);
}
