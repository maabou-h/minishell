/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 14:40:43 by maabou-h          #+#    #+#             */
/*   Updated: 2019/02/24 21:50:52 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <sys/stat.h>

typedef struct s_env
{
    char        *id;
    char        *val;
}               t_env;

int get_next_line(const int fd, char **line);
size_t ft_strcmp(char *s1, char *s2);
size_t ft_strncmp(char *s1, char *s2, size_t n);
void ft_putstr(char const *s);
char *ft_strjoin(char *s1, char *s2);
char **ft_strsplit(char *str, char c);
char **ft_splitwhitespaces(char *str);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
void				ft_putendl(char const *s);
size_t				ft_strlen(const char *s);

#endif
