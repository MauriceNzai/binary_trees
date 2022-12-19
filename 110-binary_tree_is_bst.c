#include <limits.h>
#include "binary_trees.h"

/**
 * binary_tree_is_bst - Checks if a banary tree is a valid binary search tree
 *
 * @tree: pointer to the root node of the binary tree to check
 *
 * Return: 1 if tree is a valid BST, 0 if tree is not BST
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (is_tree_bst(tree, INT_MIN, INT_MAX));
}

/**
 * is_tree_bst - checks if tree is a valid BST
 *
 * @tree: pointer to the root node of the binary tre to search
 * @min: value of the least node visited
 * @max: value of the greatest node visited
 *
 * Return: 1 if tree is BST, 0 if tree is not BST
 */

int is_tree_bst(const binary_tree_t *tree, int min, int max)
{
	if (tree)
	{
		if (tree->n < min || tree->n > max)
			return (0);

		return (is_tree_bst(tree->left, min, tree->n - 1) &&

			is_tree_bst(tree->right, tree->n + 1, max));
	}
	return (1);
}

