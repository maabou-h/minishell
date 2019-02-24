/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 05:27:51 by maabou-h          #+#    #+#             */
/*   Updated: 2018/11/27 21:14:46 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new;

	if (!s1)
		return (NULL);
	if (!(new = (char*)ft_memalloc(ft_strlen(s1))))
		return (NULL);
	new = ft_strcpy(new, s1);
	return (new);
}
