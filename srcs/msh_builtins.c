/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_builtins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 00:41:26 by maabou-h          #+#    #+#             */
/*   Updated: 2019/03/16 17:44:34 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		msh_exit(char **ftav, char ***ftep)
{
	(void)ftep;
	ft_free_arr(ftav);
	exit(0);
}

int		msh_help(char **ftav, char ***ftep)
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
	int		i;
	int		j;
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
	if (ftav[1] && ft_strcmp(ftav[1], "-n") == 0)
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
	while (ftav[++i])
	{
		ft_putstr(msh_rm_quotes(ftav[i]));
		ft_putchar(' ');
	}
	ft_putchar('\n');
	return (1);
}
