#include "ft_printf.h"

int		digitnumber(int n)
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

char	*ft_itoa(int num, fmtdata *data)
{
	char			*str;
	int				i;
	unsigned int	nbr;

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
	i = digitnumber(num);
	while (i--)
	{
		str[i] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	return (str);
}
