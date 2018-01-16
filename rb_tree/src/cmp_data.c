/*
** cmp_data.c for  in /home/le-mau_f/rendu/SystemUnix/tmp/PSU_2016_malloc/rbt/new
** 
** Made by Zouz Le Maux
** Login   <le-mau_f@epitech.net>
** 
** Started on  Wed Feb  1 11:41:47 2017 Zouz Le Maux
** Last update Wed Feb  1 13:34:40 2017 Zouz Le Maux
*/

int rbt_cmp_data(int val1, int val2)
{
  if (val1 > val2)
    return (1);
  if (val2 > val1)
    return (-1);
  return (0);
}
