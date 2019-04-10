/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 14:40:43 by maabou-h          #+#    #+#             */
/*   Updated: 2019/03/24 15:06:23 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/stat.h>
# include <pwd.h>
# include <dirent.h>
# include "get_next_line.h"
# include "libft.h"
# include "ft_printf.h"

/*
**		main file
*/

void	msh_check_path(char ***ftep);
char	*msh_path(char *ex, char **ftep, int i);
char	*msh_joinpath(char *path, char *file);
void	msh_promptbase(char *usr, char *dir);

/*
**		msh builtins
*/

int		msh_cd(char **ftav, char ***ftep);
int		msh_echo(char **ftav);
int		msh_help(void);

/*
**		msh cd
*/

void	msh_cdenv(char ***ftep);
void	msh_noargcd(char ***ftep);
void	msh_elsecd(char ***ftep, char *av);
void	msh_homecd(char ***ftep, char *av);
void	msh_oldpwdcd(char ***ftep);

/*
**		msh env
*/

void	msh_setenv(char *arg, char ***ftep);
void	msh_unsetenv(char *arg, char ***ftep);
void	msh_env(char **ftav, char ***ftep);

/*
**		msh env check
*/

int		msh_bad_arg(char *arg);
char	*ft_dollarenv(char *eval, char **envp);
char	*ft_tildecheck(char *eval, int i, int j);
char	*msh_tildehome(void);
char	*ft_getenv(char **envp, char *path);

/*
**		msh loop and exec
*/

void	msh_loop(char **ftav, char ***ftep);
void	msh_exec(char **ftav, char ***ftep);
char	**msh_av(char *path, char **ftav);
int		msh_builtin(char **ftav, char ***ftep, int ret);
int		msh_valid_path(char *exec, char flag);

/*
**		msh utils
*/

void	msh_prompt(char **envp);
char	**msh_fill_env(char **environ, int i);
char	*msh_shlvl(char *environ);
void	msh_create_env(char ***ftep);
char	**msh_exp(char **input, char ***ftep);

#endif
