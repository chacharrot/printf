/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scha <scha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 22:38:01 by scha              #+#    #+#             */
/*   Updated: 2021/03/15 22:39:58 by scha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_fmtdata
{
	int		width;
	int		pre;
	int		zero;
	int		minus;
	int		rev;
	int		int_minus;
}				t_fmtdata;

int				ft_printf(char *format, ...);
void			format_start(char *format, va_list ap, t_fmtdata *data);
int				format_check(char *format, va_list ap, t_fmtdata *data);
int				do_print(char *format, va_list ap, t_fmtdata *data);
int				ft_putchar(char c, t_fmtdata *data);
void			ft_putwidth(t_fmtdata *data, int size);
void			ft_putwidth_d(t_fmtdata *data, int size);
void			ft_putwidth_p(t_fmtdata *data, int str_len);
void			ft_putwidth_cper(t_fmtdata *data, int size);
void			data_set(t_fmtdata *data);
int				ft_f(char format);
void			ft_putstr(char *str, t_fmtdata *data, int str_len);
void			ft_putstr_d(char *str, t_fmtdata *data, int str_len);
void			ft_putstr_p(char *str, t_fmtdata *data, int str_len);
int				ft_strlen(char *str);
char			*ft_itoa(int num, t_fmtdata *data);
char			*ft_itoa_u(size_t num, t_fmtdata *data);
char			*ft_itoa_hex(size_t num, char format, t_fmtdata *data);
char			*ft_itoa_p(unsigned long long num, t_fmtdata *data);
void			do_u(va_list ap, t_fmtdata *data);
void			do_x(va_list ap, t_fmtdata *data);
void			do_bigx(va_list ap, t_fmtdata *data);
void			do_p(va_list ap, t_fmtdata *data);
int				do_s(va_list ap, t_fmtdata *data);
void			do_d(va_list ap, t_fmtdata *data);
void			do_c(va_list ap, t_fmtdata *data);
void			do_percent(t_fmtdata *data);
int				digitnumber_p(unsigned long long n);
int				digitnumber_hex(size_t n);
int				digitnumber_u(size_t n);
int				digitnumber(int n);

#endif
