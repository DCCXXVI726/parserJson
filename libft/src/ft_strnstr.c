/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deladia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 18:26:11 by deladia           #+#    #+#             */
/*   Updated: 2019/04/12 18:54:04 by deladia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i] && i < n)
	{
		j = 0;
		while (to_find[j] && str[i + j] == to_find[j] && ((i + j) < n))
			j++;
		if (!to_find[j])
			return ((char *)&str[i]);
		i++;
	}
	if (!to_find[0])
		return ((char *)&str[i]);
	return (NULL);
}
