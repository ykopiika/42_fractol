/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmapone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:24:02 by ykopiika          #+#    #+#             */
/*   Updated: 2018/12/12 17:24:05 by ykopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmapone(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*r_f;
	t_list	*ret;

	if (!f || !lst)
		return (NULL);
	r_f = f(lst);
	ret = ft_lstnew(r_f->content, r_f->content_size);
	if (!ret)
	{
		free(ret);
		ret = NULL;
	}
	return (ret);
}
