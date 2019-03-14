/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 14:39:30 by maabou-h          #+#    #+#             */
/*   Updated: 2019/03/14 19:24:41 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	msh_prompt(char **envp)
{
	char	*git;
	char	*opengit;
	char	*out;

	opengit = ft_strjoin(ft_getenv(envp, "PWD"), "/.git/HEAD");
	get_next_line(open(opengit, O_RDONLY), &git);
	out = ft_strrchr(git, '/');
	ft_putstr("\033[38;5;0;48;5;28m⮀\033[0m\033[48;5;28m ");
	ft_putstr(ft_getenv(envp, "USER"));
	ft_putstr(" \033[0m\033[48;5;74;38;5;28m⮀⮀⮀\033[0m\033[38;5;0;48;5;74m ");
	ft_putstr(ft_getenv(envp, "PWD"));
	ft_putstr(" ~ \033[0m\033[38;5;74m⮀\033[0m");
	if (out)
	{
		ft_putstr("\033[38;5;0;48;5;220m⮀\033[0m\033[48;5;220;38;5;0m  ");
		ft_putstr(&out[1]);
		ft_putstr(" \033[0m\033[38;5;220m⮀\033[0m");
	}
}

int		valid_path(char *exec, char *folder)
{
	struct stat		buf;
	DIR				*d;

	if (!(d = opendir(folder)))
		return (0);
	if (lstat(exec, &buf) == -1)
		return (0);
	if ((buf.st_mode & S_IXUSR))
		return (1);
	closedir(d);
	return (0);
}

char	*msh_path(char *exec, char **ftep)
{
	char	**paths;
	char 	*tmpa;
	char	*tmpb;
	int		i;

	paths = ft_strsplit(ft_getenv(ftep, "PATH"), ':');
	i = 0;
	tmpb = NULL;
	if (exec[0] == '.' && exec[1] == '/' && valid_path(exec, "./"))
		return (exec);
	while (paths[i])
	{
		tmpa = ft_strjoin(paths[i], "/");
		tmpb = ft_strjoin(tmpa, exec);
		if (valid_path(tmpb, tmpa))
		{
			return (tmpb);
		}
		i++;
	}
	if (exec[0] == '/')
		ft_printf("msh: %s is a directory.\n", exec);
	else
		ft_printf("msh: %s: command not found.\n", exec);
	ft_strdel(&tmpb);
	ft_strdel(&tmpa);
	return (NULL);
}

int		msh_builtin(char **ftav, char **ftep)
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

char	**msh_exp(char **input, char **env)
{
	int		i;
	char	**output;

	i = -1;
	while (input[++i])
		;
	output = (char**)malloc(sizeof(char*) * (i + 1));
	i = -1;
	while (input[++i])
		output[i] = ft_dollarenv(input[i], env);
	output[i] = NULL;
	return (output);
}

void	msh_exec(char **ftav, char **ftep)
{
	pid_t	pid;
	char	*path;

	if (!ftav || !ftav[0] || msh_builtin(ftav, ftep))
			return ;
	path = NULL;
	path = msh_path(ftav[0], ftep);
	ft_strdel(&ftav[0]);
	if ((ftav[0] = path) == NULL || !path)
		return ;
	pid = fork();
	if (pid == 0)
	{
		if (execve(ftav[0], ftav, ftep) == -1)
			exit(0);
	}
	wait(&pid);
	if (pid < 0)
	{
		kill(pid, SIGTERM);
		pid = 0;
	}
}

char	**msh_fill_env(char **environ, int *flag)
{
	char	**ftep;
	int		i;
	uid_t	uid;
	char	*tmp;
	struct passwd *pw;

	uid = getuid();
	pw = getpwuid(uid);
	tmp = NULL;
	i = -1;
	*flag = 0;
	tmp = getcwd(tmp, 4096);
	if (!environ || !environ[0])
	{
		ftep = (char**)malloc(sizeof(char*) * 512);
		ftep[0] = ft_strjoin("PWD=", tmp);
		ftep[1] = ft_strdup("PATH=/usr/bin:/usr/sbin:/Users/maabou-h/\
				.brew/bin:/bin:/sbin");
		ftep[2] = ft_strjoin("USER=", pw->pw_name);
		ftep[3] = ft_strdup("LANG=en_US.UTF-8");
		ftep[4] = ft_strdup("TERM=xterm-256color");
		ftep[5] = ft_strjoin("HOME=/Users/", pw->pw_name);
		ftep[6] = ft_strdup("SHELL=minishell");
		ftep[7] = NULL;
	}
	else
	{
		while (environ[++i])
			;
		ftep = (char**)malloc(sizeof(char*) * (i + 512));
		i = -1;
		while (environ[++i])
			ftep[i] = ft_strdup(environ[i]);
		ftep[i] = NULL;
	}
	return (ftep);
}


int		main(int ac, char **av, char **envp)
{
	char	*line;
	char	**ftav;
	char	**ftep;
	int 	i;
	int		flag;

	if (ac != 1)
		return (0);
	(void)av;
	flag = 1;
	while (42)
	{
		if (flag)
			ftep = msh_fill_env(envp, &flag);
		i = -1;
		msh_prompt(ftep);
		get_next_line(0, &line);
		ftav = ft_strsplit(line, ';');
		while (ftav[++i])
			msh_exec(msh_exp(ft_splitwhitespaces(ftav[i]), ftep), ftep);
		ft_strdel(&line);
		flag = 0;
	}
	return (0);
}
