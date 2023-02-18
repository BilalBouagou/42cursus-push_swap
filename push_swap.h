/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 06:38:13 by bbouagou          #+#    #+#             */
/*   Updated: 2023/02/18 09:13:30 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>

typedef int	t_stack;

typedef struct s_info
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*c;
	int		a_size;
	int		b_size;
	int		c_size;
	int		start;
	int		end;
	int		flag;
}	t_info;

/*	PARSING UTILITY FUNCTIONS	*/

void	parse_args(t_info *info, char **args, int argnum);

/*	OPERATIONS	*/

void	sa(t_info *info, int flag);
void	sb(t_info *info, int flag);
void	ss(t_info *info);
void	pa(t_info *info, int flag);
void	pb(t_info *info, int flag);
void	ra(t_info *info, int flag);
void	rb(t_info *info, int flag);
void	rr(t_info *info);
void	rra(t_info *info, int flag);
void	rrb(t_info *info, int flag);
void	rrr(t_info *info);

/*	SORTING UTILITY FUNCTIONS	*/

void	sort(t_info *info);
void	sort_three(t_info *info, int *c);
void	sort_four(t_info *info, int *c);
void	sort_five(t_info *info, int *c);
void	sort_rest(t_info *info);
void	push_to_b_and_rotate(t_info *info, int i);
void	push_to_stack_b(t_info *info, int i);

#endif