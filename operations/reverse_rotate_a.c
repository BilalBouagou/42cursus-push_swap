/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:23:51 by bbouagou          #+#    #+#             */
/*   Updated: 2023/02/13 12:22:29 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
** Shift down all elements of stack a by 1.
** The last element becomes the first one.
*/

void	rra(t_info *info)
{
	int	*new_a;
	int	i;

	i = -1;
	if (info->a_size > 1)
	{
		new_a = (int *)malloc(sizeof(int) * info->a_size);
		while (++i < (info->a_size - 1))
			new_a[i + 1] = info->a[i];
		new_a[0] = info->a[i];
		free (info->a);
		info->a = new_a;
	}
	ft_printf("rra\n");
}
