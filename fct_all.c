/*
** fct_all.c for  in /home/anthony.piot/projet/Sistm_Unix/navy
**
** Made by Anthony PIOT
** Login   <anthony.piot@epitech.net>
**
** Started on  Tue Jan 31 10:03:10 2017 Anthony PIOT
** Last update Thu Feb  2 15:57:55 2017 Anthony PIOT
*/

#include "navy.h"

void	affpos(int *pos)
{
  my_putchar((pos[0] / 2) + 64);
  my_putchar(pos[1] + 47);
  my_putchar(':');
}

char	**checktouch(int *data, char **map, int pid)
{
  if (map[data[1]][data[0]] == '.' || map[data[1]][data[0]] == 'o')
    {
      map[data[1]][data[0]] = 'o';
      my_putstr(" missed\n\n");
      usleep(40);
      kill(pid, SIGUSR2);
    }
  else
    {
      map[data[1]][data[0]] = 'x';
      my_putstr(" hit\n\n");
      usleep(40);
      kill(pid, SIGUSR1);
    }
  return (map);
}

int	istouch(int pid)
{
  static int bol = 0;

  if (pid > 0)
    {
      bol = pid;
    }
  if (pid == -42)
    bol = 0;
  return (bol);
}

void	redir3(int pid)
{
  istouch(pid);
}

char	**checkhit(char **map, int *nb)
{
  while (istouch(0) == 0)
    {
      signal(SIGUSR1, redir3);
      signal(SIGUSR2, redir3);
    }
  if (istouch(0) == 10)
    {
      map[nb[1]][nb[0]] = 'x';
      my_putstr(": hit\n\n");
    }
  else if (istouch(0) == 12)
    {
      map[nb[1]][nb[0]] = 'o';
      my_putstr(": missed\n\n");
    }
  istouch(-42);
  return (map);
}
