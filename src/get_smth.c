/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_smth.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deladia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:32:42 by deladia           #+#    #+#             */
/*   Updated: 2020/02/01 05:47:54 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "to_json.h"

/*
** Находит по name пару и кладет в контейнер number целое число
*/

int		get_int(t_key_value *tree, char *name, int *number)
{
	int		error;
	void	*container;

	error = 0;
	if (number == NULL)
		return (WRONG_CONTAINER);
	container = ft_find(tree, name, Dec, &error);
	if (error == 0)
		*number = *((int*)container);
	return (error);
}

/*
** Находит по name пару и кладет в контейнер object ссылку на объект
*/

int		get_node(t_key_value *tree, char *name, t_key_value **object)
{
	int		error;
	void	*container;

	error = 0;
	if (object == NULL)
		return (WRONG_CONTAINER);
	container = ft_find(tree, name, Object, &error);
	if (error == 0)
		*object = (t_key_value*)container;
	return (error);
}

/*
** Находит по name пару и кладет в контейнер number вещественное число
*/

int		get_double(t_key_value *tree, char *name, double *number)
{
	int		error;
	void	*container;

	error = 0;
	if (number == NULL)
		return (WRONG_CONTAINER);
	container = ft_find(tree, name, Doub, &error);
	if (error == 0)
		*number = *((double*)container);
	return (error);
}

/*
** Находит по name пару и кладет в контейнер str копию строки
*/

int		get_str(t_key_value *tree, char *name, char **str)
{
	int		error;
	void	*container;

	error = 0;
	if (str == NULL)
		return (WRONG_CONTAINER);
	container = ft_find(tree, name, String, &error);
	if (error == 0)
		*str = ft_strdup(container);
	return (error);
}

/*
** Находит по name пару и кладет в контейнер array ссылку на массив
*/

int		get_array(t_key_value *tree, char *name, t_array **array)
{
	int		error;
	void	*container;

	error = 0;
	if (array == NULL)
		return (WRONG_CONTAINER);
	container = ft_find(tree, name, Array, &error);
	if (error == 0)
		*array = (t_array*)container;
	return (error);
}
