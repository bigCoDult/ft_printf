#include "ft_printf.h"
# include <stdio.h>

int main()
{
    int n = 1;
    char *nptr = NULL;
    int *nl = NULL;
    ft_printf("%d \n",ft_printf("Hello, %% "));
          printf("%d \n",printf("Hello, %% "));
    ft_printf("%d \n",ft_printf("Hello, %c ", 'c'));
          printf("%d \n",printf("Hello, %c ", 'c'));
    ft_printf("%d \n",ft_printf("Hello, %s ", "world!"));
          printf("%d \n",printf("Hello, %s ", "world!"));
    ft_printf("%d \n",ft_printf("Hello, %s ", nptr));
          printf("%d \n",printf("Hello, %s ", nptr));
    ft_printf("%d \n",ft_printf("Hello, %d ", 4200));
          printf("%d \n",printf("Hello, %d ", 4200));
    ft_printf("%d \n",ft_printf("Hello, %d ", -4200));
          printf("%d \n",printf("Hello, %d ", -4200));
    ft_printf("%d \n",ft_printf("Hello, %u ", 4200));
          printf("%d \n",printf("Hello, %u ", 4200));
    ft_printf("%d \n",ft_printf("Hello, %u ", -4200));
          printf("%d \n",printf("Hello, %u ", -4200));
    ft_printf("%d \n",ft_printf("Hello, %x ", 4200));
          printf("%d \n",printf("Hello, %x ", 4200));
    ft_printf("%d \n",ft_printf("Hello, %X ", 4200));
          printf("%d \n",printf("Hello, %X ", 4200));
    ft_printf("%d \n",ft_printf("Hello, %x ", -4200));
          printf("%d \n",printf("Hello, %x ", -4200));
    ft_printf("%d \n",ft_printf("Hello, %X ", -4200));
          printf("%d \n",printf("Hello, %X ", -4200));
    ft_printf("%d \n",ft_printf("Hello, %p ", &n));
          printf("%d \n",printf("Hello, %p ", &n));
    ft_printf("%d \n",ft_printf("Hello, %p ", nl));
          printf("%d \n",printf("Hello, %p ", nl));
    ft_printf("%d \n",ft_printf("Hello, %s %d %u %x %X %p %c %% ", "world!", 42, 42, 42, 42, &n, 'c'));
          printf("%d \n",printf("Hello, %s %d %u %x %X %p %c %% ", "world!", 42, 42, 42, 42, &n, 'c'));
    return 0;
}

