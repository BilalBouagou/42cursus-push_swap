/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:09:18 by bbouagou          #+#    #+#             */
/*   Updated: 2023/02/14 11:49:29 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	anti_norminette(t_info *info, int flag, int *ptr)
{
	if (flag)
	{
		info->b_size++;
		info->a_size--;
	}
	else
	{
		free (info->a);
		info->a = ptr;
		ft_printf("pb\n");
	}
}

void	pb(t_info *info)
{
	int	*new_a;
	int	*new_b;
	int	i;

	i = -1;
	if (info->a_size > 0)
	{
		new_b = (int *)malloc(sizeof(int) * (info->b_size + 1));
		while (++i < info->b_size)
			new_b[i + 1] = info->b[i];
		new_b[0] = info->a[0];
		if (info->a_size >= 1)
		{
			new_a = (int *)malloc(sizeof(int) * (info->a_size - 1));
			i = -1;
			while (++i < (info->a_size - 1))
				new_a[i] = info->a[i + 1];
			anti_norminette(&(*info), 0, new_a);
		}
		else
			free (info->a);
		free (info->b);
		info->b = new_b;
		anti_norminette(&(*info), 1, (void *)0);
	}
}
