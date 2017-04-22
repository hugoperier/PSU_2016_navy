/*
** my_strcpy.c for  in /home/anthony.piot/Test/PSU_2016_navy/PSU_2016_navy
** 
** Made by Anthony PIOT
** Login   <anthony.piot@epitech.net>
** 
** Started on  Thu Feb  2 15:57:21 2017 Anthony PIOT
** Last update Thu Feb  2 15:57:50 2017 Anthony PIOT
*/

#include "navy.h"

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  dest = malloc(sizeof(char) * (my_strlen(src) + 1));
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  return (dest);
}
