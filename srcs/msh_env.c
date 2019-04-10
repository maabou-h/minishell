/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 16:10:11 by maabou-h          #+#    #+#             */
/*   Updated: 2019/03/23 23:57:33 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		msh_env(char **ftav, char ***ftep)
{
	int	i;

	i = -1;
	(void)ftav;
	while ((*ftep)[++i])
	{
		ft_putendl((*ftep)[i]);
	}
}

void		msh_unsetenv(char *arg, char ***ftep)
{
	int		i;
	int		j;
	char	**new;

	i = 0;
	j = 0;
	if (!arg)
		return ;
	while ((*ftep)[++i])
		j += (ft_strncmp((*ftep)[i], arg, ft_strichr((*ftep)[i], '=')) == 0);
	if (j == 0)
		return ;
	if (!(new = (char**)malloc(sizeof(char*) * (i + 1))))
		return ;
	i = -1;
	j = 0;
	while ((*ftep)[++i])
	{
		if (ft_strncmp((*ftep)[i], arg, ft_strichr((*ftep)[i], '=')))
			new[j++] = ft_strdup((*ftep)[i]);
	}
	ft_free_arr(*ftep);
	new[j] = NULL;
	(*ftep) = new;
}

void		msh_setenv(char *arg, char ***ftep)
{
	int		i;
	int		j;
	char	**new;

	if (msh_bad_arg(arg))
		return ;
	i = 0;
	while ((*ftep)[i])
		i++;
	if (!(new = (char**)malloc(sizeof(char*) * (i + 2))))
		return ;
	i = -1;
	j = 0;
	while ((*ftep)[++i])
	{
		if (ft_strncmp(arg, (*ftep)[i], ft_strichr((*ftep)[i], '=') + 1))
			new[j++] = ft_strdup((*ftep)[i]);
	}
	ft_free_arr(*ftep);
	new[j] = ft_strdup(arg);
	new[j + 1] = NULL;
	(*ftep) = new;
}
