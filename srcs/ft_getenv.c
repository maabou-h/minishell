/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:11:07 by maabou-h          #+#    #+#             */
/*   Updated: 2019/03/16 19:55:01 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_getenv(char **envp, char *path)
{
	int i;
	int x;

	i = 0;
	if (path)
	{
		x = ft_strlen(path);
		while (envp[i])
		{
			if (ft_strncmp(envp[i], path, x) == 0 && envp[i][x] == '=')
				return (envp[i] + x + 1);
			i++;
		}
	}
	return (NULL);
}

char	*ft_tildecheck(char *eval, int i)
{
	char			*out;
	char			*out2;
	uid_t			uid;
	struct passwd	*p;
	int				j;

	out = NULL;
	out2 = NULL;
	if (ft_strcmp(eval, "~") == 0)
	{
		uid = getuid();
		p = getpwuid(uid);
		out = ft_strjoin("/Users/", p->pw_name);
		return (out);
	}
	else
	{
		j = open("/etc/passwd", O_RDONLY);
		while (get_next_line((const int)j, &out) > 0)
		{
			if (ft_strstr(out, &eval[1]))
			{
				i = ft_strichr(out, '/');
				out2 = ft_strndup(&out[i], ft_strichr(&out[i], ':'));
				return (out2);
			}
			ft_strdel(&out);
		}
		ft_putendl("msh: user doesn't exist locally.");
	}
	return (eval);
}

char	*ft_dollarenv(char *eval, char **envp)
{
	int i;

	i = 0;
	if (eval && eval[0] == '$')
	{
		while (envp[i])
		{
			if (ft_strncmp(&eval[1], envp[i], ft_strichr(envp[i], '=') - 1) == 0
			&& eval[ft_strichr(envp[i], '=') + 1] == '\0')
				return (ft_strdup(&envp[i][ft_strichr(envp[i], '=') + 1]));
			i++;
		}
	}
	if (eval && eval[0] == '~')
		return (ft_tildecheck(eval, 0));
	return (eval);
}
