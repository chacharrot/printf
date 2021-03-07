#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct	fmtdata_s
{
	int		width;
	int		precision;
	int		zero;
	int		minus;
	int		rev;
	int		int_minus;
}				fmtdata;

int		ft_printf(char *format, ...);
void	format_start(char *format, va_list ap, fmtdata *data);
int		format_check(char *format, va_list ap, fmtdata *data);
int		do_print(char *format, va_list ap, fmtdata *data);
void	do_c(va_list ap, fmtdata *data);
int		ft_putchar(char c, fmtdata *data);
void	ft_putwidth(fmtdata *data, size_t size);
void	ft_putwidth_d(fmtdata *data, size_t size);
int		precision_check(char *format, va_list ap, fmtdata *data);
void	data_set(fmtdata *data);
int		ft_f(char format);
void	ft_putstr(char *str, fmtdata *data, size_t str_len);
void	ft_putstr_d(char *str, fmtdata *data, size_t str_len);
size_t	ft_strlen(char *str);
int		do_s(va_list ap, fmtdata *data);
void	do_d(va_list ap, fmtdata *data);
int		digitnumber(int n);
char	*ft_itoa(int num, fmtdata *data);
char	*ft_itoa_u(size_t num);
int		digitnumber_u(size_t n);
void	do_u(va_list ap, fmtdata *data);
char	*ft_itoa_xX(size_t num, char format);
void	do_x(va_list ap, fmtdata *data);

# endif
