/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:39:01 by bbouagou          #+#    #+#             */
/*   Updated: 2023/01/18 14:44:17 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_get_lenght(unsigned int p)
{
	size_t	count;

	count = 0;
	while (p)
	{
		p /= 16;
		count++;
	}
	return (count);
}

static char	*ft_convert(unsigned int p, char specifier)
{
	size_t			i;
	char			*stash;
	char			*base;

	if (specifier == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	i = ft_get_lenght(p);
	stash = (char *)malloc(i + 1);
	stash[i--] = '\0';
	if (!p)
	{
		stash[0] = '0';
		return (stash);
	}
	while (p > 0)
	{
		stash[i--] = base[p % 16];
		p /= 16;
	}
	return (stash);
}

void	ft_puthex_(t_strct **list, unsigned int x, char specifier)
{
	char	*s;

	s = ft_convert(x, specifier);
	if (*s == '0')
	{
		(*list)->count += write(1, "0", 1);
		free(s);
		return ;
	}
	ft_putstr_(&(*list), s);
	free(s);
}
