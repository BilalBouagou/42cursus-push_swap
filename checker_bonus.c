/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 07:15:10 by bbouagou          #+#    #+#             */
/*   Updated: 2023/02/18 08:57:58 by bbouagou         ###   ########.fr       */
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
	if (!ft_strncmp(str, "sa", 2) || !ft_strncmp(str, "sb", 2)
		|| !ft_strncmp(str, "ss", 2) || !ft_strncmp(str, "ra", 2)
		|| !ft_strncmp(str, "rb", 2) || !ft_strncmp(str, "rr", 2)
		|| !ft_strncmp(str, "rra", 3) || !ft_strncmp(str, "rrb", 3)
		|| !ft_strncmp(str, "rrr", 3))
		return (1);
	return (0);
}

static void	apply_instruction(char *str, t_info *info)
{
	if (!ft_strncmp(str, "sa", 2))
		sa(&(*info));
	else if (!ft_strncmp(str, "sb", 2))
		sb(&(*info));
	else if (!ft_strncmp(str, "ss", 2))
		ss(&(*info));
	else if (!ft_strncmp(str, "ra", 2))
		ra(&(*info));
	else if (!ft_strncmp(str, "rb", 2))
		rb(&(*info));
	else if (!ft_strncmp(str, "rra", 3))
		rra(&(*info));
	else if (!ft_strncmp(str, "rrb", 3))
		rrb(&(*info));
	else if (!ft_strncmp(str, "rr", 2))
		rr(&(*info));
	else
		rrr(&(*info));
}

static int	sort_array(t_info *info)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	tmp = 0;
	while (i < info->a_size)
	{
		j = 0;
		while (j < info->a_size)
		{
			if (info->a[i] < info->a[j])
				tmp++;
			j++;
		}
		i++;
	}
	return (tmp);
}

int	main(int argc, char **argv)
{
	t_info		info;
	char		*string;

	if (argc > 1)
	{
		init_struct(&info);
		parse(&info, argv + 1, argc - 1);
		string = get_next_line(0);
		while (string)
		{
			if (!check_instruction(string))
			{
				ft_printf("Error\n");
				return (0);
			}
			else
				apply_instruction(string, &info);
			string = get_next_line(0);
		}
		if (!sort_array(&info) && !info.b_size)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	return (0);
}
