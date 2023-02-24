/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 07:15:10 by bbouagou          #+#    #+#             */
/*   Updated: 2023/02/24 22:36:27 by bbouagou         ###   ########.fr       */
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
