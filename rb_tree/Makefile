##
## Makefile for  in /home/fabian/rendu/PSU/PSU_2015_minishell1
## 
## Made by Zouz
## Login   <fabian@epitech.net>
## 
## Started on  Tue Jun 21 20:18:39 2016 Zouz
## Last update mar. janv. 16 23:32:59 2018 ROTARU Iulian
##

RCREAT =	mkdir

SRC_DIR =	src/

EXT =		.c

CC =		gcc

RMDIR =		rm -d

RM =		rm -f

CFLAGS = 	-Iinclude

CFLAGS +=	-Wall -Wextra

NAME = 		rbtree_test

SRCS_NAME =	main				\
		cmp_data			\
		get_color			\
		rbt_balance_tree		\
		rbt_check_valid			\
		rbt_delete_node			\
		rbt_insert_node			\
		rbt_rotate			\
		rbt_apply_node			\
		rbt_print_tree

SRCS :=		$(addprefix $(SRC_DIR), $(SRCS_NAME))

SRCS :=		$(addsuffix $(EXT), $(SRCS))

OBJS = 		$(SRCS:.c=.o)

all: 		$(NAME)

$(NAME): 	$(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS)
clean:
	$(RM) $(OBJS)

fclean: 	clean
	$(RM) $(NAME)

re: 		fclean all

.PHONY: all clean fclean re
