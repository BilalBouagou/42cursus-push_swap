/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:14:01 by bbouagou          #+#    #+#             */
/*   Updated: 2023/02/12 06:50:59 by bbouagou         ###   ########.fr       */
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
}

/*
** calls the parse_args from parsing_utility.c to check the supplied arguments.
** If no arguments are supplied, nothing happens.
*/

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc > 1)
	{
		init_struct(&info);
		parse_args(&info, argv + 1, argc - 1);
		sort(&info);
	}
	return (0);
}
