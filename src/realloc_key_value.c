/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_key_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 17:14:59 by thorker           #+#    #+#             */
/*   Updated: 2020/01/31 07:16:42 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "to_json.h"

/*
** Замена старых массивов на новые
*/

static void		ft_free(t_key_value *for_re,
		char **new_key_array,
		void **new_value_array,
		t_type *new_type_array)
{
	free(for_re->key);
	free(for_re->value);
	if (for_re->type != 0)
		free(for_re->type);
	for_re->key = new_key_array;
	for_re->value = new_value_array;
	for_re->type = new_type_array;
}

/*
** выделение памяти, проверка маллоко, копирование данных в новые массивы
*/

static int		realloc_struct(t_key_value *for_re, size_t i)
{
	char	**new_key_array;
	void	**new_value_array;
	t_type	*new_type_array;

	if ((new_key_array = (char**)malloc(sizeof(char*) * (i + 2))) == 0 |
			(new_value_array = (void**)malloc(sizeof(void*) * (i + 1))) == 0 |
			(new_type_array = (t_type*)malloc(sizeof(t_type) * (i + 1))) == 0)
	{
		if (new_key_array != 0)
			free(new_key_array);
		if (new_value_array != 0)
			free(new_value_array);
		if (new_type_array != 0)
			free(new_type_array);
		return (0);
	}
	while (i-- != 0)
	{
		*(new_key_array + i) = *(for_re->key + i);
		*(new_value_array + i) = *(for_re->value + i);
		*(new_type_array + i) = *(for_re->type + i);
	}
	ft_free(for_re, new_key_array, new_value_array, new_type_array);
	return (1);
}

/*
** функция в которой выделяется новая память для расширенного массива
*/

int				realloc_key_value(t_key_value *for_re,
		char *new_key,
		void *new_value,
		t_type new_type)
{
	size_t	i;

	i = 0;
	while (*(for_re->key + i) != 0)
		i++;
	if (realloc_struct(for_re, i) == 0)
		return (0);
	*(for_re->key + i) = new_key;
	*(for_re->key + i + 1) = 0;
	*(for_re->value + i) = new_value;
	*(for_re->type + i) = new_type;
	return (1);
}

/*
** Копирование старых объектов в новый массив
*/

static void		cpy_array(t_array *array,
		void **new_array_value,
		t_type *new_array_type)
{
	size_t	i;

	i = 0;
	while (i < array->length)
	{
		new_array_value[i] = array->value[i];
		new_array_type[i] = array->type[i];
		i++;
	}
	if (array->length != 0)
	{
		free(array->value);
		free(array->type);
	}
}

/*
** Перевыделение памяти и добавление нового элемента в массив
*/

int				realloc_array(t_array *array, void *new_value, t_type new_type)
{
	void	**new_array_value;
	t_type	*new_array_type;

	if ((new_array_value =
				(void**)malloc(sizeof(void*) * (array->length + 1))) == 0 |
			(new_array_type =
			(t_type*)malloc(sizeof(t_type) * (array->length + 1))) == 0)
	{
		if (new_array_value != 0)
			free(new_array_value);
		if (new_array_type != 0)
			free(new_array_type);
		return (0);
	}
	cpy_array(array, new_array_value, new_array_type);
	new_array_value[array->length] = new_value;
	new_array_type[array->length] = new_type;
	array->value = new_array_value;
	array->type = new_array_type;
	array->length = array->length + 1;
	return (1);
}
