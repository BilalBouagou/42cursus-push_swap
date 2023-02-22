/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:28:14 by bbouagou          #+#    #+#             */
/*   Updated: 2023/02/22 21:36:30 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_info *info, int flag)
{
	int	i;
	int	tmp;

	if (info->b_size > 1)
	{
		i = info->b_size - 1;
		tmp = info->b[info->b_size - 1];
		while (--i >= 0)
			info->b[i + 1] = info->b[i];
		info->b[0] = tmp;
		if (flag)
			ft_printf("rrb\n");
	}
}
