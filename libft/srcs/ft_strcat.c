/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 22:16:04 by maabou-h          #+#    #+#             */
/*   Updated: 2018/11/08 23:48:00 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char *tmp;

	tmp = s1;
	tmp += ft_strlen(s1);
	while (*s2)
	{
		*tmp++ = *s2++;
	}
	*tmp = '\0';
	return (s1);
}
