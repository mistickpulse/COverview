//
// tree.h for  in /home/le-mau_f/rendu/SystemUnix/tmp/PSU_2016_malloc/rbt
// 
// Made by Zouz Le Maux
// Login   <le-mau_f@epitech.net>
// 
// Started on  Sun Jan 29 22:09:16 2017 Zouz Le Maux
// Last update Wed Feb  1 22:58:10 2017 Zouz Le Maux
//

#ifndef TREE_H_
# define TREE_H_

# define TREE_VIOLATION "Data tree violation"
# define RED_VIOLATION "Red tree violation"
# define BLACK_VIOLATION "Black tree Violation"

typedef enum		e_clor
  {
    BLACK,
    RED,
    UNDEFINED
  }			t_rbt_color;

typedef struct		s_rbt_node
{
  int			val;
  t_rbt_color		color;
  struct s_rbt_node    	*rope[2];
}			t_rbt_node;

typedef struct		s_rbt_tree
{
  t_rbt_node		*root;
}			t_rbt_tree;

# define DEFAULT_COLOR RED

typedef enum	e_dir
  {
    LEFT,
    RIGHT
  }		t_dir;

void		format_node(t_rbt_node *, unsigned int depth);
t_rbt_node	*rbt_rebalance_tree(t_rbt_node *root, t_dir dir, int *done);
t_rbt_color	is_red(t_rbt_node *node);
int		rbt_is_valid(t_rbt_node *root);
int		rbt_remove(t_rbt_tree	*tree, int value);
int		rbt_insert(t_rbt_tree	*tree, int value, void *addr);
t_rbt_node	*rbt_single_rotation(t_rbt_node *node, t_dir dir);
t_rbt_node	*rbt_double_rotation(t_rbt_node *node, t_dir dir);
int		rbt_cmp_data(int value1, int val2);
void		rbt_apply_node(t_rbt_node *node, void (*ptr)(), int depth);
int		rbt_print_tree(t_rbt_tree *tree);
#endif /* !TREE_H_ */
