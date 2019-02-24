/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:17:04 by maabou-h          #+#    #+#             */
/*   Updated: 2019/02/19 08:13:31 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_notstrjoin(char *s1, char *s2, size_t n)
{
	char	*new;
	size_t	i;
	size_t	pos;

	if (!(new = ft_memalloc((sizeof(char) * (ft_strlen(s1) + n + 1)))))
		return (NULL);
	i = 0;
	pos = 0;
	while (s1[i])
		new[pos++] = s1[i++];
	i = 0;
	while (n-- && s2[i])
		new[pos++] = s2[i++];
	new[pos] = '\0';
	return (new);
}

static int	ft_buf(const int fd, char **line, char **buf)
{
	char	*tmp;

	tmp = *line;
	*line = ft_notstrjoin(tmp, buf[fd], (ft_strlen(buf[fd]) -
				ft_strlen(ft_strchr(buf[fd], '\n'))));
	free(tmp);
	tmp = buf[fd];
	buf[fd] = ft_strdup(ft_strchr(buf[fd], '\n'));
	free(tmp);
	if (buf[fd])
	{
		tmp = buf[fd];
		buf[fd] = ft_strdup(buf[fd] + 1);
		free(tmp);
		return (1);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char	*buf[4895];
	int			ret;

	if (fd < 0 || !line || fd > 4894 || !(*line = ft_strnew(0)))
		return (-1);
	ret = 1;
	while (ret != -1)
	{
		if (buf[fd] == NULL)
		{
			buf[fd] = ft_strnew(BUFF_SIZE);
			if ((ret = read(fd, buf[fd], BUFF_SIZE)) == -1)
				return (-1);
		}
		if (ft_buf(fd, line, buf))
			return (1);
		if (ret == 0)
		{
			if (!*line[0])
				return (0);
			return (1);
		}
	}
	return (-1);
}
