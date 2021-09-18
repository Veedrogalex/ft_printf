#include "libftprintf.h"

int			spec_x(t_parsf *strf, va_list parametr)
{
	unsigned long long int	x;
	char					*str;
	int						lenstr;
	int						len;

	len = 0;
	x = va_arg(parametr, unsigned int);
	if (strf->spec == 'X')
		str = ft_itoa_hex(x, 16, 'A');
	if (strf->spec == 'x')
		str = ft_itoa_hex(x, 16, 'a');
	if (*str == '0' && strf->flagaccuracy && !strf->accuracy)
		*str = '\0';
	lenstr = ft_strlen(str);
	parsenumzero(strf, 0, lenstr);
	parsespaft(strf, 0, lenstr);
	parsespbef(strf, 0, lenstr);
	len += ft_spam_for_num(strf->spasebefore, ' ');
	len += ft_spam_for_num(strf->numzero, '0');
	len += ft_putstr(str);
	len += ft_spam_for_num(strf->spaseafter, ' ');
	free(str);
	lenstr = len;
	return (lenstr);
}

int			spec_u(t_parsf *strf, va_list parametr)
{
	long					u;
	char					*str;
	int						lenstr;
	int						len;

	len = 0;
	u = va_arg(parametr, unsigned int);
	str = ft_itoa(u);
	if (*str == '0' && strf->flagaccuracy && !strf->accuracy)
		*str = '\0';
	lenstr = ft_strlen(str);
	parsenumzero(strf, 0, lenstr);
	parsespaft(strf, 0, lenstr);
	parsespbef(strf, 0, lenstr);
	len += ft_spam_for_num(strf->spasebefore, ' ');
	len += ft_spam_for_num(strf->numzero, '0');
	len += ft_putstr(str);
	len += ft_spam_for_num(strf->spaseafter, ' ');
	free(str);
	lenstr = len;
	return (lenstr);
}

int			spec_p(t_parsf *strf, va_list parametr)
{
	unsigned long long int	p;
	char					*str;
	int						lenstr;
	int						len;

	len = 2;
	p = va_arg(parametr, unsigned long long int);
	str = ft_itoa_hex(p, 16, 'a');
	if (*str == '0' && strf->flagaccuracy && !strf->accuracy)
		*str = '\0';
	lenstr = ft_strlen(str) + 2;
	parsenumzero(strf, 0, lenstr);
	parsespaft(strf, 0, lenstr);
	parsespbef(strf, 0, lenstr);
	len += ft_spam_for_num(strf->spasebefore, ' ');
	write(1, "0x", 2);
	len += ft_spam_for_num(strf->numzero, '0');
	len += ft_putstr(str);
	len += ft_spam_for_num(strf->spaseafter, ' ');
	free(str);
	lenstr = len;
	return (lenstr);
}
