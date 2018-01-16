/*
** main.c for  in /home/le-mau_f/rendu/SystemUnix/tmp/PSU_2016_malloc/rbt/new
** 
** Made by Zouz Le Maux
** Login   <le-mau_f@epitech.net>
** 
** Started on  Wed Feb  1 12:04:38 2017 Zouz Le Maux
** Last update mar. janv. 16 23:31:57 2018 ROTARU Iulian
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "color.h"
#include "tree.h"


static void display_help(const char *str) {
  fprintf(stderr, "Usage: %s `cat test/file`\n", str);
}



static void insertTest(t_rbt_tree *tree, int ac, const char * const *av) {
  for (int i = 1; i < ac; ++i)
    rbt_insert(tree, atoi(av[i]), malloc(sizeof(*tree)));
}


static void removeTest(t_rbt_tree *tree, int ac, const char * const *av) {
  for(int i = 1; i < ac; ++i)
    rbt_remove(tree, atoi(av[i]));
}

int		main(int ac, char **av)
{
  t_rbt_tree	tree;

  tree.root = NULL;
  if (ac == 1) {
    display_help(av[0]);
    return EXIT_SUCCESS;
  }

  printf("Legend Description:\n");
  printf("Yellow Text are supposed to be Black Node & Red Text, red Nodes\n");
  printf("All the spaces between two nodes are here to represent different deep level in the tree\n");
  printf("It goes from left to right\n");

  printf("Starting Test:\n");


  printf("*********************************************Before Insertion***************************\n");
  rbt_print_tree(&tree);
  insertTest(&tree, ac, (const char *const *)av);
  printf("*********************************************After Insertion***************************\n");
  rbt_print_tree(&tree);


  printf("*********************************************Starting Deletion***************************\n");
  removeTest(&tree, ac, (const char *const *)av);
  printf("*********************************************After Deletion***************************\n");
  rbt_print_tree(&tree);
  return EXIT_SUCCESS;
}
