/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 19:14:32 by ykopiika          #+#    #+#             */
/*   Updated: 2018/11/13 19:14:34 by ykopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
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
	{
		if (str[i] == r)
			return (&(str[i]));
		i++;
	}
	if (r == '\0')
		return (&(str[i]));
	return (NULL);
}
