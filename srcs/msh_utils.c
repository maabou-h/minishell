/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 16:06:35 by maabou-h          #+#    #+#             */
/*   Updated: 2019/03/16 17:44:39 by maabou-h         ###   ########.fr       */
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
	output = (char**)malloc(sizeof(char*) * (i + 1));
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
	tmp = getcwd(tmp, 4096);
	uid = getuid();
	pw = getpwuid(uid);
	(*ftep) = (char**)malloc(sizeof(char*) * 11);
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
}

char	**msh_fill_env(char **environ, int i)
{
	char			**ftep;
	char			*c;

	if (!environ || !environ[0])
		msh_create_env(&ftep);
	else
	{
		while (environ[++i])
			;
		ftep = (char**)malloc(sizeof(char*) * (i + 1));
		i = -1;
		while (environ[++i])
		{
			if (ft_strncmp(environ[i], "SHLVL=", 6) == 0)
			{
				c = ft_itoa(ft_atoi(ft_strdup(&environ[i][6])) + 1);
				ftep[i] = ft_strjoin("SHLVL=", c);
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
