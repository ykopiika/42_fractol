/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:18:36 by ykopiika          #+#    #+#             */
/*   Updated: 2018/12/06 18:18:39 by ykopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_list;

	new_list = (t_list*)malloc(sizeof(t_list));
	if (!new_list)
		return (NULL);
	if (content == NULL)
	{
		new_list->content = NULL;
		new_list->content_size = 0;
	}
	else
	{
		new_list->content = (void*)malloc(content_size);
		if (!new_list->content)
		{
			free(new_list);
			return (NULL);
		}
		new_list->content_size = content_size;
		new_list->content = ft_memcpy(new_list->content, content, content_size);
	}
	new_list->next = NULL;
	return (new_list);
}
