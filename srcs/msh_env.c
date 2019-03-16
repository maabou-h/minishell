/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 16:10:11 by maabou-h          #+#    #+#             */
/*   Updated: 2019/03/16 20:04:54 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		msh_env(char **ftav, char ***ftep)
{
	int	i;
	char	**new;

	i = -1;
	(void)ftav;
	new = *ftep;
	while (new[++i])
	{
			ft_putendl(new[i]);
	}
	return (1);
}

int		msh_unsetenv(char *arg, char ***ftep)
{
	int	i;
	int j;
	char	**new;

	i = -1;
	if (!arg)
		return (1);
	while ((*ftep)[i])
		i++;
	if (!(new = (char**)malloc(sizeof(char*) * i)))
		return (1);
	i = -1;
	j = -1;
	while ((*ftep)[++i])
	{
		if (ft_strncmp((*ftep)[i], arg, ft_strichr((*ftep)[i], '=') - 1))
			new[++j] = ft_strdup((*ftep)[i]);
		ft_strdel(&(*ftep)[i]);
	}
	new[j] = NULL;
	(*ftep) = new;
	return (1);
}

int		msh_bad_arg(char *arg)
{
	int	j;

	j = 0;
	if (!arg)
		return (1);
	while (arg[j] && arg[j] != '=')
		j++;
	if (arg[j] == '\0')
		return (1);
	while (arg[++j])
	{
		if ((!ft_isascii(arg[j]) && arg[j] != '_'))
		{
			ft_putendl_fd("msh: setenv: use with VAR=content format,", 2);
			ft_putendl_fd(" where content is composed of ascii only,", 2);
			ft_putendl_fd(" and the first character should be a letter", 2);
			return (1);
		}
	}
	return (0);
}

int		msh_setenv(char *arg, char ***ftep)
{
	int		i;
	int		j;
	char	**new;

	if (msh_bad_arg(arg))
		return (1);
	i = 0;
	while ((*ftep)[i])
		i++;
	if (!(new = (char**)malloc(sizeof(char*) * (i + 2))))
		return (1);
	i = -1;
	j = -1;
	while ((*ftep)[++i])
	{
		if (ft_strncmp(arg, (*ftep)[i], ft_strichr((*ftep)[i], '=')))
			new[++j] = ft_strdup((*ftep)[i]);
		ft_strdel(&(*ftep)[i]);
	}
	new[++j] = ft_strdup(arg);
	new[j + 1] = NULL;
	(*ftep) = new;
	return (1);
}

int		msh_cd(char **ftav, char ***ftep)
{
	int				i;
	uid_t			uid;
	struct passwd	*p;
	char			*tmp;

	i = 0;
	uid = getuid();
	p = getpwuid(uid);
	tmp = NULL;
	tmp = getcwd(tmp, 4096);
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
		{
			if (chdir(ft_getenv(*ftep, "OLDPWD")) == -1)
				ft_putendl_fd("msh: cd: bad path in $OLDPWD", 2);
		}
		else if (ftav[1] && ft_strcmp(ftav[1], "~") == 0
				&& ft_strlen(ftav[1]) == 1)
			chdir(ft_strjoin("/Users/", p->pw_name));
		else if (!ftav[1])
		{
			if (chdir(ft_getenv(*ftep, "HOME")) == -1)
			ft_putendl_fd("msh: cd: bad path in $HOME", 2);
		}
		else
		{
			if (chdir(ft_dollarenv(ftav[1], *ftep)) == -1)
				ft_putendl_fd("msh: cd: bad access", 2);
		}
	}
	msh_setenv(ft_strjoin("OLDPWD=", tmp), ftep);
	ft_strdel(&tmp);
	tmp = getcwd(tmp, 4096);
	msh_setenv(ft_strjoin("PWD=", tmp), ftep);
	return (1);
}
