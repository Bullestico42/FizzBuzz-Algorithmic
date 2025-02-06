/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiscopo <apiscopo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:01:20 by apiscopo          #+#    #+#             */
/*   Updated: 2024/10/04 16:20:05 by apiscopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	ptrc;

	ptr = (unsigned char *)s;
	ptrc = (unsigned char)c;
	while (n > 0)
	{
		if (ptrc != *(ptr))
		{
			ptr++;
			n--;
		}
		else
			return ((unsigned char *)ptr);
	}
	return (NULL);
}
