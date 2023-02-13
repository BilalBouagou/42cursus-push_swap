/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:02:31 by bbouagou          #+#    #+#             */
/*   Updated: 2023/02/13 12:43:34 by bbouagou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_init(t_strct **list)
{
	(*list)->count = 0;
}

void	ft_handler(char specifier, t_strct **list)
{
	if (specifier == 'c')
		ft_putchar_(&(*list), va_arg((*list)->ptr, int));
	else if (specifier == 's')
		ft_putstr_(&(*list), va_arg((*list)->ptr, char *));
	else if (specifier == 'p')
		ft_putptr_(&(*list), va_arg((*list)->ptr, unsigned long));
	else if (specifier == 'x' || specifier == 'X')
		ft_puthex_(&(*list), va_arg((*list)->ptr, unsigned int), specifier);
	else if (specifier == 'd' || specifier == 'i' || specifier == 'u')
	{
		if (specifier == 'u')
			ft_putnbr_(&(*list), 0, va_arg((*list)->ptr, unsigned int));
		else
			ft_putnbr_(&(*list), va_arg((*list)->ptr, int), 0);
	}
	else if (specifier == '%')
		ft_putchar_(&(*list), '%');
}

int	ft_printf(const char *format, ...)
{
	t_strct	*list;
	int		i;

	list = (t_strct *)malloc(sizeof(t_strct));
	if (!list)
		return (-1);
	i = 0;
	ft_init(&list);
	va_start(list->ptr, format);
	while (format[i])
	{
		if (format[i] != '%')
			list->count += write(1, &format[i], 1);
		else
		{
			ft_handler(format[++i], &list);
		}
		i++;
	}
	va_end(list->ptr);
	i = list->count;
	free(list);
	return (i);
}
