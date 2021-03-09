#include "ft_printf.h"

char	*ft_itoa(int num, fmtdata *data)
{
	char			*str;
	int				i;
	unsigned int	nbr;

	i = digitnumber(num);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	if (num < 0)
	{
		nbr = (unsigned int)(num * -1);
		data->int_minus = 1;
	}
	else
		nbr = num;
	while (i--)
	{
		str[i] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	return (str);
}

char	*ft_itoa_u(size_t num)
{
	char			*str;
	int				i;
	unsigned int	nbr;

	i = digitnumber_u(num);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	else
		nbr = num;
	while (i--)
	{
		str[i] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	return (str);
}

char	*ft_itoa_xX(size_t num, char format)
{
	char			*base;
	char			*str;
	int				i;
	unsigned int	nbr;

	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	i = digitnumber_xX(num);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	else
		nbr = num;
	while (i--)
	{
		str[i] = base[nbr % 16];
		nbr = nbr / 16;
	}
	return (str);
}

char	*ft_itoa_p(unsigned long long num, char format)
{
	char			*base;
	char			*str;
	int				i;
	unsigned int	nbr;

	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	i = digitnumber_p(num);
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	else
		nbr = num;
	while (i--)
	{
		str[i] = base[nbr % 16];
		nbr = nbr / 16;
	}
	return (str);
}