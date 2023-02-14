/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 20:34:31 by bbouagou          #+#    #+#             */
/*   Updated: 2023/02/14 11:57:32 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** imma implement a simple stupid sorting algorithm,
** ill look for the smallest int in stack a and push it
** to stack b, repeat the process untill stack a has only one element left
** then push everything from stack b to stack a.
*/

static void	sort_stack(t_info *info)
{
	int	i;
	int	j;

	if (info->a_size <= 3)
		sort_three(&(*info), info->c);
	else if (info->a_size == 4)
		sort_four(&(*info));
}

/*
** simple bubble sort to sort the c stack.
*/

static void	sort_array(t_info *info)
{
	size_t	i;
	size_t	j;
	int		tmp;

	i = 0;
	while (i < info->c_size)
	{
		j = 0;
		while (j < info->c_size)
		{
			if (info->c[i] < info->c[j])
			{
				tmp = info->c[i];
				info->c[i] = info->c[j];
				info->c[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

/*
** simple function to check if stack a is already sorted or not.
*/

static int	check_stack(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->c_size)
	{
		if (info->c[i] != info->a[i])
			return (1);
		i++;
	}
	return (0);
}

/*
** idk what i'm doing here so im just gonna first
** create a third stack named c and sort it, it may
** be of use later on.
*/

void	sort(t_info *info)
{
	size_t	i;

	i = 0;
	info->c = (int *)malloc(sizeof(int) * info->a_size);
	if (!info->c)
	{
		ft_printf("Error\nMalloc failure.\n");
		exit(-1);
	}
	info->c_size = info->a_size;
	while (i < info->c_size)
	{
		info->c[i] = info->a[i];
		i++;
	}	
	sort_array(&(*info));
	if (check_stack(&(*info)))
		sort_stack(&(*info));
}
