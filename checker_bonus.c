/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 07:15:10 by bbouagou          #+#    #+#             */
/*   Updated: 2023/02/24 23:24:54 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	init_struct(t_info *info)
{
	info->a_size = 0;
	info->b_size = 0;
}

static int	check_instruction(char *str)
{
	if (!ft_strcmp(str, "sa\n")
		|| !ft_strcmp(str, "sb\n")
		|| !ft_strcmp(str, "ss\n")
		|| !ft_strcmp(str, "ra\n")
		|| !ft_strcmp(str, "rb\n")
		|| !ft_strcmp(str, "rr\n")
		|| !ft_strcmp(str, "rra\n")
		|| !ft_strcmp(str, "rrb\n")
		|| !ft_strcmp(str, "rrr\n")
		|| !ft_strcmp(str, "pb\n")
		|| !ft_strcmp(str, "pa\n"))
		return (1);
	return (0);
}

static void	apply_instruction(char *str, t_info *info)
{
	if (!ft_strcmp(str, "sa\n"))
		sa(&(*info), 0);
	else if (!ft_strcmp(str, "sb\n"))
		sb(&(*info), 0);
	else if (!ft_strcmp(str, "ss\n"))
		ss(&(*info));
	else if (!ft_strcmp(str, "ra\n"))
		ra(&(*info), 0);
	else if (!ft_strcmp(str, "rb\n"))
		rb(&(*info), 0);
	else if (!ft_strcmp(str, "rra\n"))
		rra(&(*info), 0);
	else if (!ft_strcmp(str, "rrb\n"))
		rrb(&(*info), 0);
	else if (!ft_strcmp(str, "rr\n"))
		rr(&(*info));
	else if (!ft_strcmp(str, "pa\n"))
		pa(&(*info), 0);
	else if (!ft_strcmp(str, "pb\n"))
		pb(&(*info), 0);
	else
		rrr(&(*info));
	free (str);
}

static int	check_array(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->a_size - 1)
	{
		if (info->a[i] > info->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_info		info;
	char		*string;

	if (argc > 1)
	{
		init_struct(&info);
		parse(&info, argv + 1, argc - 1);
		info.b = (int *)malloc(sizeof(int) * info.a_size);
		string = get_next_line(0);
		while (string)
		{
			if (!check_instruction(string))
			{
				write(2, "Error\n", 6);
				return (0);
			}
			else
				apply_instruction(string, &info);
			string = get_next_line(0);
		}
		if (check_array(&info))
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
}
