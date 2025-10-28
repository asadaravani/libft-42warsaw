/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeganov <abeganov@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 10:56:41 by abeganov          #+#    #+#             */
/*   Updated: 2025/10/28 16:29:16 by abeganov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Sets a block of memory to zero (like memset with 0)
void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*p;

	if (!s)
		return ;
	p = s;
	i = 0;
	while (i < n)
		p[i++] = '\0';
}
