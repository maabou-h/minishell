/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snbrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 13:50:14 by maabou-h          #+#    #+#             */
/*   Updated: 2019/03/15 15:39:58 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_snbrlen(intmax_t n)
{
	int intlen;

	intlen = 1;
	intlen = (n < 0) ? intlen + 1 : intlen;
	n = (n < 0) ? -n : n;
	while (n / 10)
	{
		n /= 10;
		intlen++;
	}
	return (intlen);
}
