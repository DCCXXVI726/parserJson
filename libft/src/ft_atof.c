/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deladia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 19:15:40 by deladia           #+#    #+#             */
/*   Updated: 2020/01/31 06:51:36 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

static int    atoi_shift(char **s, size_t *i)
{
	int number;

	number = ft_atoi(*s);
	*i = 0;
	while (**s != 0)
	{
		if (**s == '-' || **s == '+')
		{
			if (*i != 0)
				return (number);
		}
		else if (ft_isdigit(**s) == 0)
			return (number);
		(*s)++;
		(*i)++;
	}
	return (number);
}

double        ft_atof(char *s)
{
	size_t            i;
	double            number;
	double            nbr_point;

	if (s == 0)
		return (0);
	number = atoi_shift(&s, &i);
	if (*(s) != '.' && ft_isdigit(*(s + 1)) == 0)
		return(number);
	s++;
	nbr_point = atoi_shift(&s, &i);
	while (i-- > 0)
		nbr_point = nbr_point / 10;
	if (number < 0)
		number -= nbr_point;
	else
		number += nbr_point;
	return (number);
}
