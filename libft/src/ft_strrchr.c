/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deladia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:02:09 by deladia           #+#    #+#             */
/*   Updated: 2019/04/09 20:50:02 by deladia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int		i;
	char	*res;

	i = 0;
	res = NULL;
	while (str[i] != '\0')
	{
		if (str[i] == ch)
		{
			res = ((char *)&str[i]);
		}
		i++;
	}
	if (res)
		return (res);
	if (ch == '\0')
		return ((char *)str + i);
	return (NULL);
}
