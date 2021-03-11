#include "ft_printf.h"

void	ft_putstr_d(char *str, fmtdata *data, int str_len)
{
	int	i;

	if (data->int_minus)
		ft_putchar('-', data);
	if (data->pre == -1 && data->zero && data->int_minus)
		ft_putwidth_d(data, str_len);
	i = data->pre;
	if (data->pre > (int)str_len)
		while (i-- - (int)str_len > 0)
			ft_putchar('0', data);
	write(1, str, str_len);
	data->rev += str_len;
}

void	ft_putstr_p(char *str, fmtdata *data, int str_len)
{
	int		i;

	write(1, "0x", 2);
	data->rev += 2;
	if (data->pre == -1 && data->zero)
		ft_putwidth_p(data);
	i = data->pre;
	if (data->pre > str_len + 2)
		while (i-- > str_len + 2)
			ft_putchar('0', data);
	write(1, str, str_len);
	data->rev += str_len;
}

void	ft_putstr(char *str, fmtdata *data, int str_len)
{
	if (str == NULL)
		return ;
	if (data->pre < str_len)
		str_len = data->pre;
	if (data->pre > str_len)
		data->pre = str_len;
	write(1, str, str_len);
	data->rev += str_len;
}

