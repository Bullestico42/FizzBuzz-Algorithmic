/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiscopo <apiscopo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:21:02 by apiscopo          #+#    #+#             */
/*   Updated: 2024/10/09 14:54:16 by apiscopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;
	size_t	new_len;
	char	*res;

	start = 0;
	end = ft_strlen(s1);
	if (!s1)
		return (NULL);
	while (start < end && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	new_len = end - start;
	res = (char *)malloc(end - start + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1 + start, new_len + 1);
	return (res);
}
