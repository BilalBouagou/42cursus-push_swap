/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 07:15:10 by bbouagou          #+#    #+#             */
/*   Updated: 2023/02/18 11:39:46 by bbouagou         ###   ########.fr       */
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
	if (!ft_strncmp(str, "sa", ft_strlen(str) - 1)
		|| !ft_strncmp(str, "sb", ft_strlen(str) - 1)
		|| !ft_strncmp(str, "ss", ft_strlen(str) - 1)
		|| !ft_strncmp(str, "ra", ft_strlen(str) - 1)
		|| !ft_strncmp(str, "rb", ft_strlen(str) - 1)
		|| !ft_strncmp(str, "rr", ft_strlen(str) - 1)
		|| !ft_strncmp(str, "rra", ft_strlen(str) - 1)
		|| !ft_strncmp(str, "rrb", ft_strlen(str) - 1)
		|| !ft_strncmp(str, "rrr", ft_strlen(str) - 1)
		|| !ft_strncmp(str, "pb", ft_strlen(str) - 1)
		|| !ft_strncmp(str, "pa", ft_strlen(str) - 1))
		return (1);
	return (0);
}

static void	apply_instruction(char *str, t_info *info)
{
	if (!ft_strncmp(str, "sa", 2))
		sa(&(*info), 0);
	else if (!ft_strncmp(str, "sb", ft_strlen(str) - 1))
		sb(&(*info), 0);
	else if (!ft_strncmp(str, "ss", ft_strlen(str) - 1))
		ss(&(*info));
	else if (!ft_strncmp(str, "ra", ft_strlen(str) - 1))
		ra(&(*info), 0);
	else if (!ft_strncmp(str, "rb", ft_strlen(str) - 1))
		rb(&(*info), 0);
	else if (!ft_strncmp(str, "rra", ft_strlen(str) - 1))
		rra(&(*info), 0);
	else if (!ft_strncmp(str, "rrb", ft_strlen(str) - 1))
		rrb(&(*info), 0);
	else if (!ft_strncmp(str, "rr", ft_strlen(str) - 1))
		rr(&(*info));
	else if (!ft_strncmp(str, "pa", ft_strlen(str) - 1))
		pa(&(*info), 0);
	else if (!ft_strncmp(str, "pb", ft_strlen(str) - 1))
		pb(&(*info), 0);
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
		j = i + 1;
		while (j < info->a_size)
		{
			if (info->a[i] > info->a[j])
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
