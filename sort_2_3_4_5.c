/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2_3_4_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:59:48 by bbouagou          #+#    #+#             */
/*   Updated: 2023/02/14 11:59:10 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	sort_two(t_info *info)
{
	if (info->a[0] > info->a[1])
		sa(&(*info));
}

/*
** hard coding stacks of size 2-3.
*/

void	sort_three(t_info *info, int *c)
{
	if (info->a_size == 1)
		exit(0);
	else if (info->a_size == 2)
		sort_two(&(*info));
	if (c[0] == info->a[1] && info->a[2] == c[2])
		sa(&(*info));
	else if (c[0] == info->a[2] && c[2] == info->a[1])
		rra(&(*info));
	else if (c[2] == info->a[0] && c[0] == info->a[1])
		ra(&(*info));
	else if (c[2] == info->a[0] && c[0] == info->a[2])
	{
		sa(&(*info));
		rra(&(*info));
	}
	else if (c[1] == info->a[2] && c[2] == info->a[1])
	{
		rra(&(*info));
		sa(&(*info));
	}
}

/*
** hard coding stacks of size 4
*/

void	sort_four(t_info *info)
{
	if (info->c[2] == info->a[0])
		sa(&(*info));
	pb(&(*info));
	sort_three(&(*info), info->c + 1);
	pa(&(*info));
	if (info->c[1] == info->a[0])
		sa(&(*info));
	else if (info->c[3] == info->a[0])
		ra(&(*info));
}
