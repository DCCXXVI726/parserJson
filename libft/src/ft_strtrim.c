/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deladia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 19:49:38 by deladia           #+#    #+#             */
/*   Updated: 2019/04/11 14:51:48 by deladia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_start(char const *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		{
			if (s[i + 1] != ' ' && s[i + 1] != '\t' && s[i + 1] != '\n')
			{
				i++;
				break ;
			}
			i++;
		}
		else
			break ;
	}
	return (i);
}

static int	ft_finish(char const *s)
{
	int		i;
	int		res;

	i = ft_strlen(s) - 1;
	res = 0;
	while (i > 0)
	{
		if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		{
			if (s[i - 1] != ' ' && s[i - 1] != '\t' && s[i - 1] != '\n')
			{
				res++;
				break ;
			}
			i--;
			res++;
		}
		else
			break ;
	}
	return (res);
}

static char	*ft_contain(int start, int finish, char *str, char const *s)
{
	int		sum;
	int		i;

	i = 0;
	sum = ft_strlen(s) - start - finish;
	while (i < sum)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		start;
	int		finish;
	int		i;

	if (!s)
		return (NULL);
	start = ft_start(s);
	finish = ft_finish(s);
	i = ft_strlen(s);
	if (i == start)
	{
		str = (char *)malloc(sizeof(char) * 1);
		str[0] = '\0';
		return (str);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) - start - finish + 1));
	if (str == NULL)
		return (NULL);
	ft_contain(start, finish, str, s);
	return (str);
}
