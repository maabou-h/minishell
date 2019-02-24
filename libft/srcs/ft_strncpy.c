/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 12:39:16 by maabou-h          #+#    #+#             */
/*   Updated: 2018/11/08 23:41:04 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t x;

	x = 0;
	while (x < len && src[x] != '\0')
	{
		dst[x] = src[x];
		x++;
	}
	while (x < len)
	{
		dst[x] = '\0';
		x++;
	}
	return (dst);
}
