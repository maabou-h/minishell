/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 14:53:43 by maabou-h          #+#    #+#             */
/*   Updated: 2019/03/07 20:58:16 by maabou-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <wchar.h>
# include <unistd.h>
# include <float.h>
# include <stdlib.h>
# include <stdarg.h>

# define F_H 2
# define F_Z 4
# define F_M 8
# define F_P 16
# define F_S 32
# define P_A 64

# define L_ 2
# define H_ 4
# define LL_ 8
# define HH_ 16
# define J_ 32
# define Z_ 64

typedef struct	s_pf
{
	int			fl;
	int			fi;
	int			pr;
	int			mod;
	char		id;
}				t_pf;

int				pf_rawlenm(intmax_t nbr, int base);
size_t			pf_strlen(const char *s);
int				pf_putchar(unsigned char c, t_pf *raw);
int				pf_putstr(char const *s, t_pf *raw);
int				pf_csp_case(t_pf *raw, va_list ap);
int				pf_append_di(long long int n, int base, t_pf *raw);
int				pf_di_case(t_pf *raw, va_list ap);
int				pf_free_pf(t_pf *tmp);
int				pf_plusspace(t_pf *raw, long long n);
int				pf_parse_before(t_pf *raw, long long n, int base);
int				pf_parse_between(t_pf *raw, long long n, int base);
int				pf_parse_after(t_pf *raw, long long n, int base);
size_t			pf_is_prefix(char c);
size_t			pf_is_spec(char c);
size_t			pf_interpretable(char const *format, int pos);
int				pf_prefix(char spec);
int				pf_modif(char c, char d, char e, int *i);
int				pf_append_o(uintmax_t n, int base, t_pf *raw);
int				pf_o_case(t_pf *raw, va_list ap);
int				pf_parse_before_o(t_pf *raw, uintmax_t n, int base);
int				pf_parse_between_o(t_pf *raw, uintmax_t n, int base);
int				pf_parse_after_o(t_pf *raw, uintmax_t n, int base);
int				pf_parse_before_p(t_pf *raw, intmax_t n, int base);
int				pf_parse_between_p(t_pf *raw, intmax_t n, int base);
int				pf_parse_after_p(t_pf *raw, long long n, int base);
int				pf_append_p(uintmax_t n, int base, t_pf *raw);
void			pf_initialize_fmt(t_pf *raw);
t_pf			pf_get_struct_info(const char *format, int i, t_pf *raw);
int				pf_printf_wrapper(t_pf *raw, va_list ap);
int				ft_printf(const char *format, ...);
int				pf_intlen(intmax_t nbr, int base);
int				pf_rawlen(intmax_t nbr, int base);
int				pf_pflen(uintmax_t nbr, int base);
int				pf_parser(char c);
int				pf_atoi(const char *str);
int				pf_nbr_upp(intmax_t n, int base, t_pf *raw, char *radix);
int				pf_nbr_uns(uintmax_t n, int base, t_pf *raw, char *radix);
int				pf_append_u(uintmax_t n, int base, t_pf *raw);
int				pf_u_case(t_pf *raw, va_list ap);
int				pf_parse_before_u(t_pf *raw, uintmax_t n, int base);
int				pf_parse_between_u(t_pf *raw, uintmax_t n, int base);
int				pf_parse_after_u(t_pf *raw, uintmax_t n, int base);
int				pf_append_x(uintmax_t n, int base, t_pf *raw);
int				pf_x_case(t_pf *raw, va_list ap);
int				pf_parse_before_x(t_pf *raw, uintmax_t n, int base);
int				pf_parse_between_x(t_pf *raw, uintmax_t n, int base);
int				pf_parse_after_x(t_pf *raw, uintmax_t n, int base);
int				pf_append_xu(uintmax_t n, int base, t_pf *raw);
int				pf_xu_case(t_pf *raw, va_list ap);
int				pf_parse_before_xu(t_pf *raw, uintmax_t n, int base);
int				pf_parse_between_xu(t_pf *raw, uintmax_t n, int base);
int				pf_parse_after_xu(t_pf *raw, uintmax_t n, int base);

#endif
