/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation_token_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deladia <deladia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 16:16:00 by deladia           #+#    #+#             */
/*   Updated: 2020/02/01 12:19:51 by deladia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "to_json.h"

t_token			*create_token(char *word, t_token *token)
{
	if (token->value == NULL)
		token->value = ft_strdup(word);
	else
	{
		if ((token->next = (t_token *)ft_memalloc(sizeof(t_token))) == NULL)
			return (NULL);
		token = token->next;
		token->value = ft_strdup(word);
	}
	return (token);
}
