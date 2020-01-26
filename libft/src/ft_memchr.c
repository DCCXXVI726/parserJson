/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deladia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:34:49 by deladia           #+#    #+#             */
/*   Updated: 2019/04/09 18:00:20 by deladia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int ch, size_t n)
{
	unsigned char	*ar;
	unsigned char	c;

	ar = (unsigned char *)arr;
	c = (unsigned char)ch;
	while (n > 0)
	{
		if (*ar++ == c)
		{
			return (--ar);
		}
		n--;
	}
	return (NULL);
}
