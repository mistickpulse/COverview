/*
** rbt_rotate.c for  in /home/le-mau_f/rendu/SystemUnix/tmp/PSU_2016_malloc/rbt/new
** 
** Made by Zouz Le Maux
** Login   <le-mau_f@epitech.net>
** 
** Started on  Wed Feb  1 11:56:51 2017 Zouz Le Maux
** Last update Wed Feb  1 22:44:07 2017 Zouz Le Maux
*/

#include "tree.h"

t_rbt_node	*rbt_single_rotation(t_rbt_node *root, t_dir dir)
{
  t_rbt_node	*save;

  save = root->rope[!dir];
  
  root->rope[!dir] = save->rope[dir];
  save->rope[dir] = root;
  root->color = RED;
  save->color = BLACK;
  return (save);
}

t_rbt_node	*rbt_double_rotation(t_rbt_node *root, t_dir dir)
{
  root->rope[!dir] = rbt_single_rotation(root->rope[!dir], !dir);
  return (rbt_single_rotation(root, dir));
}
