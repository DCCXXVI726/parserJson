/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deladia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 21:54:38 by deladia           #+#    #+#             */
/*   Updated: 2020/02/02 07:44:48 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "to_json.h"

/*
**	Чистит всю структуру массива
*/

void	ft_return_array(t_array **array, t_type type, void **value)
{
	size_t	i;

	if (array == 0 || *array == 0)
		return ;
	i = (*array)->length;
	while (i-- > 0)
	{
		if ((*array)->value[i] == NULL)
			continue ;
		if ((*array)->type[i] == Object)
			ft_return((t_key_value**)((*array)->value + i));
		else if ((*array)->type[i] == Array)
			ft_return_array((t_array**)((*array)->value + i), 0, 0);
		else
			ft_memdel((*array)->value + i);
	}
	if ((*array)->length != 0)
	{
		free((*array)->value);
		free((*array)->type);
	}
	if (type != 0)
		ft_memdel(value);
	ft_memdel((void**)array);
}

/*
** Функция для чистки всей структуры в случе ошибки
*/

void	ft_return(t_key_value **tree)
{
	int		i;

	if (tree == 0 || *tree == 0 || (i = 0))
		return ;
	while ((*tree)->key[i])
	{
		ft_strdel((*tree)->key + i++);
	}
	free((*tree)->key);
	while (--i >= 0)
	{
		if ((*tree)->value[i] == NULL)
			continue ;
		if ((*tree)->type[i] == Object)
			ft_return((t_key_value**)((*tree)->value + i));
		else if ((*tree)->type[i] == Array)
			ft_return_array((t_array**)((*tree)->value + i), 0, 0);
		else
			free((*tree)->value[i]);
		*((*tree)->value + i) = 0;
	}
	ft_memdel((void**)&((*tree)->value));
	ft_memdel((void**)&((*tree)->type));
	ft_memdel((void**)tree);
}

/*
** добавить чистку маcсива когда она будет
*/
