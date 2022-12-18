#include "binary_trees.h"

/**
 * binary_tree_levelorder - traverses a binary tree in level-order traversal
 *
 * @tree: pointer to the root node of the binary tree to traverse
 * @func: the func to use
 *
 * Return: Nothing
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{

	int h;
	int i;

	h = binary_tree_height(tree);

	if (!tree || !func)
		return;

	for (i = 1; i <= h; i++)
	{
		print_current_level(tree, i);
	}
}

/**
 * binary_tree_height - measures the height of a binary tree
 *
 * @tree: the binary tree to measure
 *
 * Return: The height of the tree
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_size;
	size_t right_size;

	if (!tree)
		return (0);

	left_size = binary_tree_height(tree->left);

	right_size = binary_tree_height(tree->right);

	if (left_size > right_size)
		return (left_size + 1);
	else
		return (right_size + 1);
}

/**
 * print_current_level - prints nodes at a current level
 *
 * @tree: pointer to the root node of the binary tree
 * @level: the current level
 *
 * Return: Nothing
 */

void print_current_level(const binary_tree_t *tree, int level)
{
	if (!tree)
		return;

	if (level == 1)
		printf("%d \n", tree->n);
	if (level > 1)
	{
		print_current_level(tree->left, level - 1);
		print_current_level(tree->right, level - 1);
	}
}
