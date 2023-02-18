/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:18:43 by bbouagou          #+#    #+#             */
/*   Updated: 2023/02/18 07:59:01 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_info *info)
{
	int	*new_b;
	int	i;

	i = -1;
	if (info->b_size > 1)
	{
		new_b = (int *)malloc(sizeof(int) * info->b_size);
		while (++i < (info->b_size - 1))
			new_b[i] = info->b[i + 1];
		new_b[i] = info->b[0];
		free (info->b);
		info->b = new_b;
	}
	ft_printf("rb\n");
}
