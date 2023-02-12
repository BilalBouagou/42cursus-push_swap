/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 17:33:15 by bbouagou          #+#    #+#             */
/*   Updated: 2022/10/13 21:28:21 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	size_t		size_d;
	size_t		size_s;

	size_s = ft_strlen(src);
	if (dst == NULL && !dstsize)
		return (ft_strlen(src));
	size_d = ft_strlen(dst);
	if (size_d >= dstsize || dstsize == 0)
		return (dstsize + size_s);
	i = 0;
	while (src[i] != '\0' && (i + 1 < (dstsize - size_d)))
	{
		dst[size_d + i] = src[i];
		i++;
	}
	dst[size_d + i] = '\0';
	return (size_d + size_s);
}
