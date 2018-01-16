/*
** rbt_print_tree.c for  in /home/le-mau_f/rendu/SystemUnix/tmp/PSU_2016_malloc/rbt/new/src
** 
** Made by Zouz Le Maux
** Login   <le-mau_f@epitech.net>
** 
** Started on  Wed Feb  1 13:09:03 2017 Zouz Le Maux
** Last update mar. janv. 16 23:31:19 2018 ROTARU Iulian
*/

#include <stdio.h>
#include "color.h"
#include "tree.h"

# define SPACE_QTE 10

static void	space_format(unsigned int depth)
{
  unsigned int		j;
  unsigned int		i;

  j = 0;
  while (j < depth)
    {
      i = 0;
      while (i < SPACE_QTE)
	{
	  printf(" ");
	  ++i;
	}
      ++j;
    }
}

void	format_node(t_rbt_node *node, unsigned int depth)
{
  space_format(depth);
  printf("***** Start ********\n");
  if (node->color == RED)
    color(C_RED);
  else
    color(YELLOW);
  color(HIGH);
  space_format(depth);
  printf("Addr  : [%p]\n", (void *)node);
  space_format(depth);
  printf("value : [%d]\n", node->val);
  space_format(depth);
  printf("Color : ");
  printf("[%s]\n", (node->color == RED) ? "RED" : "BLACK");
  color(RESET);
  space_format(depth);
  printf("***** End **********\n");
}

int	rbt_print_tree(t_rbt_tree *tree)
{
  if (tree && tree->root)
    rbt_apply_node(tree->root, &format_node, 0);
  return (0);
}
