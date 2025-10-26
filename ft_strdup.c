/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeganov <abeganov@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 11:12:46 by abeganov          #+#    #+#             */
/*   Updated: 2025/10/26 20:00:45 by abeganov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	sz;

	if (!s)
		return (NULL);
	sz = ft_strlen(s) + 1;
	str = (char *)ft_calloc(sz, sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s, sz);
	return (str);
}
