/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 11:26:58 by sanbaek           #+#    #+#             */
/*   Updated: 2024/05/11 11:26:58 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putfmt(t_etc *etc, va_list ap, char c, unsigned long long int ptr);
void	ft_test_specifier(const char *str, t_etc *etc, va_list ap);

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	t_etc	*etc;
	int		final_count;

	etc = malloc(sizeof(t_etc));
	if (etc == NULL)
		return (-1);
	va_start(ap, str);
	etc->count = 0;
	ft_test_specifier(str, etc, ap);
	va_end(ap);
	final_count = etc->count;
	free(etc);
	return (final_count);
}

void	ft_test_specifier(const char *str, t_etc *etc, va_list ap)
{
	unsigned long long int	ptr;

	ptr = 0;
	while (*str)
	{
		if (*str == '%')
			ft_putfmt(etc, ap, *++str, ptr);
		else
			etc->count += ft_putchar_fd(*str, 1);
		str++;
	}
}

int	ft_putfmt(t_etc *etc, va_list ap, char c, unsigned long long int ptr)
{
	if (c == '%')
		etc->count += ft_putchar_fd('%', 1);
	else if (c == 'c')
		etc->count += ft_putchar_fd(va_arg(ap, int), 1);
	else if (c == 's')
	{
		etc->string = (va_arg(ap, char *));
		if (etc->string == NULL)
			etc->count += ft_putstr_fd("(null)", 1);
		else
			etc->count += ft_putstr_fd(etc->string, 1);
	}
	else if (c == 'd' || c == 'i')
		etc->count += ft_putll_fd(va_arg(ap, int), 1);
	else if (c == 'u')
		etc->count += ft_putll_fd((unsigned int)va_arg(ap, unsigned int), 1);
	else if (c == 'x' || c == 'X')
		etc->count += ft_puthex_fd(c, va_arg(ap, unsigned long long int), 1);
	else if (c == 'p')
	{
		ptr = (unsigned long long int)va_arg(ap, void *);
		etc->count += ft_putstr_fd("0x", 1);
		etc->count += ft_puthex_fd('x', ptr, 1);
	}
	return (etc->count);
}
