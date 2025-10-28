/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeganov <abeganov@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 12:09:25 by abeganov          #+#    #+#             */
/*   Updated: 2025/10/28 15:58:47 by abeganov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	copy_len;
	char	*ptr;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	copy_len = 0;
	while (s[start + copy_len] && copy_len < len)
		copy_len++;
	ptr = (char *)ft_calloc(copy_len +1, sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < copy_len)
	{
		ptr[i] = s[i + start];
		i++;
	}
	return (ptr);
}
