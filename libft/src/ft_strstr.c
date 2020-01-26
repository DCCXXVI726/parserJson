/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deladia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 18:10:25 by deladia           #+#    #+#             */
/*   Updated: 2019/04/11 18:55:52 by deladia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int		i;
	int		j;
	size_t	res;
	int		z;

	i = 0;
	res = 0;
	if (*to_find == '\0')
		return ((char *)str);
	while (str[i] != '\0')
	{
		j = 0;
		if (str[i] == to_find[0])
		{
			z = i;
			while (to_find[j] != '\0')
				if (str[z++] == to_find[j++])
					res++;
			if (res == ft_strlen(to_find))
				return ((char *)&str[z - res]);
		}
		i++;
		res = 0;
	}
	return (NULL);
}
