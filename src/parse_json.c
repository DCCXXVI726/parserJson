/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_json.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:44:06 by thorker           #+#    #+#             */
/*   Updated: 2020/02/01 11:28:36 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "to_json.h"

/*
** Начальная функция для создания ноды (первного объекта)
*/

t_key_value	*parse_json(char *file_name)
{
	t_key_value	*tmp;
	t_token		*token;
	t_token		*head_token;
	int			flag;

	tmp = NULL;
	flag = 0;
	if ((token = ft_open(file_name)) == 0)
		return (0);
	head_token = token;
	if (ft_strcmp(token->value, "{") != 0)
		flag = 1;
	else if ((t_token*)(tmp = make_object(&token)) == token)
		flag = 1;
	ft_free_token(&head_token);
	if (flag == 0)
		return (tmp);
	return (0);
}
