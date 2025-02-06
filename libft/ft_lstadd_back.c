/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiscopo <apiscopo@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:06:44 by apiscopo          #+#    #+#             */
/*   Updated: 2024/10/11 15:45:29 by apiscopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*back;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	back = ft_lstlast(*lst);
	if (back == NULL)
	{
		*lst = new;
	}
	back->next = new;
}
