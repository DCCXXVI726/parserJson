/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 21:11:44 by thorker           #+#    #+#             */
/*   Updated: 2020/01/27 02:09:41 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "to_json.h"

/*
** Поиск и проверка типа пары значения по имени в объекте
*/

void	*ft_find(t_key_value *tree, char *name, t_type type, int *error)
{
	int	i;

	i = 0;
	if (tree == 0 || tree->key == 0 || tree->value == 0 || tree->type == 0 ||
			name == 0)
	{
		*error = BROKEN_NODE;
		return (0);
	}
	while (tree->key[i])
	{
		if (ft_strcmp(tree->key[i], name) == 0)
		{
			if (tree->type[i] == type || type == 0)
				return (tree->value[i]);
			else
			{
				*error = WRONG_TYPE;
				return (0);
			}
		}
		i++;
	}
	*error = (NOT_FOUND);
	return (0);
}

/*
** Поиск и проверка типа значения по номеру в массиве
*/

void	*find_in_array(t_array *array, size_t item, t_type type, int *error)
{
	if (array == 0)
	{
		*error = BROKEN_ARRAY;
		return (0);
	}
	if (item >= array->length)
	{
		*error = OUT_OF_RANGE;
		return (0);
	}
	if (type != 0 && array->type[item] != type)
	{
		*error = WRONG_TYPE;
		return (0);
	}
	return (array->value[item]);
}

/*
**	Функция для проверки пустого объекта
*/

int		check_null_object(t_token **token)
{
	if ((*token)->next != 0 && ft_strcmp((*token)->next->value, "}") == 0)
	{
		*token = ((*token)->next->next);
		return (0);
	}
	return (1);
}
