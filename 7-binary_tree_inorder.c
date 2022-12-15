#include "binary_trees.h"

/**
 * binary_tree_inorder - traverses a tree with a in-order calling function
 * 
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 *
 * Return: Nothing
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	func(tree->n);
	binary_tree_inorder(tree->left, func);
	binary_tree_inorder(tree->right, func);
}
