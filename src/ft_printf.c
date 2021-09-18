#include "libftprintf.h"
#include <stdio.h>

static int	sf_fullpars(const char *line, t_parsf *strf, va_list parametr)
{
	const char	*src;

	src = line;
	line = ft_parseflag(line, strf);
	line = ft_parsewidth(line, strf, parametr);
	line = ft_parseaccuracy(line, strf, parametr);
	line = ft_parsespec(line, strf);
	return (line - src);
}

void		to_zero(t_parsf *strf, int *count)
{
	ft_bzero(strf, sizeof(*strf));
	*count = 0;
}

int			nospec(const char *s)
{
	int		len;
	char	*elem;

	elem = ft_strchr(s, '%');
	if (elem)
		len = elem - s;
	else
		len = ft_strlen(s);
	write(1, s, len);
	return (len);
}

int			ft_conclusionbyparse(t_parsf *strf, va_list parametr)
{
	if (strf->spec == 'c')
		return (spec_c(strf, parametr));
	if (strf->spec == 's')
		return (spec_s(strf, parametr));
	if (strf->spec == 'p')
		return (spec_p(strf, parametr));
	if (strf->spec == 'd')
		return (spec_d(strf, parametr));
	if (strf->spec == 'u')
		return (spec_u(strf, parametr));
	if (strf->spec == 'x')
		return (spec_x(strf, parametr));
	if (strf->spec == 'X')
		return (spec_x(strf, parametr));
	if (strf->spec == '%')
		return (spec_percent(strf));
	return (1);
}

int			ft_printf(const char *line, ...)
{
	va_list	parametr;
	t_parsf	strf;
	int		count;
	int		nspc;

	to_zero(&strf, &count);
	va_start(parametr, line);
	while (*line)
	{
		if (*line == '%')
		{
			line += sf_fullpars(line + 1, &strf, parametr) + 1;
			if (strf.exist)
				count += ft_conclusionbyparse(&strf, parametr);
			ft_bzero(&strf, sizeof(strf));
		}
		else
		{
			nspc = nospec(line);
			line += nspc;
			count += nspc;
		}
	}
	va_end(parametr);
	return (count);
}
