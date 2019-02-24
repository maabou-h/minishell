/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 14:40:43 by maabou-h          #+#    #+#             */
/*   Updated: 2019/02/24 16:59:46 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

typedef struct s_env
{
    char        *id;
    char        *val;
}               t_env;

int get_next_line(const int fd, char **line);
size_t ft_strcmp(char *s1, char *s2);
size_t ft_strncmp(char *s1, char *s2, size_t n);
void ft_putstr(char const *s);

#endif
