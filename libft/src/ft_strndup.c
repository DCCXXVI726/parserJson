/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deladia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 14:52:57 by deladia           #+#    #+#             */
/*   Updated: 2019/06/12 14:53:01 by deladia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*result;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i] && i < n)
		i++;
	if (!(result = ft_memalloc(i + 1)))
		return (NULL);
	while (s1[j] && j < n)
	{
		result[j] = s1[j];
		j++;
	}
	result[j] = '\0';
	return (result);
}
