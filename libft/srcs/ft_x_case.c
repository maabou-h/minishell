/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_x_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 15:53:31 by maabou-h          #+#    #+#             */
/*   Updated: 2019/01/24 13:31:19 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_append_x(uintmax_t n, int base, t_pf *raw)
{
	int j;

	j = 0;
	if (raw->fl & F_M)
		j += pf_parse_after_x(raw, n, base);
	else if (!(raw->fl & P_A))
		j += pf_parse_before_x(raw, n, base);
	else
		j += pf_parse_between_x(raw, n, base);
	return (j);
}

int	pf_x_case(t_pf *raw, va_list ap)
{
	if (raw->id == 'x' && !raw->mod)
		return (pf_append_x((unsigned int)va_arg(ap, uintmax_t), 16, raw));
	else if (raw->id == 'x' && raw->mod & L_)
		return (pf_append_x((unsigned long)va_arg(ap, uintmax_t), 16, raw));
	else if (raw->id == 'x' && raw->mod & H_)
		return (pf_append_x((unsigned short)va_arg(ap, uintmax_t), 16, raw));
	else if (raw->id == 'x' && raw->mod & LL_)
		return (pf_append_x(va_arg(ap, uintmax_t), 16, raw));
	else if (raw->id == 'x' && raw->mod & HH_)
		return (pf_append_x((unsigned char)va_arg(ap, uintmax_t), 16, raw));
	else if (raw->id == 'x' && raw->mod & J_)
		return (pf_append_x(va_arg(ap, uintmax_t), 16, raw));
	else if (raw->id == 'x' && raw->mod & Z_)
		return (pf_append_x((size_t)va_arg(ap, uintmax_t), 16, raw));
	else
		return (-1);
}
