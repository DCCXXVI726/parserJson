/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deladia <deladia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 22:54:41 by deladia           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/01/31 08:10:31 by thorker          ###   ########.fr       */
=======
/*   Updated: 2020/01/31 10:06:04 by deladia          ###   ########.fr       */
>>>>>>> 9ca3350fa0f8572f51d086103be29043a4402363
/*                                                                            */
/* ************************************************************************** */

#include "to_json.h"

void	free_token(t_token **token)
{
	t_token		*tmp;

	tmp = *token;
	while(tmp)
	{
		*token = tmp;
		if (tmp->next)
			tmp = tmp->next;
		free((*token)->value);
		free(token);
	}
}

int		main(void)
{
	t_key_value	*tmp;
<<<<<<< HEAD
	t_array		*array;
	t_key_value *node;
	double		b;
	int error;
//	tmp = parse_json("../../../param.json");
	tmp = parse_json("test.json");
	error = get_node(tmp, "light_1", &node);
	error = get_array(node, "position", &array);
	error = getf_double_array(array, 0, &b);
	printf("вот тот double %lf\n",b);
=======
	// t_key_value *node;
//	double		b;
	// int error;
	// char *str;

//	tmp = parse_json("../../../param.json");
	tmp = parse_json("test.json");
	//printf("вот тот double %lf\n",b);
	// printf("str = %s\n", str);
>>>>>>> 9ca3350fa0f8572f51d086103be29043a4402363
	//ft_print(tmp);
	/*
	char *line = 0;
	size_t k = read(0, line, 3);
	(void)k;
	*/
	ft_return(&tmp);
	return (0);
}
