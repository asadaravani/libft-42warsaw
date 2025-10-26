/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeganov <abeganov@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 21:31:28 by abeganov          #+#    #+#             */
/*   Updated: 2025/10/26 23:10:34 by abeganov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
static size_t	word_counter(char const *s, char c)
{
	size_t	is_word_start;
	size_t	i;
	size_t	counter;

	is_word_start = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
			is_word_start = 1;
		if (s[i] == c && is_word_start == 1)
		{
			counter++;
			is_word_start = 0;
		}
	}
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
	char **arr = (char**)ft_calloc(word_counter(s, c) + 1, sizeof(char*));
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