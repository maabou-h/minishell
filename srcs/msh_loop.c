/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 14:39:30 by maabou-h          #+#    #+#             */
/*   Updated: 2019/03/24 15:02:44 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		msh_valid_path(char *exec, char flag)
{
	struct stat		buf;

	if (lstat(exec, &buf) == -1)
	{
		return (0);
	}
	if ((buf.st_mode & S_IFMT) == S_IFDIR)
	{
		if (flag)
			ft_putendl_fd("msh: is a directory.", 2);
		return (0);
	}
	if (access(exec, X_OK) == -1)
	{
		if (flag)
			ft_putendl_fd("msh: permission denied.", 2);
		return (0);
	}
	return (1);
}

int		msh_builtin(char **ftav, char ***ftep, int ret)
{
	char	*path;

	if (ft_strcmp(ftav[0], "exit") == 0)
	{
		ft_free_arr(*ftep);
		ft_free_arr(ftav);
		exit(0);
	}
	else if ((ret = ft_strcmp(ftav[0], "env")) == 0)
		msh_env(ftav, ftep);
	else if ((ret = ft_strcmp(ftav[0], "setenv")) == 0)
		msh_setenv(ftav[1], ftep);
	else if ((ret = ft_strcmp(ftav[0], "unsetenv")) == 0)
		msh_unsetenv(ftav[1], ftep);
	else if ((ret = ft_strcmp(ftav[0], "echo")) == 0)
		msh_echo(ftav);
	else if ((ret = ft_strcmp(ftav[0], "cd")) == 0)
		msh_cd(ftav, ftep);
	else if ((ret = ft_strcmp(ftav[0], "help")) == 0)
		msh_help();
	path = ft_strjoin("_=", ftav[0]);
	msh_setenv(path, ftep);
	ft_strdel(&path);
	return (ret ? 0 : 1);
}

char	**msh_av(char *path, char **ftav)
{
	int		i;
	char	**new;

	i = 0;
	while (ftav[i])
		i++;
	if (!(new = (char**)malloc(sizeof(char*) * (i + 2))))
		return (NULL);
	i = 0;
	new[i] = ft_strdup(path);
	while (ftav[++i])
		new[i] = ft_strdup(ftav[i]);
	new[i] = NULL;
	return (new);
}

void	msh_exec(char **ftav, char ***ftep)
{
	pid_t	pid;
	char	*path;
	char	**newav;

	if (!ftav || !ftav[0] || msh_builtin(ftav, ftep, 1)
			|| !(path = msh_path(ftav[0], *ftep, -1)))
		return ;
	newav = msh_av(path, ftav);
	ft_strdel(&path);
	pid = fork();
	if (pid == 0)
	{
		path = ft_strjoin("_=", ftav[0]);
		msh_setenv(path, ftep);
		ft_strdel(&path);
		if (execve(newav[0], newav, *ftep) == -1)
			exit(0);
	}
	wait(&pid);
	if (pid < 0)
	{
		kill(pid, SIGTERM);
		pid = 0;
	}
	ft_free_arr(newav);
}

void	msh_loop(char **ftav, char ***ftep)
{
	char	**split;
	char	**avft;

	if (!(split = ft_splitwhitespaces(*ftav)))
		return ;
	if (!(avft = msh_exp(split, ftep)))
		return ;
	msh_check_path(ftep);
	msh_exec(avft, ftep);
	ft_free_arr(avft);
	ft_free_arr(split);
}
