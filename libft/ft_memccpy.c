#include "libft.h"

void				*ft_memccpy(void *dst, void *src, int c, size_t n)
{
	unsigned char	symbol;
	unsigned char	*dst1;
	unsigned char	*src1;
	size_t			i;

	dst1 = dst;
	src1 = (unsigned char *)src;
	symbol = (unsigned char)c;
	i = 0;
	if (!src && !dst)
		return (0);
	while (i < n)
	{
		dst1[i] = src1[i];
		if (dst1[i] == symbol)
			return ((char *)dst + i + 1);
		i++;
	}
	return (0);
}
