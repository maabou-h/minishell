/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 00:13:16 by maabou-h          #+#    #+#             */
/*   Updated: 2018/11/12 15:00:52 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strtrim(char const *s)
{
	size_t	st;
	size_t	end;

	if (!s)
		return (NULL);
	st = 0;
	end = ft_strlen(s) - 1;
	while (st <= end && (s[st] == ' ' || s[st] == '\n' || s[st] == '\t'))
		st++;
	if (st == end)
		return (NULL);
	while (end > st && (s[end] == ' ' || s[end] == '\n' || s[end] == '\t'))
		end--;
	return (ft_strndup(s + st, end - st + 1));
}
