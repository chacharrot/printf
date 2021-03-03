/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scha <scha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 17:18:21 by scha              #+#    #+#             */
/*   Updated: 2021/01/04 17:18:21 by scha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     digitnumber(int n)
{
    int i;

    i = 0;
    if(n < 0)
        i = 1;
    while(n)
    {    
        n = n/10;
        i++;
    }
    return(i);
}

char    *ft_itoa(int n)
{
    char    *str;
    int     i;

    i = digitnumber(n);
    str = (char *)malloc(sizeof(char) * (i + 1));
    if(!str)
        return(NULL);
    if(n < 0)
    {
        n = n * -1;
        *str = 45;
        i++;
    }
    str[i] ='\0';
    while(i)
    {
        str[--i] = n % 10 + '0';
        n = n/10;
    }
    return(str);
}