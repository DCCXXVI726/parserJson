/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deladia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 13:50:08 by deladia           #+#    #+#             */
/*   Updated: 2019/04/12 18:59:49 by deladia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char			*dst;
	const unsigned char		*sr;
	size_t					i;

	dst = dest;
	sr = src;
	i = 0;
	while (i < n)
	{
		dst[i] = sr[i];
		if (sr[i] == (unsigned char)c)
		{
			dst[i] = sr[i];
			return (&dest[i + 1]);
		}
		i++;
	}
	return (NULL);
}
