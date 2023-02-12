/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:21:17 by bbouagou          #+#    #+#             */
/*   Updated: 2023/01/18 14:44:46 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_(t_strct **list, char *string)
{
	int	i;

	i = -1;
	if (!string)
	{
		(*list)->count += write(1, "(null)", 6);
		return ;
	}
	while (string[++i])
	(*list)->count += write(1, &string[i], 1);
}
