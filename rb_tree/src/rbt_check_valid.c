/*
** rbt_check_valid.c for  in /home/le-mau_f/rendu/SystemUnix/tmp/PSU_2016_malloc/rbt/new
** 
** Made by Zouz Le Maux
** Login   <le-mau_f@epitech.net>
** 
** Started on  Tue Jan 31 12:54:30 2017 Zouz Le Maux
** Last update Wed Feb  1 11:48:40 2017 Zouz Le Maux
*/

#include "tree.h"

/*                                                                                                                     
** About tree violations check
** Return 1 in case of a valid tree otherwise 0
*/

#include <unistd.h>
#include <string.h>

static int             rbt_check_for_red_violation(t_rbt_node *root,
						   t_rbt_node *left,
						   t_rbt_node *right)
{
  if (is_red(root) && (is_red(left) || is_red(right)))
    {
      write(2, RED_VIOLATION, strlen(RED_VIOLATION));
      return (0);
    }
  return (1);
}

static int             rbt_check_for_data_violation(t_rbt_node *root,
						    t_rbt_node *left,
						    t_rbt_node *right)
{
  if ((left != NULL && rbt_cmp_data(left->val, root->val) >= 0)
      || (right != NULL && rbt_cmp_data(right->val, root->val) <= 0))
    {
      write(2, TREE_VIOLATION, strlen(TREE_VIOLATION));
      return (0);
    }
  return (1);
}

static int             rbt_check_for_black_violation(int left,
						     int right)
{
  if (left != 0 && right != 0 && left != right)
    {
      write(1, BLACK_VIOLATION, strlen(BLACK_VIOLATION));
      return (0);
    }
  return (1);
}

static int             return_b_node(int left_qte,
				     int right_qte,
				     t_rbt_node *root)
{
  if (left_qte != 0 && right_qte != 0)
    return (is_red(root) == RED ? left_qte : left_qte + 1);
  return (0);
}

int             rbt_is_valid(t_rbt_node *root)
{
  t_rbt_node    *tmp_ropes[2];
  int           left_bnode;
  int           right_bnode;

  if (root == NULL)
    return (1);
  tmp_ropes[LEFT] = root->rope[LEFT];
  tmp_ropes[RIGHT] = root->rope[RIGHT];
  left_bnode = rbt_is_valid(tmp_ropes[LEFT]);
  right_bnode = rbt_is_valid(tmp_ropes[RIGHT]);
  if(((rbt_check_for_red_violation(root,
				   tmp_ropes[LEFT],
				   tmp_ropes[RIGHT]) == 0)) ||
     ((rbt_check_for_data_violation(root,
				    tmp_ropes[LEFT],
				    tmp_ropes[RIGHT])) == 0) ||
     ((rbt_check_for_black_violation(left_bnode, right_bnode)) == 0))
    return (0);
  return (return_b_node(left_bnode, right_bnode, root));
}
