/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeganov <abeganov@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 13:22:30 by abeganov          #+#    #+#             */
/*   Updated: 2025/10/26 20:56:39 by abeganov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	size_t	s1_len;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	s1_len = ft_strlen(s1);
	end = s1_len - 1;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	if (start >= end)
		return (ft_strdup(""));
	len = end - start + 1;
	return (ft_substr(s1, start, len));
}
