/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_both.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 07:03:27 by bbouagou          #+#    #+#             */
/*   Updated: 2023/02/18 09:20:56 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_info *info)
{
	sa(&(*info), 0);
	sb(&(*info), 0);
	ft_printf("ss\n");
}
