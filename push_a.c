/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 09:53:19 by bbouagou          #+#    #+#             */
/*   Updated: 2023/02/22 20:17:52 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_info *info, int flag)
{
	int	i;

	if (info->b_size > 0)
	{
		i = 0;
		if (info->a_size)
			i = info->a_size - 1;
		while (i-- >= 0)
			info->a[i + 1] = info->a[i];
		info->a[0] = info->b[0];
		i = -1;
		while (++i < info->b_size - 1)
			info->b[i] = info->b[i + 1];
		info->a_size++;
		info->b_size--;
		if (flag)
			ft_printf("pa\n");
	}
}
