/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_u_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 18:32:33 by maabou-h          #+#    #+#             */
/*   Updated: 2019/01/27 00:57:01 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_parse_before_u(t_pf *raw, uintmax_t n, int base)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (raw->fl & F_Z)
	{
		while (raw->fi-- > pf_pflen(n, base) + j)
			i += pf_parser('0');
	}
	else
	{
		while (raw->fi-- > pf_pflen(n, base))
			i += pf_parser(' ');
	}
	j += pf_nbr_uns(n, base, raw, "0123456789");
	return (j + i);
}

int	pf_parse_between_u(t_pf *raw, uintmax_t n, int base)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = (raw->pr > pf_pflen(n, base)) ? raw->fi - raw->pr : raw->fi
		- pf_rawlen(n, base);
	if (k < 0)
		k = 0;
	while (k--)
		j += pf_parser(' ');
	while (raw->pr-- > pf_pflen(n, base))
		i += pf_parser('0');
	if (n == 0 && raw->pr == -1 && (raw->fl & P_A))
		return (j + i);
	j += pf_nbr_uns(n, base, raw, "0123456789");
	return (j + i);
}

int	pf_parse_after_u(t_pf *raw, uintmax_t n, int base)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (raw->fl & P_A)
	{
		while (raw->pr-- > pf_pflen(n, base))
			j += pf_parser('0');
	}
	j += pf_nbr_uns(n, base, raw, "0123456789");
	while (raw->fi-- > j)
		i += pf_parser(' ');
	return (j + i);
}
