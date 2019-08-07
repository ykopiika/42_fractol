/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:02:41 by ykopiika          #+#    #+#             */
/*   Updated: 2018/11/14 15:02:44 by ykopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *nee, size_t len)
{
	char	*h;
	char	*n;
	size_t	ln;
	size_t	i;

	h = (char*)hay;
	n = (char*)nee;
	ln = ft_strlen(n);
	i = 0;
	if (h == n || !*n)
		return (h);
	if (!*h)
		return (NULL);
	while (*h && i < len && (len - i) >= ln)
	{
		if (ft_strncmp(h, n, ln) == 0)
			return (h);
		h++;
		i++;
	}
	return (NULL);
}
