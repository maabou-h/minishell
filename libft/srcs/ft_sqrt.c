/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 19:01:35 by maabou-h          #+#    #+#             */
/*   Updated: 2018/11/17 19:01:47 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_sqrt(int nb)
{
	int square;

	square = 0;
	while (square < nb / 2)
	{
		if ((square * square) == nb)
			return (square);
		square++;
	}
	return (0);
}
