/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 09:53:19 by bbouagou          #+#    #+#             */
/*   Updated: 2023/02/18 09:09:12 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	anti_norminette(t_info *info, int flag, int *ptr, int i)
{
	if (flag)
	{
		if (info->a_size > 0)
			free (info->a);
		info->a_size++;
		info->b_size--;
	}
	else
	{
		free (info->b);
		info->b = ptr;
		if (i)
			ft_printf("pa\n");
	}
}

void	pa(t_info *info, int flag)
{
	int	*new_a;
	int	*new_b;
	int	i;

	i = -1;
	if (info->b_size > 0)
	{
		new_a = (int *)malloc(sizeof(int) * (info->a_size + 1));
		while (++i < info->a_size)
			new_a[i + 1] = info->a[i];
		new_a[0] = info->b[0];
		if (info->b_size >= 1)
		{
			new_b = (int *)malloc(sizeof(int) * (info->b_size - 1));
			i = -1;
			while (++i < (info->b_size - 1))
				new_b[i] = info->b[i + 1];
			anti_norminette(&(*info), 0, new_b, flag);
		}
		else
			free (info->b);
		anti_norminette(&(*info), 1, (void *)0, flag);
		info->a = new_a;
	}
}
