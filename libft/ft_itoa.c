/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiscopo <apiscopo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 13:38:10 by apiscopo          #+#    #+#             */
/*   Updated: 2024/10/06 15:16:22 by apiscopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sizetab(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i += 1;
		if (n == -2147483648)
			return (11);
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	ft_itoa_recursive(int n, char *res, int *i)
{
	if (n < 0)
	{
		res[(*i)++] = '-';
		if (n == -2147483648)
		{
			res[(*i)++] = '2';
			n = 147483648;
		}
		else
			n = -n;
	}
	if (n > 9)
		ft_itoa_recursive(n / 10, res, i);
	res[(*i)++] = (n % 10) + '0';
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;
	int		i;

	len = ft_sizetab(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		res[i++] = '-';
		if (n == -2147483648)
		{
			res[i++] = '2';
			n = 147483648;
		}
		else
			n = -n;
	}
	ft_itoa_recursive(n, res, &i);
	res[i] = '\0';
	return (res);
}
