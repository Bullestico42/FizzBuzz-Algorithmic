/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiscopo <apiscopo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:38:08 by apiscopo          #+#    #+#             */
/*   Updated: 2024/10/18 17:42:34 by apiscopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

ssize_t	ft_putc(char c)
{
	write(1, &c, 1);
	return (1);
}
/*
	Ecris le caractère c sur la sortie standard.
*/
