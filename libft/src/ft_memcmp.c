/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deladia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:47:38 by deladia           #+#    #+#             */
/*   Updated: 2019/04/10 19:25:22 by deladia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	unsigned char	*ar1;
	unsigned char	*ar2;

	ar1 = (unsigned char *)arr1;
	ar2 = (unsigned char *)arr2;
	while (n-- > 0)
	{
		if (*ar1 != *ar2)
		{
			return (*ar1 - *ar2);
		}
		ar1++;
		ar2++;
	}
	return (0);
}
