/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_x_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 18:32:33 by maabou-h          #+#    #+#             */
/*   Updated: 2019/01/27 01:27:52 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_parse_before_x(t_pf *raw, uintmax_t n, int base)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = (raw->fl & F_H && n > 0) ? 2 : 0;
	if (raw->fl & F_Z)
	{
		(raw->fl & F_H && n > 0) ? j += pf_parser('0') : 0;
		(raw->fl & F_H && n > 0) ? j += pf_parser('x') : 0;
		while (raw->fi-- > pf_pflen(n, base) + j)
			i += pf_parser('0');
	}
	else
	{
		while (raw->fi-- > pf_pflen(n, base) + k)
			i += pf_parser(' ');
		(raw->fl & F_H && n > 0) ? j += pf_parser('0') : 0;
		(raw->fl & F_H && n > 0) ? j += pf_parser('x') : 0;
	}
	j += pf_nbr_uns(n, base, raw, "0123456789abcdef");
	return (j + i);
}

int	pf_parse_between_x(t_pf *raw, uintmax_t n, int base)
{
	int i;
	int j;
	int k;
	int fl;

	i = 0;
	j = 0;
	fl = (raw->fl & F_H && n > 0) ? 2 : 0;
	k = (raw->pr > pf_pflen(n, base)) ? raw->fi - raw->pr : raw->fi -
		pf_pflen(n, base);
	(n == 0 && raw->pr == 0 && raw->fl & P_A) ? k += 1 : 0;
	(k < 0) ? k = 0 : 0;
	while (k-- > fl)
		j += pf_parser(' ');
	if (raw->fl & F_H && n > 0)
	{
		j += pf_parser('0');
		j += pf_parser('x');
	}
	while (raw->pr-- > pf_pflen(n, base))
		i += pf_parser('0');
	if (n == 0 && raw->pr == -1 && (raw->fl & P_A))
		return (j + i);
	j += pf_nbr_uns(n, base, raw, "0123456789abcdef");
	return (j + i);
}

int	pf_parse_after_x(t_pf *raw, uintmax_t n, int base)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (raw->fl & F_H && n > 0)
	{
		j += pf_parser('0');
		j += pf_parser('x');
	}
	if (raw->fl & P_A)
	{
		while (raw->pr-- > pf_pflen(n, base))
			j += pf_parser('0');
	}
	j += pf_nbr_uns(n, base, raw, "0123456789abcdef");
	while (raw->fi-- > j)
		i += pf_parser(' ');
	return (j + i);
}
