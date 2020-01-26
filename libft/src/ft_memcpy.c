/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deladia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 13:29:38 by deladia           #+#    #+#             */
/*   Updated: 2019/04/09 16:39:21 by deladia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dst;
	unsigned const char	*sr;

	dst = dest;
	sr = src;
	while (n > 0)
	{
		*dst++ = *sr++;
		n--;
	}
	return (dest);
}
