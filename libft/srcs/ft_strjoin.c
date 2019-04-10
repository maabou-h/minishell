/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:41:16 by maabou-h          #+#    #+#             */
/*   Updated: 2019/03/23 20:26:20 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	i;
	size_t	pos;

	if (!s1 || !s2)
		return (NULL);
	if (!(new = (char*)malloc(sizeof(char) * (ft_strlen(s1)
						+ ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	pos = 0;
	while (s1[i])
		new[pos++] = s1[i++];
	i = 0;
	while (s2[i])
		new[pos++] = s2[i++];
	new[pos] = '\0';
	return (new);
}
