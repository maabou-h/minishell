/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:39:36 by maabou-h          #+#    #+#             */
/*   Updated: 2019/03/24 15:04:59 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	msh_promptbase(char *usr, char *dir)
{
	ft_putstr("\033[38;5;0;48;5;28m⮀\033[0m\033[48;5;28m ");
	ft_putstr(usr);
	ft_putstr(" \033[0m\033[48;5;74;38;5;28m⮀⮀⮀\033[0m\033[38;5;0;48;5;74m ");
	ft_putstr(dir);
	ft_putstr(" ~ \033[0m\033[38;5;74m⮀\033[0m");
}

char	*msh_joinpath(char *path, char *file)
{
	char	*tmpa;
	char	*tmpb;

	tmpa = ft_strjoin(path, "/");
	tmpb = ft_strjoin(tmpa, file);
	ft_strdel(&tmpa);
	return (tmpb);
}

char	*msh_path(char *ex, char **ftep, int i)
{
	char	**paths;
	char	*env;
	char	*tmpb;

	env = ft_getenv(ftep, "PATH");
	paths = ft_strsplit(env, ':');
	ft_strdel(&env);
	tmpb = NULL;
	if (ex[0] == '/'
			|| (ex[0] == '.' && ex[1] == '/' && msh_valid_path(ex, 1)))
	{
		tmpb = ft_strdup(ex);
		ft_free_arr(paths);
		return (tmpb);
	}
	while (paths[++i])
	{
		tmpb = msh_joinpath(paths[i], ex);
		if (msh_valid_path(tmpb, 0) && ex[0] != '.' && ex[1] != '/')
			break ;
		ft_strdel(&tmpb);
	}
	ft_free_arr(paths);
	(!tmpb) ? ft_putendl_fd("msh: command not found.", 2) : 0;
	return (tmpb);
}

void	msh_check_path(char ***ftep)
{
	char	*env;
	char	*tmp;

	env = ft_strdup("PATH=");
	tmp = ft_getenv(*ftep, "PATH");
	if (!tmp)
		msh_setenv(env, ftep);
	if (tmp)
		ft_strdel(&tmp);
	ft_strdel(&env);
}

int		main(int ac, char **av, char **envp)
{
	char	*line;
	char	**ftav;
	char	**ftep;
	int		i;

	(void)av;
	if (ac != 1 || !isatty(0))
		return (0);
	ftep = msh_fill_env(envp, -1);
	while (42)
	{
		i = -1;
		msh_prompt(ftep);
		if (get_next_line(0, &line) <= 0)
			break ;
		ftav = ft_strsplit(line, ';');
		while (ftav[++i])
			msh_loop(&ftav[i], &ftep);
		ft_free_arr(ftav);
		ft_strdel(&line);
	}
	return (0);
}
