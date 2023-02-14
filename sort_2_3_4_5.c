/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2_3_4_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:59:48 by bbouagou          #+#    #+#             */
/*   Updated: 2023/02/14 16:47:48 by bbouagou         ###   ########.fr       */
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

void	sort_four(t_info *info, int *c)
{
	int	i;

	i = 0;
	while (info->a[i] != info->c[0])
		i++;
	if (i <= 3)
	{
		while (c[0] != info->a[0])
			ra(&(*info));
	}
	else
		while (c[0] != info->a[0])
			rra(&(*info));
	pb(&(*info));
	sort_three(&(*info), c + 1);
	pa(&(*info));
	if (c[1] == info->a[0])
		sa(&(*info));
	else if (c[3] == info->a[0])
		ra(&(*info));
}

/*
** hard coding stacks of size 5
*/

void	sort_five(t_info *info, int *c)
{
	int	i;

	i = 0;
	while (info->a[i] != info->c[0])
		i++;
	if (i <= 3)
	{
		while (c[0] != info->a[0])
			ra(&(*info));
	}
	else
		while (c[0] != info->a[0])
			rra(&(*info));
	pb(&(*info));
	sort_four(&(*info), &c[1]);
	pa(&(*info));
	if (c[1] == info->a[0])
		sa(&(*info));
	else if (c[4] == info->a[0])
		ra(&(*info));
}
