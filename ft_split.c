/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeganov <abeganov@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 21:31:28 by abeganov          #+#    #+#             */
/*   Updated: 2025/10/27 19:06:23 by abeganov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
static size_t	*dyn_word_finder(char const *s, char c, size_t s_e[2])
{
	size_t	start;
	char	*end;

	start = s_e[0];
	s_e[0] = 0;
	s_e[1] = 0;
	while (s[start] == c)
		start++;
	end = ft_strchr(s + start, c);
	if (!end)
		return (s_e);
	s_e[0] = start;
	s_e[1] = end - s;
	return s_e;
}
static size_t	ft_word_counter(char const *s, char c)
{
	size_t	counter;
	size_t	s_e[2];

	counter = 0;
	while (dyn_word_finder(s, c, s_e) + 1 != 0)
		counter++;
	return (counter);
}
static void free_all(char **arr, size_t index)
{
	size_t	i;

	i = 0;
	while (i < index)
		free(arr[i++]);
	free(arr);
}
char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	is_word_start;
	size_t	word;
	size_t	start;
	char	*sub;

	if (!s || !c)
		return (NULL);
	char **arr = (char**)ft_calloc(ft_word_counter(s, c) + 1, sizeof(char*));
	if (!arr)
		return (NULL);
	i = 0;
	word = i;
	start = i;
	while (arr[word])
	{
		j = i + 1;
		while (s[j])
	}
	arr[word++] = ft_substr(s, start, i - start);
	arr[word] = NULL;
	return (arr);
}