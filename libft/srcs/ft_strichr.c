/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 17:57:56 by maabou-h          #+#    #+#             */
/*   Updated: 2019/03/14 14:57:41 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strichr(const char *s, int c)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	if (!s)
		return (0);
	while (s[++i])
	{
		j++;
		if (s[i] == (char)c)
			break;
	}
	return (i);
}
