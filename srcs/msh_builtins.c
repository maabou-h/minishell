/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_builtins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 00:41:26 by maabou-h          #+#    #+#             */
/*   Updated: 2019/03/24 00:00:58 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		msh_help(void)
{
	ft_putendl("Welcome to msh help. A UNIX minimalistic shell.\n\
			Below are some builtin commands you can use:\n\
			help, cd, env, setenv, unsetenv, echo, exit\n\
			Thanks for using maabou-h's minishell.");
	return (1);
}

int		msh_echo(char **ftav)
{
	int	i;

	i = 0;
	if (ftav[1] && ft_strcmp(ftav[1], "-n") == 0)
	{
		if (!ftav[2])
			return (1);
		ft_putstr(ftav[2]);
		return (1);
	}
	if (!ftav[1])
	{
		ft_putchar('\n');
		return (1);
	}
	while (ftav[++i])
	{
		ft_printf("%s ", ftav[i]);
	}
	ft_putchar('\n');
	return (1);
}

int		msh_cd(char **ftav, char ***ftep)
{
	int		i;

	i = 0;
	while (ftav[++i])
		;
	if (i > 2)
	{
		ft_putendl_fd("msh: cd: too many arguments.", 2);
		return (1);
	}
	else
	{
		if (ftav[1] && ft_strcmp(ftav[1], "-") == 0
				&& ft_strlen(ftav[1]) == 1)
			msh_oldpwdcd(ftep);
		else if (ftav[1] && ft_strncmp(ftav[1], "~", 1) == 0)
			msh_homecd(ftep, &ftav[1][1]);
		else if (!ftav[1])
			msh_noargcd(ftep);
		else
			msh_elsecd(ftep, ftav[1]);
	}
	msh_cdenv(ftep);
	return (1);
}
