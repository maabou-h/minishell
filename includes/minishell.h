/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 14:40:43 by maabou-h          #+#    #+#             */
/*   Updated: 2019/03/14 18:58:19 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <sys/stat.h>
#include <pwd.h>
#include <dirent.h>
#include "../libft/includes/get_next_line.h"
#include "../libft/includes/libft.h"
#include "../libft/includes/ft_printf.h"

int get_next_line(const int fd, char **line);
char	*ft_getenv(char **envp, char *path);
char *ft_dollarenv(char *eval, char **envp);
int		msh_exit(char **ftav, char **ftep);
int		msh_env(char **ftav, char **ftep);
int		msh_unsetenv(char *args, char **ftep);
int	    msh_setenv(char *arg, char **ftep);
int		msh_cd(char **ftav, char **ftep);
int		msh_help(char **ftav, char **ftep);
int		msh_echo(char **ftav);
char	*msh_rm_quotes(char *ftav);

#endif
