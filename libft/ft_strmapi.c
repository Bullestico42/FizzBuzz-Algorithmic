/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiscopo <apiscopo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:53:49 by apiscopo          #+#    #+#             */
/*   Updated: 2024/10/09 13:04:22 by apiscopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char				*res;
	unsigned int		i;

	i = 0;
	res = (char *)malloc((ft_strlen(s) + 1) * (sizeof(char)));
	if (!res)
		return (NULL);
	while (i < (unsigned int)ft_strlen(s))
	{
		res[i] = (f)(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
