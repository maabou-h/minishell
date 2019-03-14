/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_csp_case.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 19:16:50 by maabou-h          #+#    #+#             */
/*   Updated: 2019/03/07 20:48:57 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	pf_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
	}
	return (i);
}

int		pf_putchar(unsigned char c, t_pf *raw)
{
	int		i;

	i = raw->fi;
	i = (i <= 0) ? 1 : i;
	if (raw->fl & F_M)
		write(1, &c, sizeof(c));
	if (raw->fl & F_Z)
	{
		while (raw->fi-- > 1)
			write(1, "0", 1);
	}
	else
	{
		while (raw->fi-- > 1)
			write(1, " ", 1);
	}
	if (!(raw->fl & F_M))
		write(1, &c, sizeof(c));
	return (i);
}

int		pf_putstr(char const *s, t_pf *raw)
{
	int		i;
	int		j;
	int		k;
	int		len;
	char	*x;

	x = (!s) ? "(null)" : NULL;
	len = (!s) ? 6 : (int)pf_strlen(s);
	j = 0;
	(!(raw->fl & P_A)) ? raw->pr = len : 0;
	(raw->pr > len) ? raw->pr = len : 0;
	i = ((raw->fl & P_A) && raw->pr > len) ? 0 : raw->fi - raw->pr;
	k = (raw->pr < len && (raw->fl & P_A)) ?
		raw->pr : len;
	if (raw->fl & F_M)
		(!s) ? write(1, x, k) : write(1, s, k);
	if (!(raw->fl & F_Z))
		while (i-- > 0)
			j += pf_parser(' ');
	else
		while (i-- > 0)
			j += pf_parser('0');
	if (!(raw->fl & F_M))
		(!s) ? write(1, x, k) : write(1, s, k);
	return (k + j);
}

int		pf_csp_case(t_pf *raw, va_list ap)
{
	int		i;

	i = 0;
	if (raw->id == 'c')
		return (pf_putchar((unsigned char)va_arg(ap, int), raw));
	else if (raw->id == '%')
		return (pf_putchar('%', raw));
	else if (raw->id == 's')
		return (pf_putstr(va_arg(ap, char*), raw));
	else if (raw->id == 'p')
		return (pf_append_p((uintmax_t)va_arg(ap, void*), 16, raw));
	return (-1);
}
