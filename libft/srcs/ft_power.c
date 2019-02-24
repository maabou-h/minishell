/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 19:01:13 by maabou-h          #+#    #+#             */
/*   Updated: 2018/11/17 19:02:08 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_power(int nb, int power)
{
	if (power == 0 || (nb == 1 && power > 0))
		return (1);
	if (power > 0 && nb != 0)
		return (nb * ft_power(nb, (power - 1)));
	return (0);
}
