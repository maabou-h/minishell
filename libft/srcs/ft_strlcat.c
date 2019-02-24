/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 23:37:43 by maabou-h          #+#    #+#             */
/*   Updated: 2018/11/12 23:31:03 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, char const *src, size_t size)
{
	size_t	res;

	res = ft_strlen(src) + size;
	if (size > ft_strlen(dst))
	{
		res = ft_strlen(dst) + ft_strlen(src);
		ft_strncat(dst, src, size - ft_strlen(dst) - 1);
	}
	return (res);
}
