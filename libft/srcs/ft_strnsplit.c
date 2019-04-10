/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnsplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 10:38:01 by maabou-h          #+#    #+#             */
/*   Updated: 2019/03/23 20:26:12 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	**ft_strnsplit(char const *s, size_t len, size_t lentwo)
{
	int		i;
	int		j;
	char	**arr;

	i = 0;
	j = 0;
	if (!s || len == 0 || lentwo == 0)
		return (NULL);
	if (!(arr = (char**)malloc(sizeof(char*) * (len + 1))))
		return (NULL);
	while (len--)
	{
		if (!(arr[j] = ft_strsub(s, i, lentwo)))
			return (ft_free_arr(arr) ? NULL : NULL);
		j++;
		i += lentwo;
	}
	arr[j] = NULL;
	return (arr);
}
