/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:18:43 by bbouagou          #+#    #+#             */
/*   Updated: 2023/02/22 21:29:05 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_info *info, int flag)
{
	int	i;
	int	tmp;

	if (info->b_size > 1)
	{
		i = -1;
		tmp = info->b[0];
		while (++i < info->b_size - 1)
			info->b[i] = info->b[i + 1];
		info->b[info->b_size - 1] = tmp;
		if (flag)
			ft_printf("rb\n");
	}
}
