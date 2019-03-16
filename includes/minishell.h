/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 14:40:43 by maabou-h          #+#    #+#             */
/*   Updated: 2019/03/16 19:45:24 by maabou-h         ###   ########.fr       */
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
#include "get_next_line.h"
#include "libft.h"
#include "ft_printf.h"

char	*ft_dollarenv(char *eval, char **envp);
char	*ft_tildecheck(char *eval, int i);
char	*ft_getenv(char **envp, char *path);
void	msh_exec(char **ftav, char ***ftep);
int		msh_builtin(char **ftav, char ***ftep);
char	*msh_path(char *exec, char **ftep);
int		msh_valid_path(char *exec, char *folder);
int		msh_echo(char **ftav);
char	*msh_rm_quotes(char *ftav);
int		msh_help(char **ftav, char ***ftep);
int		msh_exit(char **ftav, char ***ftep);
int		msh_cd(char **ftav, char ***ftep);
int		msh_unsetenv(char *arg, char ***ftep);
int		msh_setenv(char *arg, char ***ftep);
int		msh_env(char **ftav, char ***ftep);
void	msh_prompt(char **envp);
char	**msh_fill_env(char **environ, int i);
void	msh_create_env(char ***ftep);
char	**msh_exp(char **input, char ***ftep);
int		msh_bad_arg(char *arg);

#endif
