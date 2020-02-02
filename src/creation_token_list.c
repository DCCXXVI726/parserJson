/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation_token_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deladia <deladia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 16:16:00 by deladia           #+#    #+#             */
/*   Updated: 2020/02/01 13:51:57 by deladia          ###   ########.fr       */
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

int				ft_gnl(ssize_t fd, t_token **token_head)
{
	char	*line;
	t_token	*token_tmp;

	token_tmp = *token_head;
	while (get_next_line(fd, &line) > 0)
	{
		if ((token_tmp = parse(line, token_tmp)) == 0)
		{
			ft_strdel(&line);
			return (ft_free_token(token_head));
		}
		free(line);
	}
	return (1);
}
