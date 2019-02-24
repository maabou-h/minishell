/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 22:16:00 by maabou-h          #+#    #+#             */
/*   Updated: 2019/02/21 14:17:15 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *dst, const void *s, int c, size_t n)
{
	const unsigned char	*ns;
	unsigned char		*nd;
	size_t				i;

	ns = (const unsigned char*)s;
	nd = (unsigned char*)dst;
	i = 0;
	while (i < n)
	{
		nd[i] = ns[i];
		if (ns[i] == (unsigned char)c)
			return (nd + i + 1);
		i++;
	}
	return (NULL);
}
