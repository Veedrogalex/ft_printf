#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;

	s = (void *)malloc(size * count);
	if (s == NULL)
		return (NULL);
	ft_bzero(s, count * size);
	return (s);
}
