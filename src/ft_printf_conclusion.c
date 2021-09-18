#include "libftprintf.h"

int			spec_c(t_parsf *strf, va_list parametr)
{
	char sym;

	sym = va_arg(parametr, int);
	if (strf->width && !strf->flagminus && !strf->flagzero)
		ft_spam(strf->width - 1, ' ');
	if (strf->width && strf->flagzero)
		ft_spam(strf->width - 1, '0');
	write(1, &sym, 1);
	if (strf->width && strf->flagminus)
		ft_spam(strf->width - 1, ' ');
	if (strf->width)
		return (strf->width);
	return (1);
}

int			spec_percent(t_parsf *strf)
{
	if (strf->width && !strf->flagminus && !strf->flagzero)
		ft_spam(strf->width - 1, ' ');
	if (strf->width && strf->flagzero)
		ft_spam(strf->width - 1, '0');
	write(1, "%", 1);
	if (strf->width && strf->flagminus)
		ft_spam(strf->width - 1, ' ');
	if (strf->width)
		return (strf->width);
	return (1);
}

int			spec_s(t_parsf *strf, va_list parametr)
{
	char	*s;
	int		len;

	s = va_arg(parametr, char*);
	if (s)
		len = ft_strlen(s);
	else
		len = 6;
	if (strf->flagaccuracy && strf->accuracy < len)
		len = strf->accuracy;
	if (strf->width && !strf->flagminus && !strf->flagzero && strf->width > len)
		ft_spam(strf->width - len, ' ');
	if (strf->width && strf->flagzero && strf->width > len)
		ft_spam(strf->width - len, '0');
	if (s)
		write(1, s, len);
	else
		write(1, "(null)", len);
	if (strf->width && strf->flagminus && strf->width > len)
		ft_spam(strf->width - len, ' ');
	if (strf->width > len)
		return (strf->width);
	else
		return (len);
}

int			spec_d(t_parsf *strf, va_list parametr)
{
	int						lenstr;
	char					*str;
	int						minus;
	long					n;
	int						len;

	len = 0;
	n = (long)va_arg(parametr, int);
	minus = (n < 0) ? -1 : 0;
	n = (n < 0) ? -n : n;
	str = ft_itoa(n);
	if (*str == '0' && strf->flagaccuracy && !strf->accuracy)
		*str = '\0';
	lenstr = ft_strlen(str);
	parsenumzero(strf, minus, lenstr);
	parsespaft(strf, minus, lenstr);
	parsespbef(strf, minus, lenstr);
	len += ft_spam_for_num(strf->spasebefore, ' ');
	minus == -1 ? write(1, "-", 1) : 0;
	len += ft_spam_for_num(strf->numzero, '0');
	len += ft_putstr(str);
	len += ft_spam_for_num(strf->spaseafter, ' ');
	free(str);
	lenstr = len - minus;
	return (lenstr);
}
