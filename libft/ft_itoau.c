/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoau.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 22:21:55 by bbouagou          #+#    #+#             */
/*   Updated: 2023/01/18 14:34:47 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	get_integer_lenght(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static	void	write_to_string(unsigned int n, char *s, int size)
{
	while (size >= 0 && s[size] != '-')
	{
		if (n >= 10)
		{
			s[size] = n % 10 + '0';
			n /= 10;
		}
		else
			s[size] = n + '0';
		size--;
	}
}

char	*ft_itoau(unsigned int n)
{
	char	*result;
	int		size;

	size = get_integer_lenght(n) + 1;
	result = (char *)ft_calloc(size, sizeof(char));
	if (result == NULL)
		return (NULL);
	write_to_string(n, result, size - 2);
	result[size - 1] = '\0';
	return (result);
}
