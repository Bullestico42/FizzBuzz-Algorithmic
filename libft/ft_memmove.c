/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiscopo <apiscopo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:38:18 by apiscopo          #+#    #+#             */
/*   Updated: 2024/10/09 18:38:16 by apiscopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*tmpd;
	unsigned const char	*tmps;
	size_t				i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	tmpd = (unsigned char *)dst;
	tmps = (unsigned const char *)src;
	if (tmpd > tmps)
	{
		while (len-- > 0)
			tmpd[len] = tmps[len];
	}
	else
	{
		while (i < len)
		{
			tmpd[i] = tmps[i];
			i++;
		}
	}
	return (dst);
}
/*
Hello World
HelHello Wo
*/
