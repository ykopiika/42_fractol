/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:59:58 by ykopiika          #+#    #+#             */
/*   Updated: 2018/11/26 17:00:00 by ykopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s || !*s)
		return (NULL);
	sub = ft_strnew(len);
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len && s[(size_t)start + i] != '\0')
	{
		sub[i] = s[(size_t)start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
