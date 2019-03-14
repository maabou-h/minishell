/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_di_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 18:32:33 by maabou-h          #+#    #+#             */
/*   Updated: 2019/01/27 00:25:48 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_plusspace(t_pf *raw, long long n)
{
	int j;

	j = 0;
	(n < 0) ? j += pf_parser('-') : 0;
	(raw->fl & F_P && n >= 0) ? j += pf_parser('+') : 0;
	(raw->fl & F_S && n >= 0 && !(raw->fl & F_P)) ? j += pf_parser(' ') : 0;
	return (j);
}

int	pf_parse_before(t_pf *raw, long long n, int base)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = ((raw->fl & F_S || raw->fl & F_P) && n >= 0) ? 1 : 0;
	if (raw->fl & F_Z)
	{
		j += pf_plusspace(raw, n);
		(n < 0) ? n = -n : 0;
		while (raw->fi-- > pf_rawlen(n, base) + j)
			i += pf_parser('0');
	}
	else
	{
		while (raw->fi-- > pf_rawlen(n, base) + k)
			i += pf_parser(' ');
		j += pf_plusspace(raw, n);
		(n < 0) ? n = -n : 0;
	}
	j += pf_nbr_upp(n, base, raw, "0123456789");
	return (j + i);
}

int	pf_parse_between(t_pf *raw, long long n, int base)
{
	int i;
	int j;
	int len;
	int k;
	int z;

	i = 0;
	j = 0;
	k = (((raw->fl & F_P) && n >= 0) ||
			((raw->fl & F_S) && n >= 0) || (n < 0)) ? 1 : 0;
	len = pf_rawlenm(n, base) - (n == 0 && (raw->fl & P_A) && raw->pr == 0);
	z = (raw->pr > len) ? raw->pr : len;
	while (z++ < raw->fi - k)
		j += pf_parser(' ');
	j += pf_plusspace(raw, n);
	(n < 0) ? n = -n : 0;
	while (raw->pr-- > pf_rawlen(n, base))
		i += pf_parser('0');
	if (n == 0 && (raw->fl & P_A) && raw->pr == -1)
		return (j + i);
	j += pf_nbr_upp(n, base, raw, "0123456789");
	return (j + i);
}

int	pf_parse_after(t_pf *raw, long long n, int base)
{
	int i;
	int j;

	i = 0;
	j = 0;
	(n < 0) ? j += pf_parser('-') : 0;
	(raw->fl & F_P && n >= 0) ? j += pf_parser('+') : 0;
	(raw->fl & F_S && n >= 0 && !(raw->fl & F_P)) ? j += pf_parser(' ') : 0;
	(n < 0) ? n = -n : 0;
	while (raw->pr-- > pf_rawlen(n, base))
		j += pf_parser('0');
	j += pf_nbr_upp(n, base, raw, "0123456789");
	while (raw->fi-- > j)
		i += pf_parser(' ');
	return (j + i);
}
