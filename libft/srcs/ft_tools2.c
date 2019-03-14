/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 13:27:39 by maabou-h          #+#    #+#             */
/*   Updated: 2019/01/24 19:13:57 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_atoi(const char *str)
{
	int		i;
	long	ret;

	i = 0;
	ret = 0;
	if (str)
	{
		while ((str[i] >= 7 && str[i] <= 13) || str[i] == ' ')
			i++;
		while (str[i] <= '9' && str[i] >= '0')
		{
			ret *= 10;
			ret += str[i++] - '0';
		}
	}
	return (ret);
}

int	pf_nbr_upp(intmax_t n, int base, t_pf *raw, char *radix)
{
	uintmax_t	nbr;

	nbr = (n < 0) ? -n : n;
	if (nbr >= (uintmax_t)base)
	{
		pf_nbr_upp(nbr / base, base, raw, radix);
		pf_nbr_upp(nbr % base, base, raw, radix);
	}
	else
		write(1, &radix[nbr], 1);
	return (pf_pflen(nbr, base));
}

int	pf_nbr_uns(uintmax_t n, int base, t_pf *raw, char *radix)
{
	if (raw->id == 'p' && n == 0 && (raw->fl & P_A) && raw->pr == -1)
		return (0);
	else if (n >= (uintmax_t)base)
	{
		pf_nbr_uns(n / base, base, raw, radix);
		pf_nbr_uns(n % base, base, raw, radix);
	}
	else
		write(1, &radix[n], 1);
	return (pf_pflen(n, base));
}
