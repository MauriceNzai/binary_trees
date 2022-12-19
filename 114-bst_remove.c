#include "binary_trees.h"

/**
 * bst_remove - removes a node from a Binary Search Tree
 *
 * @root: pointer to the root of the tree to remove node from
 * @value: the value of the node
 *
 * Return: pointer to new root node of the tree after desred value is removed
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (remove_node(root, root, value));
}

/**
 * remove_node - recursively removes a node from a BST
 *
 * @root: pointer to the root node of the BST to remove node from
 * @node: pointer to the node to remove
 * @value: value of the node to remove
 *
 * Return: pointer to the new root node after deletion
 */
bst_t *remove_node(bst_t *root, bst_t *node, int value)
{
	if (node)
	{
		if (node->n == value)
			return (delete_node(root, node));
		if (node->n > value)
			return (remove_node(root, node->left, value));
		return (remove_node(root, node->right, value));
	}
	return (NULL);
}

/**
 * delete_node - deletes a node from a BST
 *
 * @root: pointer to the root node of the BST to remove node from
 * node: pointer to the node to delete
 *
 * Return: pointer to the new root node after deletion
 */

bst_t *delete_node(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent;
	bst_t *successor = NULL;

	/* no children or right child only */
	if (!node->left)
	{
		if (parent && parent->left == node)
			parent->left = node->right;
		else if (parent)
			parent->right = node->right;
		if (node->right)
			node->right->parent = parent;
		free(node);
		return (parent == NULL ? node->right : root);
	}

	/* left child only */
	if (!node->right)
	{
		if (parent && parent->left == node)
			parent->left = node->left;
		else if (parent)
			parent->right = node->left;
		if (node->left)
			node->left->parent = parent;
		free(node);
		return (parent == NULL ? node->left : root);
	}

	/* two children */
	successor = inorder_successor(node->right);
	node->n = successor->n;

	return (delete_node(root, successor));
}

/**
 * inorder_successor - returns the minimum value of a BST
 *
 * @root: pointer to the root node of the BST
 *
 * Return: minimum value in the tree/BST
 */
bst_t *inorder_successor(bst_t *root)
{
	while (root->left)
		root = root->left;
	return (root);
}
