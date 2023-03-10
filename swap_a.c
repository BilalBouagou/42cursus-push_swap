/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 06:55:54 by bbouagou          #+#    #+#             */
/*   Updated: 2023/02/18 09:14:26 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_info *info, int flag)
{
	int	tmp;

	tmp = 0;
	if (info->a_size > 1)
	{
		tmp = info->a[1];
		info->a[1] = info->a[0];
		info->a[0] = tmp;
	}
	if (flag)
		ft_printf("sa\n");
}
