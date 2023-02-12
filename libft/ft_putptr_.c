/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:27:01 by bbouagou          #+#    #+#             */
/*   Updated: 2023/01/18 14:44:38 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_get_lenght(unsigned long p)
{
	size_t	count;

	count = 0;
	if (!p)
		return (1);
	while (p)
	{
		p /= 16;
		count++;
	}
	return (count);
}

static char	*ft_convert(unsigned long p)
{
	size_t			i;
	char			*stash;
	char			*base;

	base = "0123456789abcdef";
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

void	ft_putptr_(t_strct **list, unsigned long p)
{
	char	*s;

	s = ft_convert(p);
	(*list)->count += write(1, "0x", 2);
	ft_putstr_(&(*list), s);
	free(s);
}
