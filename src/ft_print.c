/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deladia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 23:27:09 by deladia           #+#    #+#             */
/*   Updated: 2020/01/27 00:30:56 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "to_json.h"

/*
** функция для печати массива
*/

void		ft_print_array(t_array *array)
{
	size_t i;

	printf("[ ");
	i = 0;
	while (i < array->length)
	{
		if (array->type[i] == String)
		{
			printf("%s", array->value[i]);
		}
		else if (array->type[i] == Dec)
		{
			printf("%d",((int*)array->value[i])[0]);
		}
		else if (array->type[i] == Doub)
		{
			printf("%lf",((double*)array->value[i])[0]);
		}
		else if (array->type[i] == None)
		{
			printf("NULL");
		}
		else if (array->type[i] == Object)
		{
			printf("{");
			if (array->value[i] == 0)
				printf("NULL");
			else
				ft_print((t_key_value*)array->value[i]);
			printf("}");
		}
		else if (array->type[i] == Array)
		{
			ft_print_array((t_array*)array->value[i]);
		}
		i++;
		if (i != array->length)
			printf(", ");
	}
	printf(" ]");
}

/*
**	функция для печати всего массива
*/

void		ft_print(t_key_value *tree)
{
	int		i;

	i = 0;
	while (tree->key[i] != NULL)
	{
		if (tree->type[i] == String)
		{
			printf("key: %s\nvalue: %s\n", tree->key[i], tree->value[i]);
		}
		else if (tree->type[i] == Dec)
		{
			printf("key: %s\nvalue: %d\n", tree->key[i], ((int*)tree->value[i])[0]);
		}
		else if (tree->type[i] == Doub)
		{
			printf("key: %s\nvalue: %lf\n", tree->key[i], ((double*)tree->value[i])[0]);
		}
		else if (tree->type[i] == None)
		{
			printf("key: %s\nvalue: NULL\n", tree->key[i]);
		}
		else if (tree->type[i] == Object)
		{
			printf("key: %s\nvalue:{\n", tree->key[i]);
			if (tree->value[i] == 0)
				printf("NULL\n");
			else			
				ft_print((t_key_value*)tree->value[i]);
			printf("}\n");
		}
		else if (tree->type[i] == Array)
		{
			printf("key: %s\nvalue: ", tree->key[i]);
			ft_print_array((t_array*)tree->value[i]);
			printf("\n");
		}
		i++;
	}
}
