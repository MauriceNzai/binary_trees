#include "binary_trees.h"

/**
 * bst_insert - inserts a value into a binary search tree
 *
 * @tree: pointer to ther root node of the BST
 * @value: the value to insert into the BST
 *
 * Return: pointer to the binary search tree
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *current_node;
	bst_t *new_node;

	if (tree)
	{
		current_node = *tree;

		if (!current_node)
		{
			new_node = binary_tree_node(current_node, value);
			if (!new_node)
				return (NULL);
			return (*tree = new_node);
		}

		if (value < current_node->n) /* insert to the left subtree */
		{
			if (current_node->left)
				return (bst_insert(&current_node->left, value));

			new_node = binary_tree_node(current_node, value);
			if (!new_node)
				return (NULL);
			return (current_node->left = new_node);
		}

		if (value > current_node->n) /* insert into the right subtree */
		{
			if (current_node->right)
				return (bst_insert(&current_node->right, value));

			new_node = binary_tree_node(current_node, value);
			if (!new_node)
				return (NULL);
			return (current_node->right = new_node);
		}
	}
	return (NULL);
}
