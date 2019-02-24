/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 15:32:05 by maabou-h          #+#    #+#             */
/*   Updated: 2019/02/21 14:14:43 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_itoa(int n)
{
	char	*itoa;
	long	nbr;
	int		end;

	if (!(itoa = ft_strnew((size_t)ft_snbrlen(n))))
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
	while (nbr /= 10)
		itoa[end--] = nbr % 10 + '0';
	return (itoa);
}
