/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 14:39:30 by maabou-h          #+#    #+#             */
/*   Updated: 2019/02/24 22:39:45 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char *ft_getenv(char **envp, char *path)
{
  int i;
  int x;

  i = 0;
  if (!path)
    return (NULL);
  x = ft_strlen(path);
  while (envp[i])
  {
    if (ft_strncmp(envp[i], path, x) == 0 && envp[i][x] == '=')
        return(envp[i] + x + 1);
    i++;
  }
  return (NULL);
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

int is_valid(char *arg)
{
  if (ft_strcmp(arg, "./") == 0)
  {
    ft_putstr("minishell: is a directory: ");
    ft_putendl(arg);
  }
  else if (ft_strcmp(arg, "exit") == 0)
    exit(0);
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

  if ((lstat(fp, &buf) == -1) || (!(buf.st_mode & S_IRWXO)) || ((buf.st_mode & S_IFMT) == S_IFDIR))
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
  if (!argv[0] || is_valid(argv[0]))
    return ;
  else
  {
    while (paths[i])
    {
      abs = ft_strjoin(paths[i], "/");
      fp = ft_strjoin(abs, argv[0]);
      if ((good = is_exec_path(fp)))
        break ;
      i++;
      free(abs);
      free(fp);
    }
  }
  if (good == 1)
    return ;
  abs = ft_strjoin(ft_getenv(envp, "PWD"), "/");
  fp = ft_strjoin(abs, argv[0]);
  if (!(good = is_exec_path(fp)) && ft_strcmp(argv[0], "./"))
  {
    ft_putstr("minishell: command not found: ");
    ft_putendl(argv[0]);
  }
  free(abs);
  free(fp);
}

void print_prompt(char **envp)
{
  ft_putstr("\033[0;32m");
  ft_putstr(ft_getenv(envp, "USER"));
  ft_putstr("\033[0m @ \033[0;31m");
  ft_putstr(ft_getenv(envp, "PWD"));
  ft_putstr(" \033[0m$>");
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
    print_prompt(envp);
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
