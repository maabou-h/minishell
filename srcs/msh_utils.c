/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 16:06:35 by maabou-h          #+#    #+#             */
/*   Updated: 2019/03/23 23:58:47 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**msh_exp(char **input, char ***ftep)
{
	int		i;
	char	**output;

	i = -1;
	while (input[++i])
		;
	if (!(output = (char**)malloc(sizeof(char*) * (i + 1))))
		return (NULL);
	i = -1;
	while (input[++i])
		output[i] = ft_dollarenv(input[i], *ftep);
	output[i] = NULL;
	return (output);
}

void	msh_create_env(char ***ftep)
{
	char			*tmp;
	uid_t			uid;
	struct passwd	*pw;

	tmp = NULL;
	if (!(tmp = getcwd(tmp, 4096)))
		return ;
	uid = getuid();
	if (!(pw = getpwuid(uid)))
		return ;
	if (!((*ftep) = (char**)malloc(sizeof(char*) * 11)))
		return ;
	(*ftep)[0] = ft_strjoin("PWD=", tmp);
	(*ftep)[1] = ft_strjoin("USER=", pw->pw_name);
	(*ftep)[2] = ft_strdup("LANG=en_US.UTF-8");
	(*ftep)[3] = ft_strdup("TERM=xterm-256color");
	(*ftep)[4] = ft_strjoin("HOME=/Users/", pw->pw_name);
	(*ftep)[5] = ft_strdup("SHELL=minishell");
	(*ftep)[6] = ft_strdup("SHLVL=1");
	(*ftep)[7] = ft_strjoin("OLDPWD=", tmp);
	(*ftep)[8] = ft_strdup("PATH=/bin:/usr/bin:/sbin:/usr/sbin");
	(*ftep)[9] = ft_strdup("_=minishell");
	(*ftep)[10] = NULL;
	ft_strdel(&tmp);
}

char	*msh_shlvl(char *environ)
{
	char			*c;
	char			*d;
	char			*ftep;

	d = ft_strdup(environ);
	c = ft_itoa(ft_atoi(d) + 1);
	ftep = ft_strjoin("SHLVL=", c);
	ft_strdel(&c);
	ft_strdel(&d);
	return (ftep);
}

char	**msh_fill_env(char **environ, int i)
{
	char			**ftep;

	ftep = NULL;
	if (!environ || !environ[0])
		msh_create_env(&ftep);
	else
	{
		while (environ[++i])
			;
		if (!(ftep = (char**)malloc(sizeof(char*) * (i + 1))))
			return (NULL);
		i = -1;
		while (environ[++i])
		{
			if (ft_strncmp(environ[i], "SHLVL=", 6) == 0)
			{
				ftep[i] = msh_shlvl(&environ[i][6]);
			}
			else
				ftep[i] = ft_strdup(environ[i]);
		}
		ftep[i] = NULL;
	}
	return (ftep);
}

void	msh_prompt(char **envp)
{
	char	*git;
	char	*out;
	char	*dir;
	char	*usr;
	int		fd;

	out = NULL;
	usr = ft_getenv(envp, "USER");
	dir = ft_getenv(envp, "PWD");
	fd = open(".git/HEAD", O_RDONLY);
	if (fd > 0 && get_next_line((const int)fd, &git) > 0)
		out = ft_strdup(ft_strrchr(git, '/'));
	msh_promptbase(usr, dir);
	if (out)
	{
		ft_putstr("\033[38;5;0;48;5;220m⮀\033[0m\033[48;5;220;38;5;0m  ");
		ft_putstr(&out[1]);
		ft_putstr(" \033[0m\033[38;5;220m⮀\033[0m");
		ft_strdel(&out);
		ft_strdel(&git);
	}
	ft_strdel(&usr);
	ft_strdel(&dir);
	if (fd > 0)
		close(fd);
}
