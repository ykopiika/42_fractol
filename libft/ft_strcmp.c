/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:54:04 by ykopiika          #+#    #+#             */
/*   Updated: 2018/11/14 17:54:06 by ykopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*s11;
	unsigned char	*s22;

	s11 = (unsigned char*)s1;
	s22 = (unsigned char*)s2;
	while (*s11 && *s22 && (*s11 == *s22))
	{
		s11++;
		s22++;
	}
	return (*s11 - *s22);
}
