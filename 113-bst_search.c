#include "binary_trees.h"

/**
 * bst_search - searches for a value in a Binary Search Tree
 *
 * @tree: pointer to the root node ot the tree to search in
 * @value: the value to search
 *
 * Return: pointer to the node containing the value, NULL of failure
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree)
	{
		if (tree->n == value)
			return ((bst_t *)tree);
		if (tree->n > value)
			return (bst_search(tree->left, value));
		return (bst_search(tree->right, value));
	}
	return (NULL);
}

