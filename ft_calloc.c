/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeganov <abeganov@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 10:39:26 by abeganov          #+#    #+#             */
/*   Updated: 2025/10/28 16:30:31 by abeganov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*x;

	if (count == 0 || size == 0)
		return (NULL);
	x = (void *)malloc(count * size);
	if (!x)
		return (NULL);
	ft_bzero(x, count);
	return (x);
}
