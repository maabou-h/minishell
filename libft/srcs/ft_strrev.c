/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 21:28:43 by maabou-h          #+#    #+#             */
/*   Updated: 2018/11/12 21:34:04 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrev(char *str)
{
	int		a;
	int		b;
	char	tmp;

	a = 0;
	b = 0;
	if (!str)
		return (NULL);
	while (str[b] != '\0')
		b++;
	b -= 1;
	while (b >= a)
	{
		tmp = str[b];
		str[b] = str[a];
		str[a] = tmp;
		a++;
		b--;
	}
	return (str);
}
