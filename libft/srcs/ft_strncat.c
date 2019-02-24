/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 12:37:19 by maabou-h          #+#    #+#             */
/*   Updated: 2018/11/08 23:39:42 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*tmp;
	size_t	i;
	size_t	j;

	tmp = s1;
	j = ft_strlen(s1);
	i = 0;
	while (s2[i] && n--)
	{
		tmp[j++] = s2[i++];
	}
	tmp[j] = '\0';
	return (s1);
}
