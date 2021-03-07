#include "ft_printf.h"

static int		digitnumber(int n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static int		digitnumber_u(size_t n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static int		digitnumber_xX(size_t n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

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

	if (format = 'x')
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