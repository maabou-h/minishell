/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 14:39:30 by maabou-h          #+#    #+#             */
/*   Updated: 2019/02/24 17:04:06 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void ft_display(char **envp)
{
  int i;

  i = 0;
  while (envp[i])
  {
    if (ft_strncmp(envp[i], "USER", 4) == 0 && envp[i][4] == '=')
    {
        ft_putstr("\033[0;33m");
        ft_putstr(envp[i] + 5);
        ft_putstr("\033[0m@");
    }
    i++;
  }
  i = 0;
  while (envp[i])
  {
    if (ft_strncmp(envp[i], "PWD", 3) == 0 && envp[i][3] == '=')
    {
        ft_putstr("\033[0;31m");
        ft_putstr(envp[i] + 4);
        ft_putstr("\033[0m$>");
    }
    i++;
  }
}

void ft_controls(int sig_num)
{
  sig_num = 0;
}

int main(int argc, char **argv, char **envp)
{
  char *line;

  signal(SIGINT, ft_controls);
  if (argc != 1)
    return (0); (void)argv;
  while (1)
  {
    ft_display(envp);
    get_next_line(1, &line);
    ft_wrapper(&line);
  }
  return (0);
}
