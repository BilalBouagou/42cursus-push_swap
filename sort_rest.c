/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:54:55 by bbouagou          #+#    #+#             */
/*   Updated: 2023/02/17 18:50:41 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_range(int size)
{
	return (size * 0.0375 + 11.25);
}

static int	get_index(t_info *info, int x)
{
	int	i;

	i = 0;
	while (i < info->c_size)
	{
		if (info->c[i] == x)
			return (i);
		i++;
	}
	return (i);
}

static void	empty_stack_a(t_info *info)
{
	int	i;
	int	j;

	while (info->a_size)
	{
		i = get_index(&(*info), info->a[0]);
		j = get_index(&(*info), info->a[info->a_size - 1]);
		if ((i >= info->start && i <= info->end) || (j >= info->start && j <= info->end))
		{
			if ((i >= info->start && i <= info->end))
				pb(&(*info));
			else
			{
				rra(&(*info));
				pb(&(*info));
			}
			info->flag = 1;
		}
		else if (i < info->start || j < info->start)
		{
			if (i < info->start)
			{
				pb(&(*info));
				rb(&(*info));
			}
			else
			{
				rrb(&(*info));
				pb(&(*info));
				rb(&(*info));
			}
			info->flag = 1;
		}
		else
			ra(&(*info));
		if (info->end < info->c_size && info->flag)
		{
			info->end++;
			info->start++;
			info->flag = 0;
		}
	}
}

static void	push_back_to_a(t_info *info)
{
	int	i;
	int	j;

	i = info->c_size - 1;
	while (info->b_size)
	{
		if (info->b[0] == info->c[i])
		{
			pa(&(*info));
			i--;
		}
		else
		{
			j = 0;
			while (info->b[j] != info->c[i])
				j++;
			if (j <= info->b_size / 2)
				rb(&(*info));
			else
				rrb(&(*info));
		}
	}
}

void	sort_rest(t_info *info)
{
	info->end = get_range(info->c_size);
	if (info->end > info->c_size - 1)
		info->end = info->c_size - 1;
	info->start = 0;
	empty_stack_a(&(*info));
	push_back_to_a(&(*info));
}
