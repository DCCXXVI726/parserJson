/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_json.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 01:50:08 by thorker           #+#    #+#             */
/*   Updated: 2020/01/27 02:34:36 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TO_JSON_H
# define TO_JSON_H
# define WRONG_TYPE -1
# define NOT_FOUND -2
# define WRONG_CONTAINER -3
# define BROKEN_NODE -4
# define BROKEN_ARRAY -5
# define OUT_OF_RANGE -6
# include "libft.h"
# include <fcntl.h>

typedef enum			e_type
{
	Object = 1,
	Array,
	String,
	Dec,
	Doub,
	None
}						t_type;

typedef struct			s_array
{
	void				**value;
	t_type				*type;
	size_t				length;
}						t_array;

/*
** Структура для хранения массива триплетов: ключ , значение, тип.
*/

typedef struct			s_key_value
{
	char				**key;
	void				**value;
	t_type				*type;
}						t_key_value;

typedef struct			s_token
{
	char				*value;
	t_type				type;
	struct s_token		*next;
}						t_token;

int						getf_int_array(t_array *array,
		size_t item, int *number);
int						getf_double_array(t_array *array,
		size_t item, int *number);
int						getf_object_array(t_array *array,
		size_t item, t_key_value **object);
int						getf_array_array(t_array *array,
		size_t item, t_array **new_array);
int						getf_str_array(t_array *array, size_t item, char **str);
void					*check_value(t_token **token, t_type *type);
int						ft_token_isstr(t_token **token);
char					*make_string(char *str);
int						realloc_key_value(t_key_value *for_re, char *new_key,
		void *new_value, t_type new_type);
int						get_array(t_key_value *tree,
		char *name, t_array **array);
int						get_int(t_key_value *node, char	*name, int *container);
int						get_str(t_key_value *tree, char *name, char **str);
int						get_double(t_key_value *tree,
		char *name, double *number);
int						get_node(t_key_value *tree,
		char *name, t_key_value **object);
t_key_value				*parse_json(char *file_name);
t_token					*ft_open(char *file);
void					*make_object(t_token **token);
void					ft_return(t_key_value **tree);
void					ft_return_array(t_array **array, t_type type, void **v);
void					ft_print(t_key_value *tree);
t_token					*create_token(char *word, t_token *token);
void					ft_error(char *str);
void					*make_digit(t_token **token);
int						ft_str_isdigit(char *str);
int						ft_str_isdouble(char *str);
void					*make_double(t_token **token);
void					*make_array(t_token **token);
int						realloc_array(t_array *array,
		void *new_value, t_type new_type);
void					*ft_find(t_key_value *tree,
		char *name, t_type type, int *error);
void					*find_in_array(t_array *array,
		size_t item, t_type type, int *error);
int						check_null_object(t_token **tiken);
#endif
