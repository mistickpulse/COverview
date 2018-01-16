/*
** rbt_apply_node.c for  in /home/le-mau_f/rendu/SystemUnix/tmp/PSU_2016_malloc/rbt/new/src
** 
** Made by Zouz Le Maux
** Login   <le-mau_f@epitech.net>
** 
** Started on  Wed Feb  1 13:12:58 2017 Zouz Le Maux
** Last update Wed Feb  1 14:08:03 2017 Zouz Le Maux
*/

#include <stdlib.h>
#include "tree.h"

void    rbt_apply_node(t_rbt_node *node, void   (*ptr)(), int depth)
{
  if (node == NULL)
    return ;
  rbt_apply_node(node->rope[LEFT], ptr, depth + 1);
  (*ptr)(node, depth);
  rbt_apply_node(node->rope[RIGHT], ptr, depth + 1);
}
