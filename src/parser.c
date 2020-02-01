/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deladia <deladia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 20:44:57 by deladia           #+#    #+#             */
/*   Updated: 2020/02/01 13:51:37 by deladia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "to_json.h"

int			ft_free_token(t_token **head_token)
{
	t_token *tmp;

	while (*head_token != 0)
	{
		tmp = (*head_token)->next;
		if ((*head_token)->value != 0)
			ft_strdel(&((*head_token)->value));
		ft_memdel((void**)head_token);
		*head_token = tmp;
	}
	return (0);
}

int			word_len(char *line)
{
	int		len;

	len = 0;
	while (line[len] != '\0' && line[len] != ' ' && line[len] != '\t')
	{
		len++;
		if (line[len - 1] == '{')
			return (len == 1 ? len : len - 1);
		else if (line[len - 1] == '}')
			return (len == 1 ? len : len - 1);
		else if (line[len - 1] == '"')
			return (len == 1 ? len : len - 1);
		else if (line[len - 1] == ',')
			return (len == 1 ? len : len - 1);
		else if (line[len - 1] == ':')
			return (len == 1 ? len : len - 1);
		else if (line[len - 1] == '[')
			return (len == 1 ? len : len - 1);
		else if (line[len - 1] == ']')
			return (len == 1 ? len : len - 1);
		else if (line[len - 1] == '\\' && line[len] == '\"')
			len += 1;
	}
	return (len);
}

char		*create_word(char **line)
{
	char	*word;
	int		i;
	int		len;

	i = 0;
	while (**line == ' ' || **line == '\t')
		(*line)++;
	len = word_len(*line);
	if (!(word = (char *)ft_memalloc(sizeof(char) * len + 1)))
		return (NULL);
	while (len-- > 0)
	{
		word[i] = **line;
		i++;
		(*line)++;
	}
	word[i] = '\0';
	return (word);
}

/*
** 		Парсит line по ключевым словам и кладет в односвязный список token
** 		возвращает указатель на последний добавленный token
*/

t_token		*parse(char *line, t_token *token)
{
	char	*word;

	while (*line != '\0')
	{
		if ((word = create_word(&line)) == NULL)
			return (NULL);
		if ((token = create_token(word, token)) == NULL)
		{
			free(word);
			return (NULL);
		}
		free(word);
	}
	return (token);
}

/*
** 		Открывает json создает указатель на первый токен token_head
** 		Читает гнлом построчно и каждую строку сразу отправляет в parse
** 		Затем вызывает проверку на валидность последовательности токенов
*/

t_token		*ft_open(char *file)
{
	ssize_t			fd;
	t_token			*token_head;

	if ((fd = open(file, O_RDONLY)) < 0)
		return (NULL);
	if (!(token_head = (t_token *)ft_memalloc(sizeof(t_token))))
	{
		close(fd);
		return (NULL);
	}
	if (ft_gnl(fd, &token_head) == 0)
		return (0);
	close(fd);
	if (token_head->value == 0)
	{
		ft_memdel((void**)&token_head);
		return (0);
	}
	return (token_head);
}
