/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_both.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:29:24 by bbouagou          #+#    #+#             */
/*   Updated: 2023/02/18 09:20:43 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_info *info)
{
	rra(&(*info), 0);
	rrb(&(*info), 0);
	ft_printf("rrr\n");
}
