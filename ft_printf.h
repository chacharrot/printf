#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

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
int		ft_putchar(char c, fmtdata *data);
void	ft_putwidth(fmtdata *data, int size);
void	ft_putwidth_d(fmtdata *data, int size);
void	ft_putwidth_p(fmtdata *data);
void	data_set(fmtdata *data);
int		ft_f(char format);
void	ft_putstr(char *str, fmtdata *data, int str_len);
void	ft_putstr_d(char *str, fmtdata *data, int str_len);
void	ft_putstr_p(char *str, fmtdata *data, int str_len);
int		ft_strlen(char *str);
char	*ft_itoa(int num, fmtdata *data);
char	*ft_itoa_u(size_t num);
char	*ft_itoa_xX(size_t num, char format);
char	*ft_itoa_p(unsigned long long num, char format);
void	do_u(va_list ap, fmtdata *data);
void	do_x(va_list ap, fmtdata *data);
void	do_p(va_list ap, fmtdata *data);
int		do_s(va_list ap, fmtdata *data);
void	do_d(va_list ap, fmtdata *data);
void	do_c(va_list ap, fmtdata *data);
int		digitnumber_p(unsigned long long n);
int		digitnumber_xX(size_t n);
int		digitnumber_u(size_t n);
int		digitnumber(int n);

# endif
