/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_p_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 18:32:33 by maabou-h          #+#    #+#             */
/*   Updated: 2019/01/24 19:12:31 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_parse_before_p(t_pf *raw, intmax_t n, int base)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = (raw->fl & P_A) ? 1 : 0;
	if (raw->fl & F_Z)
	{
		j += pf_parser('0');
		j += pf_parser('x');
		while (raw->fi-- > pf_rawlen(n, base) + j)
			i += pf_parser('0');
	}
	else
	{
		while (raw->fi-- > pf_rawlen(n, base) + k + 2 -
				(n == 0 && (raw->fl & P_A) && raw->pr == -1))
			i += pf_parser(' ');
		j += pf_parser('0');
		j += pf_parser('x');
	}
	j += pf_nbr_uns(n, base, raw, "0123456789abcdef");
	return (j + i);
}

int	pf_parse_between_p(t_pf *raw, intmax_t n, int base)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = (raw->pr > pf_intlen(n, base)) ? raw->fi - raw->pr : raw->fi -
		pf_intlen(n, base);
	if (k < 0)
		k = 0;
	while (k-- > 2)
		j += pf_parser(' ');
	j += pf_parser('0');
	j += pf_parser('x');
	while (raw->pr-- > pf_rawlen(n, base))
		i += pf_parser('0');
	j += pf_nbr_uns(n, base, raw, "0123456789abcdef");
	return (j + i);
}

int	pf_parse_after_p(t_pf *raw, long long n, int base)
{
	int i;
	int j;

	i = 0;
	j = 0;
	j += pf_parser('0');
	j += pf_parser('x');
	while (raw->pr-- > pf_rawlen(n, base))
		j += pf_parser('0');
	j += pf_nbr_uns(n, base, raw, "0123456789abcdef");
	while (raw->fi-- > j - (n == 0 && (raw->fl & P_A) && raw->pr == -1))
		i += pf_parser(' ');
	return (j + i);
}

int	pf_append_p(uintmax_t n, int base, t_pf *raw)
{
	int j;

	j = 0;
	if (raw->fl & F_M)
		j += pf_parse_after_p(raw, n, base);
	else if (!(raw->fl & P_A))
		j += pf_parse_before_p(raw, n, base);
	else
		j += pf_parse_between_p(raw, n, base);
	return (j);
}
