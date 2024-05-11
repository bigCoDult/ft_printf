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

int		ft_putfmt(t_nums *nums, va_list ap, char c, unsigned long long int ptr);
void	ft_test_specifier(const char *str, t_nums *nums, va_list ap);

int	ft_printf(const char *str, ...)
{
	va_list					ap;
	t_nums					*nums;
	int						final_count;

	nums = malloc(sizeof(t_nums));
	if (nums == NULL)
		return (-1);
	va_start(ap, str);
	nums->count = 0;
	ft_test_specifier(str, nums, ap);
	va_end(ap);
	final_count = nums->count;
	free(nums);
	return (final_count);
}

void	ft_test_specifier(const char *str, t_nums *nums, va_list ap)
{
	unsigned long long int	ptr;

	ptr = 0;
	while (*str)
	{
		if (*str == '%')
			ft_putfmt(nums, ap, *++str, ptr);
		else
			nums->count += ft_putchar_fd(*str, 1);
		str++;
	}
}

int	ft_putfmt(t_nums *nums, va_list ap, char c, unsigned long long int ptr)
{
	if (c == '%')
		nums->count += ft_putchar_fd('%', 1);
	else if (c == 'c')
		nums->count += ft_putchar_fd(va_arg(ap, int), 1);
	else if (c == 's')
		nums->count += ft_putstr_fd(va_arg(ap, char *), 1);
	else if (c == 'd' || c == 'i')
		nums->count += ft_putlonglong_fd(va_arg(ap, int), 1);
	else if (c == 'u')
	{
		nums->u = (va_arg(ap, unsigned int));
		nums->count += ft_putlonglong_fd(nums->u, 1);
	}
	else if (c == 'x')
		nums->count += ft_puthex_fd(1, va_arg(ap, unsigned long long int), 1);
	else if (c == 'X')
		nums->count += ft_puthex_fd(0, va_arg(ap, unsigned long long int), 1);
	else if (c == 'p')
	{
		ptr = (unsigned long long int)va_arg(ap, void *);
		nums->count += ft_putstr_fd("0x", 1);
		nums->count += ft_puthex_fd(1, ptr, 1);
	}
	return (nums->count);
}
