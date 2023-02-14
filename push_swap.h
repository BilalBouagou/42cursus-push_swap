/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 06:38:13 by bbouagou          #+#    #+#             */
/*   Updated: 2023/02/14 11:57:05 by bbouagou         ###   ########.fr       */
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
	size_t	a_size;
	size_t	b_size;
	size_t	c_size;
}	t_info;

/*	PARSING UTILITY FUNCTIONS	*/

void	parse_args(t_info *info, char **args, int argnum);

/*	OPERATIONS	*/

void	sa(t_info *info);
void	sb(t_info *info);
void	ss(t_info *info);
void	pa(t_info *info);
void	pb(t_info *info);
void	ra(t_info *info);
void	rb(t_info *info);
void	rr(t_info *info);
void	rra(t_info *info);
void	rrb(t_info *info);

/*	SORTING UTILITY FUNCTIONS	*/

void	sort(t_info *info);
void	sort_three(t_info *info, int *c);
void	sort_four(t_info *info);

#endif