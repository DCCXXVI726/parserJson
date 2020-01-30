/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deladia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 19:15:40 by deladia           #+#    #+#             */
/*   Updated: 2019/11/09 18:54:51 by deladia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

double		ft_atof(char *s)
{
	int				i;
	double			nbr1;
	double			nbr2;
	short	int		sign;

	nbr1 = 0.0;
	nbr2 = 0.0;
	sign = 1;
	if (*s++ == '-')
		sign = -1;
	while (ft_isdigit(*s) && *s != '.')
	{
		nbr1 = nbr1 * 10 + *s - '0';
		s++;
	}
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
