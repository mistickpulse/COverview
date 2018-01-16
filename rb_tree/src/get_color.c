/*
** get_color.c for  in /home/le-mau_f/rendu/SystemUnix/tmp/PSU_2016_malloc/rbt/new
** 
** Made by Zouz Le Maux
** Login   <le-mau_f@epitech.net>
** 
** Started on  Tue Jan 31 12:57:10 2017 Zouz Le Maux
** Last update Wed Feb  1 23:05:54 2017 Zouz Le Maux
*/

#include <stdlib.h>
#include "tree.h"

t_rbt_color     is_red(t_rbt_node *node)
{
  if (node == NULL)
    return (BLACK);
  return (node->color);
}
