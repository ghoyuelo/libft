/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 14:19:17 by ghoyuelo          #+#    #+#             */
/*   Updated: 2021/09/17 15:12:09 by ghoyuelo         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s, char const *set)
{
	int	i;

	if (!s || !set)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && ft_strchr(set, *s))
		s++;
	i = ft_strlen(s);
	while (i > 0 && ft_strchr(set, s[i]))
		i--;
	return (ft_substr(s, 0, i + 1));
}
