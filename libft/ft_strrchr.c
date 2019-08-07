/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 14:10:25 by ykopiika          #+#    #+#             */
/*   Updated: 2018/11/14 14:10:28 by ykopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	r;
	char	*str;
	int		i;

	str = (char*)s;
	r = (char)c;
	i = 0;
	if (!s)
		return (NULL);
	while (str[i] != '\0')
		i++;
	if (r == '\0')
		return (&(str[i]));
	while (i >= 0)
	{
		if (str[i] == r)
			return (&(str[i]));
		i--;
	}
	return (NULL);
}
