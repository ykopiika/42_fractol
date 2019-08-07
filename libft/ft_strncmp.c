/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 18:08:45 by ykopiika          #+#    #+#             */
/*   Updated: 2018/11/14 18:08:48 by ykopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s11;
	unsigned char	*s22;
	size_t			i;

	s11 = (unsigned char*)s1;
	s22 = (unsigned char*)s2;
	i = 1;
	if (n == 0)
		return (0);
	while (*s11 && *s22 && (*s11 == *s22) && i < n && n > 0)
	{
		s11++;
		s22++;
		i++;
	}
	return (*s11 - *s22);
}
