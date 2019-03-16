/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 14:39:30 by maabou-h          #+#    #+#             */
/*   Updated: 2019/03/16 20:49:45 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		msh_valid_path(char *exec, char *folder)
{
	struct stat		buf;
	DIR				*d;

	if (!(d = opendir(folder)))
		return (0);
	if (lstat(exec, &buf) == -1)
	{
		closedir(d);
		return (0);
	}
	if ((buf.st_mode & S_IXUSR))
	{
		closedir(d);
		return (1);
	}
	if (access(exec, X_OK) == -1)
	{
		ft_putendl_fd("msh: permission denied.", 2);
		return (1);
	}
	closedir(d);
	return (0);
}

char	*msh_path(char *exec, char **ftep)
{
	char	**paths;
	char	*tmpa;
	char	*tmpb;
	int		i;

	paths = ft_strsplit(ft_getenv(ftep, "PATH"), ':');
	i = -1;
	tmpb = NULL;
	if ((exec[0] == '.' && exec[1] == '/' && msh_valid_path(exec, "./"))
		|| (exec[0] == '/' && msh_valid_path(exec, "/")))
			return (exec);
	while (paths[++i])
	{
		tmpa = ft_strjoin(paths[i], "/");
		tmpb = ft_strjoin(tmpa, exec);
		if (msh_valid_path(tmpb, tmpa))
			return (tmpb);
	}
	ft_putendl_fd("msh: command not found.", 2);
	ft_strdel(&tmpb);
	ft_strdel(&tmpa);
	return (NULL);
}

int		msh_builtin(char **ftav, char ***ftep)
{
	if (ft_strcmp(ftav[0], "exit") == 0)
		return (msh_exit(ftav, ftep));
	else if (ft_strcmp(ftav[0], "env") == 0)
		return (msh_env(ftav, ftep));
	else if (ft_strcmp(ftav[0], "setenv") == 0)
		return (msh_setenv(ftav[1], ftep));
	else if (ft_strcmp(ftav[0], "unsetenv") == 0)
		return (msh_unsetenv(ftav[1], ftep));
	else if (ft_strcmp(ftav[0], "echo") == 0)
		return (msh_echo(ftav));
	else if (ft_strcmp(ftav[0], "cd") == 0)
		return (msh_cd(ftav, ftep));
	else if (ft_strcmp(ftav[0], "help") == 0)
		return (msh_exit(ftav, ftep));
	else
		return (0);
}

void	msh_exec(char **ftav, char ***ftep)
{
	pid_t	pid;
	char	*path;

	msh_setenv(ft_strjoin("_=", ftav[0]), ftep);
	if (!ftav || !ftav[0] || msh_builtin(ftav, ftep))
		return ;
	path = NULL;
	path = msh_path(ftav[0], *ftep);
	ft_strdel(&ftav[0]);
	if ((ftav[0] = path) == NULL || !path)
		return ;
	pid = fork();
	if (pid == 0)
		if (execve(ftav[0], ftav, *ftep) == -1)
			exit(0);
	wait(&pid);
	if (pid < 0)
	{
		kill(pid, SIGTERM);
		pid = 0;
	}
}

int		main(int ac, char **av, char **envp)
{
	char	*line;
	char	**ftav;
	char	**ftep;
	int		i;
	int		flag;

	if (ac != 1)
		return (0);
	(void)av;
	flag = 1;
	while (42)
	{
		if (flag)
			ftep = msh_fill_env(envp, -1);
		i = -1;
		msh_prompt(ftep);
		get_next_line(0, &line);
		ftav = ft_strsplit(line, ';');
		while (ftav[++i])
			msh_exec(msh_exp(ft_splitwhitespaces(ftav[i]), &ftep), &ftep);
		ft_strdel(&line);
		flag = 0;
	}
	return (0);
}
