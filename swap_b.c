/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 06:59:56 by bbouagou          #+#    #+#             */
/*   Updated: 2023/02/18 09:14:41 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_info *info, int flag)
{
	int	tmp;

	tmp = 0;
	if (info->b_size)
	{
		tmp = info->b[1];
		info->b[1] = info->b[0];
		info->b[0] = tmp;
	}
	if (flag)
		ft_printf("sb\n");
}
