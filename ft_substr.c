/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeganov <abeganov@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 12:09:25 by abeganov          #+#    #+#             */
/*   Updated: 2025/10/26 20:01:09 by abeganov         ###   ########.fr       */
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
	i = ft_strlen(s) - start;
	while (i < len && s[i + start])
		i++;
	copy_len = i;
	ptr = (char *)ft_calloc(copy_len +1, sizeof(*s));
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
