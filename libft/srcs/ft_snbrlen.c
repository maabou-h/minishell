/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snbrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 13:50:14 by maabou-h          #+#    #+#             */
/*   Updated: 2019/02/21 14:13:35 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_snbrlen(intmax_t n)
{
	int intlen;

	intlen = 1;
	n = (n < 0) ? -n : n;
	intlen = (n < 0) ? intlen + 1 : intlen;
	while (n /= 10 > 9)
		intlen++;
	return (intlen);
}
