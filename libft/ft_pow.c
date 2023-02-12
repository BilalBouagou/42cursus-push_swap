/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:12:51 by bbouagou          #+#    #+#             */
/*   Updated: 2023/01/18 15:13:15 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pow(int num, int power)
{
	int	result;

	result = 1;
	if (power == 1)
		return (num);
	while (power > 1)
	{
		if (result == 1)
			result = num;
		result = result * num;
		power--;
	}
	return (result);
}
