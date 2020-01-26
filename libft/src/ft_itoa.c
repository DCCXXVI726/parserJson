/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deladia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 16:41:28 by deladia           #+#    #+#             */
/*   Updated: 2019/04/10 15:53:58 by deladia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		len;
	int		nb;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = (n < 0) ? 2 : 1;
	nb = n;
	while (nb >= 10 || nb <= -10)
	{
		nb = nb / 10;
		len++;
	}
	if ((str = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	str[len] = '\0';
	nb = (n < 0) ? -n : n;
	while (len-- > 0)
	{
		str[len] = nb % 10 + '0';
		nb = nb / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
