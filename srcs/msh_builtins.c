/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_builtins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 00:41:26 by maabou-h          #+#    #+#             */
/*   Updated: 2019/03/14 19:25:12 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		msh_exit(char **ftav, char **ftep)
{
	(void)ftep; // change here
	ft_free_arr(ftav);
	exit(0);
}

int		msh_env(char **ftav, char **ftep)
{
	int	i;

	i = -1;
	(void)ftav; 
	while (ftep[++i])
		if (ftep[i][0] != '\0')
			ft_putendl(ftep[i]);
	return (1);
}

int		msh_setenv(char *arg, char **ftep)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arg[j] && arg[j] != '=')
		j++;
	if (arg[j] == '\0')
		return (1);
	j++;
	while (arg[j])
	{
		if (arg[j] == '=')
		{
			ft_putstr("msh: setenv: '=' is a special character");
			ft_putendl(" and should not be used inside content");
			return (1);
		}
		j++;
	}
	while (ftep[i])
		i++;
	ftep[i] = arg;
	ftep[i + 1] = NULL;
	return (1);
}

int		msh_unsetenv(char *arg, char **ftep)
{
	int	i;

	i = -1;
	arg[ft_strichr(arg, '=')] = '\0';
	while (ftep[++i])
	{
		if (ft_strncmp(ftep[i], arg, ft_strlen(arg)) == 0)
			ftep[i][0] = '\0';
	}
	return (1);
}

int		msh_cd(char **ftav, char **ftep)
{
	int				i;
	uid_t			uid;
	struct passwd	*p;

	i = 0;
	uid = getuid();
	p = getpwuid(uid);
	(void)ftep;
	while (ftav[++i])
		;
	if (i > 2)
	{
		ft_putendl("msh: cd: too many arguments.");
		return (1);
	}
	else
	{
		i = -1;
		if (ftav[1] && ft_strcmp(ftav[1], "~"))
			chdir(ftav[1]);
		else
			chdir(ft_strjoin("/Users/", p->pw_name));
	}
	return (1);
}

int		msh_help(char **ftav, char **ftep)
{
	(void)ftav;
	(void)ftep; 
	ft_putendl("Welcome to msh help. A UNIX minimalistic shell.\n\
			Below are some builtin commands you can use:\n\
			help, cd, env, setenv, unsetenv, echo, exit\n\
			Thanks for using maabou-h's minishell.");
	return (1);
}

char	*msh_rm_quotes(char *ftav)
{
	int	i;
	int	j;
	char	*out;

	i = -1;
	j = -1;
	if (ftav[0] == '"' && ftav[ft_strlen(ftav) - 1] == '"')
	{
		out = (char*)malloc(sizeof(char) * (ft_strlen(ftav) - 1));
		while (++i < (int)ft_strlen(ftav))
			if (ftav[i] != '"')
				out[++j] = ftav[i];
		return (out);
	}
	out = NULL;
	return (ftav);
}

int		msh_echo(char **ftav)
{
	int	i;

	i = 0;
	if (ft_strcmp(ftav[1], "-n") == 0)
	{
		if (!ftav[2])
			return (1);
		ft_putstr(msh_rm_quotes(ftav[2]));
		return (1);
	}
	if (!ftav[1])
	{
		ft_putchar('\n');
		return (1);
	}
	while(ftav[++i])
	{
		ft_putstr(msh_rm_quotes(ftav[i]));
		ft_putchar(' ');
	}
	ft_putchar('\n');
	return (1);
}
