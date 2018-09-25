/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fuctions.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpas <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 16:03:39 by mpas              #+#    #+#             */
/*   Updated: 2018/09/24 22:37:53 by mpas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

void  ft_putchar(char c)
{
    write(1,&c,1);
    
}

void    ft_putstr(char *str)
{
    int    i;
    
    i = 0;
    while (str[i] != '\0')
    {
        ft_putchar(str[i]);
        i++;
    }
}

int    ft_strlen(char *str)
{
    int    i;
    
    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

char    *ft_itoa_base(intmax_t value, int base)
{
    static char    basetab[] = "0123456789abcdef";
    static char    str[65];
    intmax_t       tmp;
    char        *nstr;
    
    nstr = &str[64];
    tmp = value < 0 ? -value : value;
    while (tmp)
    {
        *--nstr = basetab[tmp % base];
        tmp = tmp / base;
    }
    if (value < 0 && base == 10)
        *--nstr = '-';
    return (nstr);
}

int    b_printf(const char * restrict format, ...)
{
    va_list    args;
    int     count;
    int     i;
    char    character;
    char    *string;
   
    count = 0;
    i = 0;
    string = NULL;
    va_start(args, format);
    while (format[i] != '\0')
    {
        while (format[i] != '%' && format[i] != '\0')
        {
            ft_putchar(format[i]);
            i++;
            count++;
        }
        if (format[i] == '%')
        {
            i++;
            if (format[i] == 'c')
            {
                character = va_arg(args, int);
                ft_putchar(character);
                count++;
            }
            if (format[i] == 's')
            {  
                string = va_arg(args, char *);
                
                if (string != NULL)
                {
               		 ft_putstr(string);
                	count += ft_strlen(string);
                } else 
				{
                    ft_putstr("(null)");
                    count += 6;
                }
                
            }
            if (format[i] == 'd' || format[i] == 'i')
            {
                string = ft_itoa_base(va_arg(args, int), 10);
                ft_putstr(string);
                count += ft_strlen(string);
            }
            if (format[i] == 'u')
            {
                string = ft_itoa_base(va_arg(args, unsigned int), 10);
                ft_putstr(string);
                count += ft_strlen(string);
            }
            if (format[i] == 'p')
            {
                string = ft_itoa_base(va_arg(args, unsigned long long), 16);
                ft_putstr("0x");
                ft_putstr(string);
                count += ft_strlen(string) + 2;
            }
            if (format[i] == 'o')
            {
                string = ft_itoa_base(va_arg(args, unsigned int), 8);
                ft_putstr(string);
                count += ft_strlen(string);
            }
            if (format[i] == 'x')
            {
                string = ft_itoa_base(va_arg(args, unsigned int), 16);
                ft_putstr(string);
                count += ft_strlen(string);
            }
            if (format[i] == ' ')
                return (count);
    
            
        }
        if (format[i] != '\0')
            i++;
    }
    return (count);
}



int main()
{
	int d = -123;
	char c = 'c';
	char *str = "hola";
	int count= 0;
	char ch = 'k' ;
    char *string =NULL;

	count = printf("tr_printf prints: %s %s\n", str, str);
	printf("total chars: %d\n", count);
	count = b_printf("bb_printf prints: %s %s\n", str, str);
	b_printf("total chars: %d\n", count);

	count = printf("tr_printf prints: %c\n", c);
	printf("total chars: %d\n", count);
	count = b_printf("bb_printf prints: %c\n", c);
	b_printf("total chars: %d\n", count);

	count = printf("tr_printf prints: %d\n", d);
	printf("total chars: %d\n", count);
	count = b_printf("bb_printf prints: %d\n", d);
	b_printf("total chars: %d\n", count);

	count = printf("tr_printf prints: %i\n", d);
	printf("total chars: %d\n", count);
	count = b_printf("bb_printf prints: %i\n", d);
	b_printf("total chars: %d\n", count);

	count = printf("tr_printf prints: %p\n", str);
	printf("total chars: %d\n", count);
	printf("size of p: %lu\n", sizeof(str));
	count = b_printf("bb_printf prints: %p\n", str);
	b_printf("total chars: %d\n", count);

	count = printf("tr_printf prints: %o\n", d);
	printf("total chars: %d\n", count);
	count = b_printf("bb_printf prints: %o\n", d);
	b_printf("total chars: %d\n", count);

	count = printf("tr_printf prints: %u\n", d);
	printf("total chars: %d\n", count);
	count = b_printf("bb_printf prints: %u\n", d);
	b_printf("total chars: %d\n", count);

	count = printf("tr_printf prints: %x\n", d);
	printf("total chars: %d\n", count);
	count = b_printf("bb_printf prints: %x\n", d);
	b_printf("total chars: %d\n", count);

    b_printf("% s","%s","%d",ch ,"jhdjh",6588);
    printf("\n\n\n");
   printf("%s""%s","%d",ch,"\n","jhdjh",6588);
	printf("\n\n\n");
    
   
    b_printf("total chars: %d\n", count);
    count = printf("tr_printf prints: %s\n", string);
    printf("total chars: %d\n", count);
    count = b_printf("bb_printf prints: %s\n", string);
    b_printf("total chars: %d\n", count);

	return (0);
}

