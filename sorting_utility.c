/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utility.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 07:06:29 by bbouagou          #+#    #+#             */
/*   Updated: 2023/02/18 09:15:34 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_stack_b(t_info *info, int i)
{
	if ((i >= info->start && i <= info->end))
		pb(&(*info), 1);
	else
	{
		rra(&(*info), 1);
		pb(&(*info), 1);
	}
	info->flag = 1;
}

void	push_to_b_and_rotate(t_info *info, int i)
{
	if (i < info->start)
	{
		pb(&(*info), 1);
		rb(&(*info), 1);
	}
	else
	{
		rrb(&(*info), 1);
		pb(&(*info), 1);
		rb(&(*info), 1);
	}
	info->flag = 1;
}
