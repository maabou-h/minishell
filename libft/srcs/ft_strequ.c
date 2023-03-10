/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 21:46:12 by maabou-h          #+#    #+#             */
/*   Updated: 2018/11/12 23:04:28 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	size_t	n;

	n = 0;
	if (!s1 || !s2)
		return (0);
	if (ft_strlen(s1) == 0 && ft_strlen(s2) == 0)
		return (1);
	while (s1[n] || s2[n])
	{
		if (s1[n] != s2[n])
			return (0);
		n++;
	}
	return (1);
}
