/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_u_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 15:53:31 by maabou-h          #+#    #+#             */
/*   Updated: 2019/01/24 13:29:06 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_append_u(uintmax_t n, int base, t_pf *raw)
{
	int j;

	j = 0;
	if (raw->fl & F_M)
		j += pf_parse_after_u(raw, n, base);
	else if (!(raw->fl & P_A))
		j += pf_parse_before_u(raw, n, base);
	else
		j += pf_parse_between_u(raw, n, base);
	return (j);
}

int	pf_u_case(t_pf *raw, va_list ap)
{
	if (raw->id == 'u' && !raw->mod)
		return (pf_append_u((unsigned int)va_arg(ap, uintmax_t), 10, raw));
	else if (raw->id == 'u' && raw->mod & L_)
		return (pf_append_u((unsigned long)va_arg(ap, uintmax_t), 10, raw));
	else if (raw->id == 'u' && raw->mod & H_)
		return (pf_append_u((unsigned short)va_arg(ap, uintmax_t), 10, raw));
	else if (raw->id == 'u' && raw->mod & LL_)
		return (pf_append_u(va_arg(ap, uintmax_t), 10, raw));
	else if (raw->id == 'u' && raw->mod & HH_)
		return (pf_append_u((unsigned char)va_arg(ap, uintmax_t), 10, raw));
	else if (raw->id == 'u' && raw->mod & J_)
		return (pf_append_u(va_arg(ap, uintmax_t), 10, raw));
	else if (raw->id == 'u' && raw->mod & Z_)
		return (pf_append_u((size_t)va_arg(ap, uintmax_t), 10, raw));
	else
		return (-1);
}
