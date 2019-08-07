/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:19:06 by ykopiika          #+#    #+#             */
/*   Updated: 2018/12/06 18:19:12 by ykopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*n;

	while (*alst && alst && del)
	{
		n = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = n;
	}
	*alst = NULL;
}
