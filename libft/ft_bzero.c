/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiscopo <apiscopo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 12:36:28 by apiscopo          #+#    #+#             */
/*   Updated: 2024/10/04 12:48:43 by apiscopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*char_s;

	if (n == 0)
		return ;
	char_s = (char *)s;
	while (n--)
	{
		*char_s++ = '\0';
	}
}
/*int main()
{
  const char a[] = "Burger";
  ft_bzero(a,3);
}*/
