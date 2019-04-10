/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:40:00 by maabou-h          #+#    #+#             */
/*   Updated: 2019/03/24 13:12:34 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	msh_oldpwdcd(char ***ftep)
{
	char *pwd;

	pwd = ft_getenv(*ftep, "OLDPWD");
	if (chdir(pwd) == -1)
		ft_putendl_fd("msh: cd: bad path in $OLDPWD", 2);
	ft_strdel(&pwd);
}

void	msh_homecd(char ***ftep, char *av)
{
	char *env;
	char *pwd;

	env = ft_getenv(*ftep, "HOME");
	pwd = ft_strjoin(env, av);
	if (chdir(pwd) == -1)
		ft_putendl_fd("msh: cd: bad access", 2);
	ft_strdel(&pwd);
	ft_strdel(&env);
}

void	msh_elsecd(char ***ftep, char *av)
{
	char *env;

	env = ft_dollarenv(av, *ftep);
	if (chdir(env) == -1)
		ft_putendl_fd("msh: cd: bad access", 2);
	ft_strdel(&env);
}

void	msh_noargcd(char ***ftep)
{
	char	*env;

	env = ft_getenv(*ftep, "HOME");
	if (chdir(env) == -1)
		ft_putendl_fd("msh: cd: bad path in $HOME", 2);
	ft_strdel(&env);
}

void	msh_cdenv(char ***ftep)
{
	char	*tmp;
	char	*tmp2;

	tmp = NULL;
	tmp = getcwd(tmp, 4096);
	tmp2 = ft_strjoin("OLDPWD=", tmp);
	msh_setenv(tmp2, ftep);
	ft_strdel(&tmp2);
	ft_strdel(&tmp);
	tmp = getcwd(tmp, 4096);
	tmp2 = ft_strjoin("PWD=", tmp);
	ft_strdel(&tmp);
	msh_setenv(tmp2, ftep);
	ft_strdel(&tmp2);
}
