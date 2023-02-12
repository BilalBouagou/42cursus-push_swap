/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:28:14 by bbouagou          #+#    #+#             */
/*   Updated: 2023/01/24 10:29:01 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrb(t_info *info)
{
	int	*new_b;
	int	i;

	i = -1;
	if (info->b_size > 1)
	{
		new_b = (int *)malloc(sizeof(int) * info->b_size);
		while (++i < (info->b_size - 1))
			new_b[i + 1] = info->b[i];
		new_b[0] = info->b[i];
		free (info->b);
		info->b = new_b;
	}
}
