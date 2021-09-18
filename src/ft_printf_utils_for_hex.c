#include "libftprintf.h"

int				normlenstr(unsigned long n, int base)
{
	int	lenstr;

	lenstr = 0;
	if (!n)
		return (1);
	while (n)
	{
		lenstr++;
		n /= base;
	}
	return (lenstr);
}

char			*ft_itoa_hex(unsigned long long int p, int base, char c)
{
	char					*s;
	int						i;
	unsigned long long int	n;
	int						k;

	n = (unsigned long long int)p;
	i = normlenstr(n, base);
	k = i;
	if (!(s = (char*)malloc(i + 1)))
		return (NULL);
	if (!n)
		s[0] = '0';
	while (n)
	{
		if (n % base > 9)
			s[--i] = n % base - 10 + c;
		else
			s[--i] = n % base + '0';
		n /= base;
	}
	s[k] = '\0';
	return (s);
}
