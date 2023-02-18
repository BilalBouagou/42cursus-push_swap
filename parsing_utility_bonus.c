/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utility_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 01:35:42 by bbouagou          #+#    #+#             */
/*   Updated: 2023/02/18 11:31:04 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/*
** Loops over a string and checks if each character is a digit.
**
** The only exception are the space(' ') and minus('-') characters.
*/

static int	check_string(char *string)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (string[++i])
	{
		if (ft_isdigit(string[i]))
			j++;
		else if ((string[i] != ' ' && string[i] != '-' && string[i] != '+')
			|| (string[i] == '-' && !ft_isdigit(string[i + 1]))
			|| (string[i] == '+' && !ft_isdigit(string[i + 1])))
			return (0);
	}
	if (!j)
		return (0);
	return (1);
}

/*
** Allocates space for the new stack, copies the contents of the old stack,
** adds the new argument and frees the old stack.
*/

static int	*allocate_and_assign(t_info *info, char *string)
{
	int		i;
	int		*new_stack;

	i = -1;
	new_stack = (int *)malloc(sizeof(int) * (info->a_size + 1));
	if (!new_stack)
	{
		ft_printf("Error\n");
		exit(-1);
	}
	while (++i < info->a_size)
		new_stack[i] = info->a[i];
	new_stack[i] = ft_atoi(string);
	free (info->a);
	return (new_stack);
}

/*
** It first takes the string supplied and splits it using the ft_split function,
** e,i, if the string was "123" the double pointer integeres's first pointer will
** point to the string "123" and the second pointer will be a null pointer.
** Another example, if the string was " 123 545 66    5", the first pointer will
** point to the string "123", the second to "545"... and the last will be null.
**
** It then loops and for each pointer it compares the lenght of the string with
** the number of digits of its int representation (converting with ft_atoi),
** if they are not equal then the number was either larger than INT_MAX
** or smaller than INT_MIN and therefore an error message should be displayed.
**
** Finally if the number is fine, its stored in the stack a using the
** allocate_and_assign function (or assigned directly if it is the first
** argument), the pointer is freed and onwards to the next iteration.
*/

static void	feed_to_stack(t_info *info, char *string)
{
	char	**ints;
	int		i;
	size_t	size;

	i = -1;
	ints = ft_split(string, ' ');
	while (ints[++i])
	{
		if (ints[i][0] == '+' || (ints[i][0] == '-' && ft_atoi(ints[i]) == 0))
			size = ft_strlen(ints[i]) - 1;
		else
			size = ft_strlen(ints[i]);
		if (ft_intlen(ft_atoi(ints[i])) != size)
		{
			ft_printf("Error\n");
			exit(0);
		}
		if (info->a_size == 0)
			info->a[0] = ft_atoi(ints[i]);
		else
			info->a = allocate_and_assign(&(*info), ints[i]);
		info->a_size++;
		free (ints[i]);
	}
	free (ints);
}

/*
** iterates over each element of the stack and compares it with the rest
** of the stack, if duplicates are found, error message is dislpayed.
*/

static void	check_duplicates(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->a_size)
	{
		j = i;
		while (++j < info->a_size)
		{
			if (info->a[i] == info->a[j])
			{
				ft_printf("Error\n");
				exit(0);
			}
		}
		i++;
	}
}

/*
** Loops over the arguments and checks for non digit characters by calling
** check_string function, if the string only contains digit characters then
** it is stored in the stack a by calling the feed_to_stack function.
**
** Lastly, it checks for duplicates by calling the check_duplicates function.
*/

void	parse(t_info *info, char **args, int argnum)
{
	int	i;

	i = -1;
	while (++i < argnum)
	{
		if (!check_string(args[i]))
		{
			ft_printf("Error\n");
			exit(0);
		}
		else
		{
			if (info->a_size == 0)
			{
				info->a = (int *)malloc(sizeof(int));
				if (!info->a)
				{
					ft_printf("Error\n");
					exit(-1);
				}
			}
			feed_to_stack(&(*info), args[i]);
		}
	}
	check_duplicates(&(*info));
}
