/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:59:28 by ykopiika          #+#    #+#             */
/*   Updated: 2018/11/26 16:59:30 by ykopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int	r;

	if (!s1 || !s2 || (!*s1 && !*s2) || n <= 0)
		return (1);
	if ((!*s1 && *s2) || (*s1 && !*s2))
		return (0);
	if (ft_strncmp(s1, s2, n) == 0)
		r = 1;
	else
		r = 0;
	return (r);
}