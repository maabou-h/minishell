/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 14:39:30 by maabou-h          #+#    #+#             */
/*   Updated: 2019/02/24 20:56:01 by maabou-h         ###   ########.fr       */
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

char  **find_exec_path(char **envp)
{
  int i;

  i = 0;
  while (envp[i])
  {
    if (ft_strncmp(envp[i], "PATH", 4) == 0 && envp[i][4] == '=')
        return (ft_strsplit(envp[i] + 5, ':'));
    i++;
  }
  return (NULL);
}

int is_builtin(char *arg)
{
  if (ft_strcmp(arg, "exit") == 0)
    return (1);
  else if (ft_strcmp(arg, "echo") == 0)
    return (1);
  else if (ft_strcmp(arg, "cd") == 0)
    return (1);
  else if (ft_strcmp(arg, "env") == 0)
    return (1);
  else if (ft_strcmp(arg, "setenv") == 0)
    return (1);
  else if (ft_strcmp(arg, "unsetenv") == 0)
    return (1);
  return (0);
}

int is_exec_path(char *fp)
{
  struct stat buf;

  if ((lstat(fp, &buf) == -1) || (!(buf.st_mode & S_IRWXO)))
    return (0);
  return (1);
}

void ft_wrapper(char **argv, char **envp)
{
  char **paths;
  char *abs;
  char *fp;
  int  i;
  int good;

  paths = find_exec_path(envp);
  i = 0;
  if (is_builtin(argv[0]))
    exit(0);
  else
  {
    while (paths[i])
    {
      abs = ft_strjoin(paths[i], "/");
      fp = ft_strjoin(abs, argv[0]);
      if ((good = is_exec_path(fp))) // to code
        break ;
        i++;
    }
  }
  if (good == 0)
  {
    ft_putstr("minishell: command not found: ");
    ft_putendl(argv[0]);
  }
}


void ft_controls(int sig_num)
{
  sig_num = 0;
}

int main(int argc, char **argv, char **envp)
{
  char *line;
  char **myargv;
  int i;

  myargv = NULL;
  signal(SIGINT, ft_controls); (void)argc; (void)argv;
  while (1)
  {
    i = 0;
    ft_display(envp);
    get_next_line(1, &line);
    myargv = ft_strsplit(line, ';');
    while (myargv[i])
    {
      ft_wrapper(ft_splitwhitespaces(myargv[i]), envp);
      i++;
    }
    free(line);
  }
  return (0);
}
