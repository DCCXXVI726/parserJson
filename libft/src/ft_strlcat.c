/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deladia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:14:49 by deladia           #+#    #+#             */
/*   Updated: 2019/04/09 16:35:54 by deladia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t i;
	size_t j;
	size_t res;

	i = 0;
	while (dest[i] != '\0')
		i++;
	res = 0;
	while (src[res] != '\0')
		res++;
	if (n <= i)
		res += n;
	else
		res += i;
	j = 0;
	while (src[j] != '\0' && i + 1 < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (res);
}
