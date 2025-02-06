/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiscopo <apiscopo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:05:18 by apiscopo          #+#    #+#             */
/*   Updated: 2024/10/09 13:27:15 by apiscopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*tmpd;
	const unsigned char	*tmps;
	size_t				i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	tmpd = (unsigned char *)dst;
	tmps = (const unsigned char *)src;
	while (n > 0)
	{
		tmpd[i] = tmps[i];
		n--;
		i++;
	}
	return (dst);
}
