/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deladia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 15:16:54 by deladia           #+#    #+#             */
/*   Updated: 2019/04/11 17:03:07 by deladia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;
	t_list *head;

	head = *alst;
	while (head != NULL)
	{
		tmp = head->next;
		del(head->content, head->content_size);
		free(head);
		head = tmp;
	}
	*alst = NULL;
}
