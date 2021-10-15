/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:01:54 by ghoyuelo          #+#    #+#             */
/*   Updated: 2021/10/13 14:10:15 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	tmp = *lst;
	if (!lst || !del)
		return ;
	else if (lst && del)
	{
		while (tmp != NULL)
		{
			tmp = tmp->next;
			del((*lst)->content);
			free(*lst);
			*lst = tmp;
		}
		lst = NULL;
	}
}
