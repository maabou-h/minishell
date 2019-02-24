/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 10:47:42 by maabou-h          #+#    #+#             */
/*   Updated: 2019/02/21 14:28:11 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ns;
	size_t			i;

	ns = (unsigned char*)s;
	i = 0;
	while (n--)
	{
		if (ns[i] == (unsigned char)c)
			return (&ns[i]);
		i++;
	}
	return (NULL);
}
