/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 14:30:04 by maabou-h          #+#    #+#             */
/*   Updated: 2019/03/10 01:00:49 by sdincbud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_free_arr(char **arr)
{
	int x;

	x = 0;
	while (arr[x])
	{
		ft_strdel(&arr[x]);
		x++;
	}
	free(arr[x]);
	free(arr);
	return (0);
}
