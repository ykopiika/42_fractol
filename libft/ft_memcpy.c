/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 18:36:49 by ykopiika          #+#    #+#             */
/*   Updated: 2018/11/04 18:36:55 by ykopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	i = 0;
	if (!src && !dst)
		return (NULL);
	if (dst == src)
		return (dst);
	s = (unsigned char*)src;
	d = (unsigned char*)dst;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}
