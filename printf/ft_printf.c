/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiscopo <apiscopo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:17:28 by apiscopo          #+#    #+#             */
/*   Updated: 2024/12/15 22:24:00 by apiscopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			count += convert(str + i, &args);
			i += 1;
		}
		else
		{
			ft_putc(str[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
/*
	Verification si dans la chaine de caractère il y a un %,
	 si oui on appelle la fonction convert
	qui va convertir le type de variable en fonction du %
	et de la lettre qui suit le %.
	Si il n'y a pas de % on affiche le caractère
*/

ssize_t	convert(const char *str, va_list *args)
{
	if (*(str + 1) == 'c')
		return (ft_putc(va_arg(*args, int)));
	else if (*(str + 1) == 's')
		return (ft_putstr((char *)va_arg(*args, char *)));
	else if (*(str + 1) == 'd' || *(str + 1) == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	else if (*(str + 1) == 'u')
		return (ft_putun(va_arg(*args, unsigned int)));
	else if (*(str + 1) == 'x')
		return (ft_puthex(va_arg(*args, unsigned int), 1));
	else if (*(str + 1) == 'X')
		return (ft_puthex(va_arg(*args, unsigned int), 0));
	else if (*(str + 1) == '%')
		return (ft_putc('%'));
	else if (*(str + 1) == 'p')
		return (ft_putptr(va_arg(*args, void *)));
	else if (*(str + 1) == '\0')
		return (0);
	else
		return (-1);
	return (0);
}

/*int main ()
{
	ft_printf("Hello, %i %c%s %X", 42, 'W', "orld!", 31346543);
	return (0);
}*/
