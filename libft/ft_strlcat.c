/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 12:05:19 by ykopiika          #+#    #+#             */
/*   Updated: 2018/11/13 12:05:22 by ykopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;
	size_t	j;

	i = 0;
	j = i;
	if (ft_strlen(dst) > dstsize)
		len = dstsize;
	else
		len = ft_strlen(dst);
	while (dst[i] != '\0')
		i++;
	while (dstsize - 1 > i && dstsize > 0 && src[j] != '\0')
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (len + ft_strlen(src));
}
