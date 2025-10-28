/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeganov <abeganov@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:33:20 by abeganov          #+#    #+#             */
/*   Updated: 2025/10/28 19:07:52 by abeganov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	get_positive_set_str(const int n, char *str)
{
	unsigned int	num;

	if (n < 0)
	{
		num = (unsigned int)(-(long)n);
		str[0] = '-';
	}
	else
		num = (unsigned int)n;
	return (num);
}

static unsigned int	get_length(int n)
{
	unsigned int	counter;
	unsigned int	num;

	counter = 0;
	if (n < 0)
	{
		num = (unsigned int)(-(long)n);
		counter++;
	}
	else
		num = n;
	while (num != 0)
	{
		num /= 10;
		counter++;
	}
	return (counter);
}

static char	get_last_char(unsigned int *pos)
{
	char	last;

	last = *pos % 10 + '0';
	*pos /= 10;
	return (last);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				i;
	unsigned int	length;
	unsigned int	positive;

	if (n == 0)
		return (ft_strdup("0"));
	length = get_length(n);
	str = (char *)ft_calloc(length + 1, sizeof(char));
	if (!str)
		return (NULL);
	positive = get_positive_set_str(n, str);
	i = length - 1;
	while (positive != 0 && i >= 0)
	{
		str[i] = get_last_char(&positive);
		i--;
	}
	return (str);
}
