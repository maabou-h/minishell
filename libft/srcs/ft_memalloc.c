/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 11:56:57 by maabou-h          #+#    #+#             */
/*   Updated: 2018/11/27 21:11:35 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memalloc(size_t size)
{
	char	*tmp;

	if (!(tmp = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_bzero(tmp, size + 1);
	return (tmp);
}
