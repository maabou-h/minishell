/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 12:03:08 by maabou-h          #+#    #+#             */
/*   Updated: 2018/11/10 20:49:40 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ns1;
	unsigned char	*ns2;
	size_t			i;

	i = 0;
	if (!n)
		return (0);
	ns1 = (unsigned char*)s1;
	ns2 = (unsigned char*)s2;
	while (ns1[i] && ns1[i] == ns2[i] && i < n - 1)
	{
		i++;
	}
	return (ns1[i] - ns2[i]);
}
