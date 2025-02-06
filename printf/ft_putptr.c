/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiscopo <apiscopo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 23:31:25 by apiscopo          #+#    #+#             */
/*   Updated: 2024/10/18 17:43:14 by apiscopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_putnbr_ptr(unsigned long long nbr, char *base, int *count)
{
	if (nbr >= 16)
		ft_putnbr_ptr(nbr / 16, base, count);
	*count += write(1, &base[nbr % 16], 1);
}

ssize_t	ft_putptr(void *ptr)
{
	unsigned long long	addr;
	char				*base;
	int					count;

	addr = (unsigned long long)ptr;
	base = "0123456789abcdef";
	count = write(1, "0x", 2);
	if (addr == 0)
		return (count + write(1, "0", 1));
	ft_putnbr_ptr(addr, base, &count);
	return (count);
}
/*
	Affiche l'adresse d'un pointeur sur la sortie standard.
*/
