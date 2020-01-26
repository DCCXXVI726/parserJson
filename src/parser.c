/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deladia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 20:44:57 by deladia           #+#    #+#             */
/*   Updated: 2020/01/27 00:05:05 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "to_json.h"

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
		ft_error("Memory not allocated (for word)");
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
		word = create_word(&line);
		token = create_token(word, token);
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
	char			*line;
	t_token			*token_head;
	t_token			*token_tmp;

	if ((fd = open(file, O_RDONLY)) < 0)
		ft_error("Can't open file!");
	if (!(token_head = (t_token *)ft_memalloc(sizeof(t_token))))
		ft_error("Memory not allocated (for token)");
	token_tmp = token_head;
	while (get_next_line(fd, &line) > 0)
	{
		token_tmp = parse(line, token_tmp);
		free(line);
	}
	close(fd);
	return (token_head);
}
