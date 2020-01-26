/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deladia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 16:08:47 by deladia           #+#    #+#             */
/*   Updated: 2019/04/14 16:20:45 by deladia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *new;

	if (size + 1 == 0)
		return (NULL);
	new = (void *)malloc(sizeof(void *) * size);
	if (new == NULL)
		return (NULL);
	ft_memset(new, 0, size);
	return (new);
}
