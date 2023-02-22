/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:14:01 by bbouagou          #+#    #+#             */
/*   Updated: 2023/02/22 21:43:25 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Initiation function.
*/

static void	init_struct(t_info *info)
{
	info->a_size = 0;
	info->b_size = 0;
	info->c_size = 0;
}

static void	initiate_stacks(t_info *info)
{
	info->b = (int *)malloc(sizeof(int) * info->a_size);
	info->c = (int *)malloc(sizeof(int) * info->a_size);
	if (!info->c || !info->b)
	{
		write(2, "Error\n", 6);
		exit(-1);
	}
}

/*
** calls the parse_args from parsing_utility.c to check the supplied arguments.
** If no arguments are supplied, nothing happens.
*/

int	main(int argc, char **argv)
{
	t_info	info;

	info.flag = 0;
	if (argc > 1)
	{
		init_struct(&info);
		parse_args(&info, argv + 1, argc - 1);
		initiate_stacks(&info);
		sort(&info);
	}
	return (0);
}
