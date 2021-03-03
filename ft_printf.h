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
}				fmtdata;

int		ft_printf(char *format, ...);
void	format_start(char *format, va_list ap, fmtdata data);
int		format_check(char *format, va_list ap, fmtdata data);
int		do_print(char *format, va_list ap, fmtdata data);
void	do_c(va_list ap, fmtdata data);
int		ft_putchar(char c, fmtdata data);
void	ft_putwidth(fmtdata data, size_t size);
int		precision_check(char *format, va_list ap, fmtdata data);
void	data_set(fmtdata data);
int		ft_f(char format);


# endif