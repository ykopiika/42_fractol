/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 14:18:36 by ykopiika          #+#    #+#             */
/*   Updated: 2018/11/14 14:18:38 by ykopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		chek(char *str1, char *str2)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (str2[i] != '\0' && str1[i] != '\0')
	{
		if (str1[k] == str2[i])
			k++;
		i++;
	}
	if (k == i)
		return (1);
	return (0);
}

char			*ft_strstr(const char *haystack, const char *needle)
{
	char	*h;
	char	*n;

	if (!*needle)
		return ((char *)haystack);
	h = (char*)haystack;
	n = (char*)needle;
	while (*h != '\0')
	{
		if (chek(h, n) == 1)
			return (h);
		h++;
	}
	if (*n == '\0')
		return (h);
	return (NULL);
}
