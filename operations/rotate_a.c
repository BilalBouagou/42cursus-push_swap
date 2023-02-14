/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:12:58 by bbouagou          #+#    #+#             */
/*   Updated: 2023/02/13 12:23:45 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
** Shift up all elements of stack a by 1.
** The first element becomes the last one.
*/

void	ra(t_info *info)
{
	int	*new_a;
	int	i;

	i = -1;
	if (info->a_size > 1)
	{
		new_a = (int *)malloc(sizeof(int) * info->a_size);
		while (++i < (info->a_size - 1))
			new_a[i] = info->a[i + 1];
		new_a[i] = info->a[0];
		free (info->a);
		info->a = new_a;
	}
	ft_printf("ra\n");
}