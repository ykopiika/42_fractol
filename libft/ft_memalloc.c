/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:55:19 by ykopiika          #+#    #+#             */
/*   Updated: 2018/11/26 16:55:22 by ykopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*p;

	p = malloc(sizeof(void) * size);
	if (p == 0)
		return (NULL);
	ft_memset(p, 0, size);
	return (p);
}
