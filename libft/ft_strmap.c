/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:58:40 by ykopiika          #+#    #+#             */
/*   Updated: 2018/11/26 16:58:42 by ykopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*d;
	size_t	i;

	if (!s || !f || !*s || !*f)
		return (NULL);
	i = ft_strlen(s);
	d = ft_strnew(i);
	if (!d)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		d[i] = f(s[i]);
		i++;
	}
	d[i] = '\0';
	return (d);
}
