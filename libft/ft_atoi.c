/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:42:16 by ykopiika          #+#    #+#             */
/*   Updated: 2018/11/16 18:42:20 by ykopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long int	res;
	unsigned long int	ln;
	int					sign;

	res = 0;
	sign = 1;
	ln = 922337203685477580;
	while (*str != '\0' && ft_check_sp(*str))
		str++;
	if ((*str == '-') || (*str == '+'))
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9' && *str != '\0')
	{
		if ((res > ln || (res == ln && (*str - '0') > 7)) && sign == 1)
			return (-1);
		else if ((res > ln || (res == ln && (*str - '0') > 8)) && sign == -1)
			return (0);
		res = (res * 10) + (*str - '0');
		str++;
	}
	return ((int)(res * sign));
}
