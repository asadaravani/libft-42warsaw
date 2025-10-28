/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeganov <abeganov@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 21:31:28 by abeganov          #+#    #+#             */
/*   Updated: 2025/10/28 17:19:52 by abeganov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_all(char **arr, size_t index)
{
	size_t	i;

	i = 0;
	while (i <= index)
		free(arr[i++]);
	free(arr);
	return (NULL);
}

static size_t	*dyn_word_finder(char const *s, char c, size_t s_e[2])
{
	size_t	start;
	char	*end;

	if (c == '\0')
	{
		s_e[1] = ft_strlen(s);
		return (s_e);
	}
	start = s_e[0];
	while (s[start] == c)
		start++;
	if (!s[start])
	{
		s_e[0] = 0;
		s_e[1] = 0;
		return (s_e);
	}
	end = ft_strchr(s + start, c);
	if (!end)
		end = (char *)(s + ft_strlen(s));
	s_e[0] = start;
	s_e[1] = end - s;
	return (s_e);
}

static size_t	ft_word_counter(char const *s, char c)
{
	size_t	counter;
	size_t	s_e[2];
	size_t	*res;

	counter = 0;
	s_e[0] = 0;
	s_e[1] = 0;
	while (1)
	{
		res = dyn_word_finder(s, c, s_e);
		if (res[1] == 0 && res[0] == 0)
			break ;
		counter++;
		s_e[0] = res[1] + 1;
		if (res[1] == ft_strlen(s))
			break ;
	}
	return (counter);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	s_e[2];
	size_t	*res;
	size_t	words;
	char	**arr;

	if (!s)
		return (NULL);
	words = ft_word_counter(s, c);
	arr = (char **)ft_calloc(words + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	i = 0;
	s_e[0] = 0;
	while (i < words)
	{
		res = dyn_word_finder(s, c, s_e);
		arr[i] = ft_substr(s, res[0], res[1] - res[0]);
		if (!arr[i])
			return (free_all(arr, i));
		s_e[0] = res[1] + 1;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
