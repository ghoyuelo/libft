/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:53:17 by ghoyuelo          #+#    #+#             */
/*   Updated: 2021/09/20 16:23:38 by ghoyuelo         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	num_count(long n, size_t len)
{
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	len++;
	return (len);
}

char	*ft_strrev(char *str, size_t len, long sz, size_t minus)
{
	str[len + minus] = '\0';
	while (len)
	{
		len--;
		str[len + minus] = sz % 10 + '0';
		sz = sz / 10;
	}
	if (minus == 1)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*number;
	long	nbr;
	size_t	len;
	size_t	minus;

	len = 0;
	minus = 0;
	nbr = (long)n;
	if (nbr < 0)
	{
		minus = 1;
		nbr *= -1;
	}
	len = num_count(nbr, len);
	number = malloc((len + 1 + minus) * sizeof(char));
	if (!number)
		return (0);
	return (ft_strrev(number, len, nbr, minus));
}
