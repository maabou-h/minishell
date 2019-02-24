/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 22:00:25 by maabou-h          #+#    #+#             */
/*   Updated: 2018/11/12 23:10:19 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	if ((ft_strlen(s1) == 0 && ft_strlen(s2) == 0) || !n)
		return (1);
	while (i < n - 1 && s1[i] == s2[i] && s1[i])
	{
		i++;
	}
	return (s1[i] == s2[i]);
}
