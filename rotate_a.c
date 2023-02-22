/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:12:58 by bbouagou          #+#    #+#             */
/*   Updated: 2023/02/22 21:29:11 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Shift up all elements of stack a by 1.
** The first element becomes the last one.
*/

void	ra(t_info *info, int flag)
{
	int	i;
	int	tmp;

	if (info->a_size > 1)
	{
		i = -1;
		tmp = info->a[0];
		while (++i < info->a_size - 1)
			info->a[i] = info->a[i + 1];
		info->a[info->a_size - 1] = tmp;
		if (flag)
			ft_printf("ra\n");
	}
}
