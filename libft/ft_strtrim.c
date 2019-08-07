/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:00:26 by ykopiika          #+#    #+#             */
/*   Updated: 2018/11/26 17:00:28 by ykopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_trm(char const *s, int len, char *res)
{
	int		j;
	int		i;

	j = 0;
	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	while (i < (len - ft_sp_end(s)))
	{
		res[j] = s[i];
		j++;
		i++;
	}
	res[j] = '\0';
	return (res);
}

char		*ft_strtrim(char const *s)
{
	char	*res;
	int		len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if ((ft_sp_beg(s) == 0 && ft_sp_end(s) == 0))
		return (ft_strdup(s));
	if ((ft_sp_beg(s) == ft_sp_end(s)) && ft_sp_end(s) == len)
		return (ft_strnew(0));
	res = ft_strnew(len - ft_sp_beg(s) - ft_sp_end(s));
	if (!res)
		return (NULL);
	res = ft_trm(s, len, res);
	return (res);
}
