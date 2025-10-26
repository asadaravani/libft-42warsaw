
#include "libft.h"

void    *ft_calloc(size_t count, size_t size)
{
	void	*x;

	x = (void*)malloc(count * size);
	if (!x)
		return (NULL);
	ft_bzero(x, count);
	return (x);
}