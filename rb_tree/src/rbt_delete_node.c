/*
** rbt_delete_node.c for  in /home/le-mau_f/rendu/SystemUnix/tmp/PSU_2016_malloc/rbt/new
** 
** Made by Zouz Le Maux
** Login   <le-mau_f@epitech.net>
** 
** Started on  Wed Feb  1 02:08:52 2017 Zouz Le Maux
** Last update mar. janv. 16 22:32:38 2018 ROTARU Iulian
*/

#include <stdlib.h>
#include "color.h"
#include "tree.h"

static t_rbt_node	*rbt_remove_node(t_rbt_node *root, int value, int *done)
{
  t_rbt_node		*save;
  t_rbt_node		*tmp;

  if (root == NULL)
    *done = 1;
  else 
    {
      t_dir		direction;
      if (rbt_cmp_data(root->val, value) == 0)
	{
	  if (root->rope[LEFT] == NULL || root->rope[RIGHT] == NULL)
	    {
	      save = root->rope[((root->rope[LEFT] == NULL) ? RIGHT : LEFT)];// ternaire WTF;
	      /* Case 0*/
	      if (is_red(root) == RED)
		*done = 1;
	      else if (is_red(save) == RED)
		{
		  save->color = BLACK;
		  *done = 1;
		}
	      free(root);
	      return (save);
	    }
	  else
	    {
	      tmp = root->rope[RIGHT];
	      while (tmp->rope[LEFT] != NULL)
		tmp = tmp->rope[LEFT];
	      root->val = tmp->val;
	      value = tmp->val;
	    }
	}
      direction = ((rbt_cmp_data(root->val, value) > 0)) ? LEFT : RIGHT;
      root->rope[direction] = rbt_remove_node(root->rope[direction], value, done);
      if (!*done)
	root = rbt_rebalance_tree(root, direction, done);
    } 
  return (root);
}

int		rbt_remove(t_rbt_tree *tree, int value)
{
  int		done;

  done = 0;
  tree->root = rbt_remove_node(tree->root, value, &done);
  if (tree->root != NULL)
      tree->root->color = BLACK;
  return (1);
}
