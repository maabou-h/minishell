/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 10:47:42 by maabou-h          #+#    #+#             */
/*   Updated: 2018/11/08 23:21:15 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*ns;

	ns = (char*)b;
	while (len > 0)
	{
		*ns++ = (unsigned char)c;
		len--;
	}
	return (b);
}
