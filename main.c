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
	t_array		*array;
	t_key_value *node;
	double		b;
	int error;
//	tmp = parse_json("../../../param.json");
	if ((tmp = parse_json("test.json")) == 0)
		exit(0);
	error = get_node(tmp, "light_1", &node);
	error = get_array(node, "position", &array);
	error = getf_double_array(array, 0, &b);
	printf("вот тот double %lf\n",b);
	// t_key_value *node;
//	double		b;
	// int error;
	// char *str;

//	tmp = parse_json("../../../param.json");
	tmp = parse_json("test.json");
	//printf("вот тот double %lf\n",b);
	// printf("str = %s\n", str);
	//ft_print(tmp);
	/*
	char *line = 0;
	size_t k = read(0, line, 3);
	(void)k;
	*/
	//ft_return(&tmp);
	return (0);
}
