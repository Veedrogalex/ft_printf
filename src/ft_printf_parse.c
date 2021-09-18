#include "libftprintf.h"

const char	*ft_parseflag(const char *s, t_parsf *strf)
{
	while (*s && ft_strchr(("-0# +"), *s))
	{
		if (*s == '-')
			strf->flagminus = 1;
		else if (*s == '0')
			strf->flagzero = 1;
		else if (*s == ' ')
			strf->flagspace = 1;
		else if (*s == '#')
			strf->flaghash = 1;
		else if (*s == '+')
			strf->flagplus = 1;
		++s;
	}
	if (strf->flagminus)
		strf->flagzero = 0;
	return (s);
}

const char	*ft_parseaccuracy(const char *s, t_parsf *strf, va_list parametr)
{
	int		del_arg;

	if (*s == '.')
	{
		strf->flagaccuracy = 1;
		++s;
	}
	while (*s >= '0' && *s <= '9' && strf->flagaccuracy)
	{
		if (!(strf->accuracy))
			strf->accuracy = ft_atoi(s);
		++s;
	}
	if (*s == '*' && strf->flagaccuracy)
	{
		if (!strf->accuracy)
			strf->accuracy = va_arg(parametr, int);
		else
			del_arg = va_arg(parametr, int);
		if (strf->accuracy < 0)
			strf->flagaccuracy = 0;
		++s;
	}
	return (s);
}

const char	*ft_parsespec(const char *s, t_parsf *strf)
{
	if (*s && (ft_strchr("cspduxX%", *s) || *s == 'i'))
	{
		strf->spec = *s;
		if (*s == 'i')
			strf->spec = 'd';
		strf->exist = 1;
		++s;
	}
	return (s);
}

int			for_parsewidth(t_parsf *str, va_list parametr, int flag)
{
	int del_arg;

	if (!str->width || !flag)
	{
		str->width = va_arg(parametr, int);
		if (str->width < 0)
		{
			str->width = -str->width;
			str->flagminus = 1;
			str->flagzero = 0;
		}
		return (1);
	}
	else
	{
		del_arg = va_arg(parametr, int);
		return (flag);
	}
}

const char	*ft_parsewidth(const char *s, t_parsf *str, va_list parametr)
{
	int	flag;

	flag = 0;
	if (*s == '*')
	{
		flag = for_parsewidth(str, parametr, flag);
		++s;
	}
	while (*s >= '0' && *s <= '9')
	{
		if (!(str->width) || flag)
			str->width = ft_atoi(s);
		++s;
	}
	if (*s == '*')
	{
		flag = for_parsewidth(str, parametr, flag);
		++s;
	}
	return (s);
}
