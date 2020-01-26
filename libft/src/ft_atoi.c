/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deladia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 12:12:09 by deladia           #+#    #+#             */
/*   Updated: 2019/04/08 18:45:52 by deladia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int res;
	int sign;

	sign = 1;
	res = 0;
	if (*str == ' ' || *str == '+' || *str == '-' ||
		(*str >= 48 && *str <= 57) || (*str >= 9 && *str <= 13))
	{
		while ((*str >= 9 && *str <= 13) || *str == ' ')
			str++;
		if (*str == '+' || (*str == '-' && (sign *= -1)))
			str++;
		while (*str == '0')
			str++;
		while (*str >= 48 && *str <= 57)
		{
			res = res * 10 + *str - '0';
			str++;
		}
		return (res * sign);
	}
	else
		return (0);
}
