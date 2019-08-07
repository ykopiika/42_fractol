/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 13:52:30 by ykopiika          #+#    #+#             */
/*   Updated: 2018/11/06 13:52:43 by ykopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;
	size_t	i;

	d = (char*)dst;
	s = (char*)src;
	i = 0;
	if (!src && !dst)
		return (NULL);
	if ((s < d) && ((s - 1 + len) > d))
	{
		s = s + len - 1;
		d = d + len - 1;
		while (len-- > 0)
			*d-- = *s--;
	}
	else
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}
