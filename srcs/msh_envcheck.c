/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_envcheck.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:11:07 by maabou-h          #+#    #+#             */
/*   Updated: 2019/03/24 15:06:09 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_getenv(char **envp, char *path)
{
	int		i;
	int		x;
	char	*dup;

	i = 0;
	dup = NULL;
	if (path)
	{
		x = ft_strlen(path);
		while (envp[i])
		{
			if (ft_strncmp(envp[i], path, x) == 0 && envp[i][x] == '=')
			{
				dup = ft_strdup(envp[i] + x + 1);
				return (dup);
			}
			i++;
		}
	}
	return (NULL);
}

char	*msh_tildehome(void)
{
	uid_t			uid;
	struct passwd	*p;
	char			*out;

	uid = getuid();
	p = getpwuid(uid);
	out = ft_strjoin("/Users/", p->pw_name);
	return (out);
}

char	*ft_tildecheck(char *eval, int i, int j)
{
	char			*out2;
	char			*out;

	if (ft_strcmp(eval, "~") == 0 && ft_strlen(eval) == 1
			&& (out = msh_tildehome()))
		return (out);
	else
	{
		j = open("/etc/passwd", O_RDONLY);
		while (get_next_line((const int)j, &out) > 0)
		{
			if (ft_strstr(out, &eval[1]))
			{
				i = ft_strichr(out, '/');
				out2 = ft_strndup(&out[i], ft_strichr(&out[i], ':'));
				close(j);
				ft_strdel(&out);
				return (out2);
			}
			ft_strdel(&out);
		}
		ft_putendl_fd("msh: user doesn't exist locally.", 2);
		close(j);
	}
	return (eval);
}

char	*ft_dollarenv(char *eval, char **envp)
{
	int		i;
	char	*dup;

	i = 0;
	dup = NULL;
	if (eval && eval[0] == '$')
	{
		while (envp[i])
		{
			if (ft_strncmp(&eval[1], envp[i], ft_strichr(envp[i], '=') - 1) == 0
			&& eval[ft_strichr(envp[i], '=') + 1] == '\0')
			{
				dup = ft_strdup(&envp[i][ft_strichr(envp[i], '=') + 1]);
				return (dup);
			}
			i++;
		}
	}
	if (eval && eval[0] == '~' && eval[1] != '/')
	{
		dup = ft_tildecheck(eval, 0, 0);
		return (dup);
	}
	dup = ft_strdup(eval);
	return (dup);
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
