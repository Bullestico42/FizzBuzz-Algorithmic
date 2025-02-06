/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiscopo <apiscopo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 21:53:27 by apiscopo          #+#    #+#             */
/*   Updated: 2024/10/18 17:42:49 by apiscopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

ssize_t	ft_puthex(unsigned int n, int index)
{
	char	*base;
	int		count;

	count = 0;
	if (index == 1)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n >= 16)
	{
		count += ft_puthex(n / 16, index);
		count += ft_putc(base[n % 16]);
	}
	else
		count += ft_putc(base[n]);
	return (count);
}
/*
	Converti un nombre en base 16 et l'affiche sur la sortie standard.
*/
