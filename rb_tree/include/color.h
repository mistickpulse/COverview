/*
** color.h for  in /home/fabian/rendu/rush/sudoki-bi/include
** 
** Made by Zouz
** Login   <fabian@epitech.net>
** 
** Started on  Sun Jun 12 00:20:39 2016 Zouz
// Last update Thu Feb  2 02:12:09 2017 Zouz Le Maux
*/

#ifndef COLOR_H_

#include <stdio.h>

# define REVERSE "7"
# define SHINE "5"
# define HIGH "1"
# define C_RED "31"
# define GREEN "32"
# define YELLOW "33"
# define ORANGE "34"
# define MAGENTA "35"
# define CYAN "36"
# define WHITE "37"
# define RESET "0"

# define color(str) printf("\033[%sm", str)

#endif /* !COLOR_H_ */
