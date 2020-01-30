/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 22:37:18 by thorker           #+#    #+#             */
/*   Updated: 2020/01/30 11:47:26 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "to_json.h"

/*
** Вспомогательная функция для нормы
*/

static void	*check_value2(t_token **token, t_type *type, void *new_value)
{
	if (ft_strcmp((*token)->value, "{") == 0)
	{
		if ((new_value = make_object(token)) != *token)
			*type = Object;
	}
	else if (ft_strcmp((*token)->value, "[") == 0)
	{
		if ((new_value = make_array(token)) != *token)
			*type = Array;
	}
	return (new_value);
}

/*
** Проверяет возможные типы переменных и вызывает соответсвующие функции
*/

void		*check_value(t_token **token, t_type *type)
{
	void	*new_value;

	new_value = 0;
	if (ft_str_isdigit((*token)->value) != 0)
	{
		if ((new_value = make_digit(token)) != 0)
			*type = Dec;
	}
	else if (ft_token_isstr(token) != 0)
	{
		if ((new_value = make_string((*token)->value)) == 0)
			return (0);
		*type = String;
		*token = (*token)->next->next;
	}
	else if (ft_str_isdouble((*token)->value) != 0)
	{
		printf("до мейк дабл: %s\n", (*token)->value);
		printf("atof: %f\n", atof((*token)->value)); 
		if ((new_value = make_double(token)) != 0)
			*type = Doub;
		printf("после make дабл: %f\n", *((double*)new_value));
	}
	else
		new_value = check_value2(token, type, new_value);
	return (new_value);
}
