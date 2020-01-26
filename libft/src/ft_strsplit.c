/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deladia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:02:59 by deladia           #+#    #+#             */
/*   Updated: 2019/04/14 16:47:26 by deladia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrwrds(char const *s, char c)
{
	int		i;
	int		nbrwrds;

	i = 0;
	nbrwrds = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c)
			nbrwrds++;
		i++;
	}
	return (nbrwrds);
}

static void	ft_free(char **arrstr, int j)
{
	while (j-- > 0)
	{
		free(arrstr[j]);
		arrstr[j] = NULL;
	}
	free(arrstr);
	arrstr = NULL;
}

static char	**ft_split(char const *s, char c, char **arrstr)
{
	size_t			lenwrd;
	unsigned int	i;
	int				j;

	i = 0;
	j = 0;
	while (s[i])
		if (s[i] == c)
			i++;
		else
		{
			lenwrd = 0;
			while (s[i + lenwrd] && (s[i + lenwrd] != c))
				lenwrd++;
			arrstr[j++] = ft_strsub(s, i, lenwrd);
			if (arrstr[j - 1] == NULL)
			{
				ft_free(arrstr, j);
				return (NULL);
			}
			i = i + lenwrd;
		}
	arrstr[j] = 0;
	return (arrstr);
}

char		**ft_strsplit(char const *s, char c)
{
	char			**arrstr;

	if (!s || !c)
		return (NULL);
	arrstr = (char **)malloc(sizeof(char *) * (ft_nbrwrds(s, c) + 2));
	if (arrstr == NULL)
		return (NULL);
	if (ft_split(s, c, arrstr) == NULL)
		return (NULL);
	return (arrstr);
}
