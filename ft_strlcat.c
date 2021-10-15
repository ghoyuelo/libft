/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 13:48:33 by ghoyuelo          #+#    #+#             */
/*   Updated: 2021/09/08 14:31:26 by ghoyuelo         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (dstsize > dst_len && dstsize > 0)
	{
		i = src_len + dst_len;
		dstsize = dstsize - dst_len - 1;
		src_len = 0;
		while (src[src_len] != 0 && dstsize != 0)
		{
			dst[dst_len++] = src[src_len++];
			dstsize--;
		}
		dst[dst_len] = '\0';
	}
	else
		i = dstsize + src_len;
	return (i);
}
