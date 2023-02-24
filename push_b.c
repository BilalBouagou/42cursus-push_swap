/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:09:18 by bbouagou          #+#    #+#             */
/*   Updated: 2023/02/23 22:59:32 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_info *info, int flag)
{
	int	i;

	if (info->a_size > 0)
	{
		i = 0;
		if (info->b_size)
			i = info->b_size;
		while (--i >= 0)
			info->b[i + 1] = info->b[i];
		info->b[0] = info->a[0];
		i = -1;
		while (++i < info->a_size - 1)
			info->a[i] = info->a[i + 1];
		info->b_size++;
		info->a_size--;
		if (flag)
			ft_printf("pb\n");
	}
}
