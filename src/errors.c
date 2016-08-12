/*
** errors.c for ok in /home/essian_b/rendu/PSU_2015_strace
**
** Made by Essiane Abel
** Login   <essian_b@epitech.net>
**
** Started on  Tue Apr  5 19:20:17 2016 Essiane Abel
** Last update Thu Jun 09 02:50:21 2016 ESSIANE Abel
*/

#include <stdio.h>
#include <stdarg.h>

int		perr(char const *format, ...)
{
  va_list	ap;

  va_start(ap, format);
  vfprintf(stderr, format, ap);
  va_end(ap);
  return (1);
}
