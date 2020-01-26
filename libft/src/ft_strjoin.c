/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deladia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 19:22:22 by deladia           #+#    #+#             */
/*   Updated: 2019/04/10 18:43:15 by deladia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s12;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s12 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s12 == NULL)
		return (NULL);
	while (s1[j] != '\0')
	{
		s12[i++] = s1[j++];
	}
	j = 0;
	while (s2[j] != '\0')
	{
		s12[i++] = s2[j++];
	}
	s12[i] = '\0';
	return (s12);
}
