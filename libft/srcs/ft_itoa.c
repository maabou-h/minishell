/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 15:32:05 by maabou-h          #+#    #+#             */
/*   Updated: 2019/03/15 15:41:05 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_itoa(int n)
{
	char	*itoa;
	long	nbr;
	int		end;

	if (!(itoa = (char*)malloc(sizeof(char) * (ft_snbrlen(n) + 1))))
		return (NULL);
	nbr = n;
	end = ft_snbrlen(n);
	itoa[end--] = '\0';
	if (n < 0)
	{
		nbr = -nbr;
		itoa[0] = '-';
	}
	if (n == 0)
		*itoa = '0';
	while (nbr)
	{
		itoa[end--] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (itoa);
}
