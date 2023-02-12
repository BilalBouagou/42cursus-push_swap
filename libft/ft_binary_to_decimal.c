/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_to_decimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:18:59 by bbouagou          #+#    #+#             */
/*   Updated: 2023/01/20 17:05:17 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	binary_to_decimal(char *byte)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (byte[i])
	{
		if (byte[i] == '1')
			result += ft_pow(2, (int)ft_strlen(&byte[i + 1]));
		i++;
	}
	free (byte);
	return (result);
}
