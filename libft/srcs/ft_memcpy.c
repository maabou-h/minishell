/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 22:16:00 by maabou-h          #+#    #+#             */
/*   Updated: 2018/11/27 21:08:39 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*ndest;
	const char	*nsrc;
	size_t		i;

	i = 0;
	ndest = (char*)dst;
	nsrc = (const char*)src;
	while (i < n)
	{
		ndest[i] = nsrc[i];
		i++;
	}
	ndest[i] = '\0';
	return (dst);
}
