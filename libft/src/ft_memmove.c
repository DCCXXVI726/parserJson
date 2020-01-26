/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deladia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:06:37 by deladia           #+#    #+#             */
/*   Updated: 2019/04/09 19:55:41 by deladia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dst;
	const unsigned char	*sr;
	size_t				i;

	dst = (unsigned char *)dest;
	sr = (unsigned char *)src;
	i = 0;
	if (dst > sr)
		while (++i <= n)
			dst[n - i] = sr[n - i];
	else
		while (n-- > 0)
			*dst++ = *sr++;
	return (dest);
}
