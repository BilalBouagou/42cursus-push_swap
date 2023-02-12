/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:10:07 by bbouagou          #+#    #+#             */
/*   Updated: 2023/01/18 14:44:27 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_(t_strct **list, int nbr, unsigned int u)
{
	char	*s;

	if (nbr && !u)
		s = ft_itoa(nbr);
	else if (!nbr && u)
		s = ft_itoau(u);
	else
		s = ft_itoa(nbr);
	ft_putstr_(&(*list), s);
	free(s);
}
