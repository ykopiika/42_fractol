/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 17:28:28 by ykopiika          #+#    #+#             */
/*   Updated: 2018/11/04 17:28:32 by ykopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*a;
	unsigned char	c1;
	size_t			i;

	i = 0;
	c1 = (unsigned char)c;
	a = (unsigned char*)b;
	while (i < len)
	{
		a[i] = c1;
		i++;
	}
	if (b == NULL)
		return (NULL);
	return (b);
}
