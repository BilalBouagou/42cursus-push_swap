/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:23:51 by bbouagou          #+#    #+#             */
/*   Updated: 2023/02/23 23:32:37 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Shift down all elements of stack a by 1.
** The last element becomes the first one.
*/

void	rra(t_info *info, int flag)
{
	int	i;
	int	tmp;

	if (info->a_size > 1)
	{
		i = info->a_size - 1;
		tmp = info->a[info->a_size - 1];
		while (--i >= 0)
			info->a[i + 1] = info->a[i];
		info->a[0] = tmp;
		if (flag)
			ft_printf("rra\n");
	}
}
