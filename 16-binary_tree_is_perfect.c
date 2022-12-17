#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if a binary tree is full
 *
 * @tree: pointer to the root node of the binary tree to check
 *
 * Return: 1 if tree is perfect, 0 if tree is not perfect
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height;
	int size;
	int perfect_num;

	if (!tree)
		return (0);

	if (!tree->left && tree->right)
		return (0);
	if (tree->left && !tree->right)
		return(0);

	height = binary_tree_height(tree);
	size = binary_tree_size(tree);
	perfect_num = powered(2, height) - 1;

	if (size == perfect_num)
		return (1);
	else
		return (0);
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
	size_t left_size = 0;
	size_t right_size = 0;

	if (!tree)
		return (0);

	left_size += 1 + binary_tree_height(tree->left);
	right_size += 1 + binary_tree_height(tree->right);

	if (left_size > right_size)
		return (left_size);
	else
		return (right_size);
}

/**
 * binary_tree_size - measures the size of a binary tree
 *
 * @tree: pointer to the root of the binary tree to measure
 *
 * Return: size of the binary tree
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 1;

	if (!tree)
		return (0);

	size += binary_tree_size(tree->left);
	size += binary_tree_size(tree->right);

	return (size);
}

/**
 * powered - returns value of a to power b
 *
 * @a: number to be raised to a power
 * @b: the power/exponent
 *
 * Return: a power b( a ** b)
 */

int powered(int a, int b)
{
	if (b < 0)
		return (-1);
	if (b == 0)
		return (1);
	else
		return (a * powered(a, b - 1));
}
