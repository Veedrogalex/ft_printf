#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	symbol;
	size_t			i;

	i = 0;
	symbol = (unsigned char)c;
	str = (unsigned char *)s;
	while (i != n)
	{
		if (*str == symbol)
			return (str);
		str++;
		i++;
	}
	return (NULL);
}
