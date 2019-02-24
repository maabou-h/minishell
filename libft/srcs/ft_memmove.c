/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 13:45:11 by maabou-h          #+#    #+#             */
/*   Updated: 2018/11/06 22:00:49 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*ndst;
	const char	*nsrc;

	ndst = (char*)dst;
	nsrc = (const char*)src;
	if (ndst > nsrc)
	{
		ndst += len - 1;
		nsrc += len - 1;
		while (len--)
			*ndst-- = *nsrc--;
	}
	else
	{
		while (len-- > 0)
			*ndst++ = *nsrc++;
	}
	return (dst);
}
