/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_smth.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 22:52:36 by thorker           #+#    #+#             */
/*   Updated: 2020/01/31 08:12:38 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "to_json.h"

/*
** проверяет является ли строка числом
*/

int			ft_str_isdigit(char *str)
{
	size_t	i;
	int		sign;

	sign = 0;
	if (str == 0)
		return (0);
	i = 0;
	while (*(str + i) != 0)
	{
		if (*(str + i) == '-' && i == 0)
			sign = -1;
		else if (*(str + i) == '+' && i == 0)
			sign = 1;
		else if (ft_isdigit(*(str + i)) == 0)
			return (0);
		i++;
	}
	if (i == 0 || (sign != 0 && i == 1))
		return (0);
	return (1);
}

/*
**	вспомагательная функция для проверки + и - в double
*/

static void	check_plus_minus(char **str)
{
	if (**str == '-' || **str == '+')
		*str = *str + 1;
}

/*
** проверяет является ли строка double
*/

int			ft_str_isdouble(char *str)
{
	size_t	i;
	int		flag;

	if (str == 0)
		return (0);
	i = 0;
	flag = 0;
	check_plus_minus(&str);
	while (*(str + i) != 0)
	{
		if (ft_isdigit(*(str + i)) == 0)
		{
			if (*(str + i) == '.' && flag == 0)
				flag = 1;
			else
				return (0);
		}
		i++;
	}
	if (i == 0 || (flag == 1 && i == 1))
		return (0);
	return (1);
}

/*
** Проверяет последовательность токенов на синтаксис строки
*/

int			ft_token_isstr(t_token **token)
{
	if (ft_strcmp((*token)->value, "\"") != 0 ||
			(*token = (*token)->next) == 0 ||
			(*token)->next == 0 ||
			ft_strcmp((*token)->next->value, "\"") != 0)
		return (0);
	return (1);
}
