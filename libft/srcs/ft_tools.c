/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 19:16:42 by maabou-h          #+#    #+#             */
/*   Updated: 2019/01/25 21:39:06 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_intlen(intmax_t nbr, int base)
{
	int	i;

	i = (nbr < 0) ? 2 : 1;
	nbr = (nbr < 0) ? -nbr : nbr;
	if (nbr == 0)
		return (0);
	while (nbr /= base)
		i++;
	return (i);
}

int		pf_rawlen(intmax_t nbr, int base)
{
	int	i;

	i = (nbr < 0) ? 2 : 1;
	nbr = (nbr < 0) ? -nbr : nbr;
	while (nbr /= base)
		i++;
	return (i);
}

int		pf_rawlenm(intmax_t nbr, int base)
{
	int	i;

	i = 1;
	nbr = (nbr < 0) ? -nbr : nbr;
	while (nbr /= base)
		i++;
	return (i);
}

int		pf_pflen(uintmax_t nbr, int base)
{
	int	i;

	i = 1;
	while (nbr /= base)
		i++;
	return (i);
}

int		pf_parser(char c)
{
	if (!c)
		return (-1);
	write(1, &c, 1);
	return (1);
}
