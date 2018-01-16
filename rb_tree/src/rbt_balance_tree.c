/*
** rbt_balance_tree.c for  in /home/le-mau_f/rendu/SystemUnix/tmp/PSU_2016_malloc/rbt/new
** 
** Made by Zouz Le Maux
** Login   <le-mau_f@epitech.net>
** 
** Started on  Wed Feb  1 02:45:19 2017 Zouz Le Maux
** Last update mar. janv. 16 22:31:51 2018 ROTARU Iulian
*/

#include <stdlib.h>
#include "tree.h"

t_rbt_node	*rbt_rebalance_tree(t_rbt_node *root, t_dir dir, int *done)
{
  t_rbt_node	*par;
  t_rbt_node	*son;

  par = root;
  son = root->rope[!dir];
  if (is_red(son) == RED)
    {
      root = rbt_single_rotation(root, dir);
      son = par->rope[!dir];
    }
  if (son != NULL)
    {
      if ((is_red(son->rope[LEFT]) == BLACK) && (is_red(son->rope[RIGHT]) == BLACK))
	{
	  if (is_red(par) == RED)
	    *done = 1;
	  par->color = BLACK;
	  son->color = RED;
	}
      else
	{
	  t_rbt_color save;
	  int		new_root = ((root == par) ? 1 : 0);
	  save = par->color;
	  if (is_red(son->rope[!dir]) == RED)
	    {
	      par = rbt_single_rotation(par, dir);
	    }
	  else
	    {
	      par = rbt_double_rotation(par, dir);
	    }
	  par->color = save;
	  par->rope[LEFT]->color = BLACK;
	  par->rope[RIGHT]->color = BLACK;
	  if (new_root)
	    {
	      root = par;
	    }
	  else
	    root->rope[dir] = par;
	  *done = 1;
	}
    }
  return (root);
}
