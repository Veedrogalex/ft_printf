#include "libftprintf.h"

int				ft_spam_for_num(int len, char sym)
{
	int		newlen;

	newlen = 0;
	if (len < 1)
		return (0);
	while (len)
	{
		newlen++;
		write(1, &sym, 1);
		--len;
	}
	return (newlen);
}

void			ft_spam(int len, char sym)
{
	if (len < 1)
		return ;
	while (len)
	{
		write(1, &sym, 1);
		--len;
	}
}

void			*ft_memset(void *destination, int c, size_t amount)
{
	unsigned char	*start;
	size_t			i;

	start = (unsigned char	*)destination;
	i = 0;
	while (i < amount)
		start[i++] = (unsigned char)c;
	return (start);
}

int				ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}
