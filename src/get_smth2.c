/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_smth2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 21:17:29 by thorker           #+#    #+#             */
/*   Updated: 2020/01/31 04:29:42 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "to_json.h"

/*
** Находит значение в массиве по номеру "item"
** и кладет в контейнер "number" целое число
*/

int		getf_int_array(t_array *array, size_t item, int *number)
{
	void	*container;
	int		error;

	if (number == 0)
		return (WRONG_CONTAINER);
	error = 0;
	container = find_in_array(array, item, Dec, &error);
	if (error == 0)
		*number = *((int*)container);
	return (error);
}

/*
** Находит значение в массиве по номеру "item"
** и кладет в контейнер "number" вещественное число
*/

int		getf_double_array(t_array *array, size_t item, double *number)
{
	void	*container;
	int		error;

	if (number == 0)
		return (WRONG_CONTAINER);
	error = 0;
	container = find_in_array(array, item, Doub, &error);
	if (error == 0)
		*number = *((double*)container);
	return (error);
}

/*
** Находит значение в массиве по номеру "item"
** и кладет в контейнер "object" ссылку на объект.
*/

int		getf_object_array(t_array *array, size_t item, t_key_value **object)
{
	void	*container;
	int		error;

	if (object == 0)
		return (WRONG_CONTAINER);
	error = 0;
	container = find_in_array(array, item, Object, &error);
	if (error == 0)
		*object = (t_key_value*)container;
	return (error);
}

/*
** Находит значение в массиве по номеру "item"
** и кладет в контейнер "new_array" ссылку на массив
*/

int		getf_array_array(t_array *array, size_t item, t_array **new_array)
{
	void	*container;
	int		error;

	if (new_array == 0)
		return (WRONG_CONTAINER);
	error = 0;
	container = find_in_array(array, item, Array, &error);
	if (error == 0)
		*new_array = (t_array*)container;
	return (error);
}

/*
** Находит значение в массиве по номеру "item"
** и кладет в контейнер "str" копию строки
*/

int		getf_str_array(t_array *array, size_t item, char **str)
{
	void	*container;
	int		error;

	if (str == 0)
		return (WRONG_CONTAINER);
	error = 0;
	container = find_in_array(array, item, String, &error);
	if (error == 0)
		ft_strcpy(*str, container);
	return (error);
}
