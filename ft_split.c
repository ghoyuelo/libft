/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 12:38:40 by ghoyuelo          #+#    #+#             */
/*   Updated: 2021/09/20 16:26:37 by ghoyuelo         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_tab_size(char const *str, char c)
{
	int	i;
	int	tab;

	i = 0;
	tab = 0;
	if (*str == '\0')
		return (0);
	while (*str != '\0')
	{
		if (*str == c)
			tab = 0;
		else if (tab == 0)
		{
			tab = 1;
			i++;
		}
		str++;
	}
	return (i);
}

static int	ft_wordnum(char const *word, char c, int i)
{
	int	len;

	len = 0;
	while (word[i] != c && word[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

static char	**free_mem(char const **dest, int i)
{
	while (i > 0)
	{
		i--;
		free((void *)dest[i]);
	}
	free(dest);
	return (NULL);
}

static char	**arr_cpy(char const *s, char **dest, char c, int tab)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i] != '\0' && j < tab)
	{
		k = 0;
		while (s[i] == c)
			i++;
		dest[j] = (char *)malloc(sizeof(char) * ft_wordnum(s, c, i) + 1);
		if (dest[j] == NULL)
			return (free_mem((char const **)dest, j));
		while (s[i] != '\0' && s[i] != c)
			dest[j][k++] = s[i++];
		dest[j][k] = '\0';
		j++;
	}
	dest[j] = 0;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	int		num;

	if (s == NULL)
		return (NULL);
	num = get_tab_size(s, c);
	dst = (char **)malloc(sizeof(char *) * (num + 1));
	if (dst == NULL)
		return (NULL);
	return (arr_cpy(s, dst, c, num));
}
