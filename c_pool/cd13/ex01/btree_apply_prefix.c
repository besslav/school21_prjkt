#include "ft_btree.h"

void	btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
	if (root)
	{
		(*applyf)(root);
		btree_apply_prefix(root->left, (applyf));
		btree_apply_prefix(root->right, (applyf));
	}
}
