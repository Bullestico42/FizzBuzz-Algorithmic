/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiscopo <apiscopo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 02:03:07 by apiscopo          #+#    #+#             */
/*   Updated: 2024/10/18 17:44:01 by apiscopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

ssize_t	ft_putun(unsigned int n)
{
	char	c;
	int		count;

	count = 0;
	if (n == 2147483647)
	{
		write(1, "2147483647", 10);
		return (10);
	}
	if (n > 9)
	{
		count += ft_putun(n / 10);
	}
	c = (n % 10) + '0';
	count += write(1, &c, 1);
	return (count);
}
/*
	Converti un nombre "unsigned" en base 10 et l'affiche sur la sortie standard.
*/
