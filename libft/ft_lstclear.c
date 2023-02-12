/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 22:55:47 by bbouagou          #+#    #+#             */
/*   Updated: 2022/10/14 00:09:41 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*tmp;

	if (lst == NULL || del == NULL)
		return ;
	if (*lst != NULL)
	{
		current = *lst;
		while (current != NULL)
		{
			tmp = current;
			current = current->next;
			del(tmp->content);
			free(tmp);
		}
		*lst = NULL;
	}
}
