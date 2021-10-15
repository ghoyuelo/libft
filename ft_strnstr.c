/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 13:38:35 by ghoyuelo          #+#    #+#             */
/*   Updated: 2021/09/13 15:07:53 by ghoyuelo         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	i;
	size_t	j;

	if (n[0] == '\0')
		return ((char *)h);
	i = 0;
	while (h[i] != '\0' && i < len)
	{
		j = 0;
		while (n[j] != '\0' && h[i + j] != '\0'
			&& i + j < len && n[j] == h[i + j])
		{
			if (n[j + 1] == '\0')
			{
				return ((char *)&h[i]);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
