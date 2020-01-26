/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deladia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 09:31:33 by deladia           #+#    #+#             */
/*   Updated: 2020/01/25 09:31:38 by deladia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

static double	ft_while(char **s, double nbr1)
{
	while (ft_isdigit(**s))
	{
		nbr1 = nbr1 * 10 + **s - '0';
		(*s)++;
	}
	return (nbr1);
}

double			ft_atof(char *s)
{
	int				i;
	double			nbr1;
	double			nbr2;
	short	int		sign;

	nbr1 = 0.0;
	nbr2 = 0.0;
	sign = 1;
	if (*s == '-')
	{
		s++;
		sign = -1;
	}
	nbr1 = ft_while(&s, nbr1);
	if (*s == '.')
		s++;
	i = 1;
	while (*s && ft_isdigit(*s))
	{
		nbr2 = nbr2 + (double)(*s - '0') / (pow(10, i));
		s++;
		i++;
	}
	return ((nbr1 + nbr2) * sign);
}
