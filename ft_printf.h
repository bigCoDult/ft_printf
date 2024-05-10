#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_strlen(const char *s);
int	ft_putchar_fd(char c, int fd);
int	ft_putstr_fd(char *s, int fd);
int	ft_putnbr_fd(int n, int fd);
int	ft_puthex_fd(int islower, unsigned int n, int fd);

#endif /* FT_PRINTF_H */
