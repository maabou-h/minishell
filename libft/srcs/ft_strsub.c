/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 22:03:45 by maabou-h          #+#    #+#             */
/*   Updated: 2018/11/10 13:25:12 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ns;
	int		i;

	if (!s)
		return (0);
	if (!(ns = (char*)ft_memalloc(len + 1)))
		return (NULL);
	i = 0;
	while (len--)
		ns[i++] = s[start++];
	return (ns);
}
