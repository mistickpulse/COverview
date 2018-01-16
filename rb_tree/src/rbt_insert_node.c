/*
** rbt_insert_node.c for  in /home/le-mau_f/rendu/SystemUnix/tmp/PSU_2016_malloc/rbt/new
** 
** Made by Zouz Le Maux
** Login   <le-mau_f@epitech.net>
** 
** Started on  Tue Jan 31 12:56:13 2017 Zouz Le Maux
** Last update mar. janv. 16 22:33:08 2018 ROTARU Iulian
*/

#include <stdlib.h>
#include <color.h>
#include "tree.h"

static t_rbt_node              *rbt_create_node(int value, void *addr)
{
  t_rbt_node			*new;

  if (addr == NULL)
    return (NULL);
  new = (t_rbt_node *)addr;
  new->val = value;
  new->color = RED;  
  new->rope[LEFT] = NULL;
  new->rope[RIGHT] = NULL;  
  return (new);
}

static void	set_color_first_case(t_rbt_node *root)
{
  root->color = RED;
  root->rope[LEFT]->color = BLACK;
  root->rope[RIGHT]->color = BLACK;
}

static t_rbt_node      *rbt_insert_node(t_rbt_node *root, int value, void *addr)
{
  t_dir			dir;

  if (root == NULL)
    root = rbt_create_node(value, addr);
  else if (rbt_cmp_data(root->val, value) != 0)
    {
      dir = (rbt_cmp_data(root->val, value) > 0) ? LEFT : RIGHT;
      root->rope[dir] = rbt_insert_node(root->rope[dir], value, addr);
      if (is_red(root->rope[dir]) == RED)
	{
	  if (is_red(root->rope[!dir]) == RED)
	    set_color_first_case(root);
	  else
	    {
	      if (is_red(root->rope[dir]->rope[dir]) == RED)
		root = rbt_single_rotation(root, !dir);
	      else if (is_red(root->rope[dir]->rope[!dir]) == RED)
		root = rbt_double_rotation(root, !dir);
	    }
	}
    }
  return (root);
}

int		rbt_insert(t_rbt_tree *root, int value, void *addr)
{
  /* color(CYAN); */
  /* color(HIGH); */
  /* printf("*********************START INSERT **********************************************************\n"); */
  /* color(RESET); */
  if ((root->root = rbt_insert_node(root->root, value, addr)) == NULL)
    return (0);
  /* root->root->color = BLACK; */
  /* rbt_print_tree(root); */
  /* color(CYAN); */
  /* color(HIGH); */
  /* printf("*********************END   INSERT **********************************************************\n"); */
  /* color(RESET); */
  return (1);
}
