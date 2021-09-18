#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include <stdio.h>

typedef struct	s_parsf
{
	int			flagminus;
	int			flagzero;
	int			flaghash;
	int			flagspace;
	int			flagplus;
	int			flagwidth;
	int			width;
	int			flagaccuracy;
	int			accuracy;
	char		spec;
	int			nextsym;
	int			exist;
	int			spasebefore;
	int			spaseafter;
	int			numzero;
}				t_parsf;

char			*ft_itoa_d(long n);
int				ft_spam_for_num(int len, char sym);
int				for_parse_width(t_parsf *str, va_list parametr, int start_flag);
const char		*ft_parsewidth(const char *s, t_parsf *str, va_list parametr);
int				ft_conclusionbyparse(t_parsf *strf, va_list parametr);
int				no_spec(const char *s);
void			to_zero(t_parsf *strf, int *count);
char			*ft_itoa_hex(unsigned long long int p, int base, char c);
int				ft_putstr(char *s);
int				hexlenstr(unsigned long n, int base);
void			parsenumzero(t_parsf *strf, int minus, int lenstr);
void			parsespaft(t_parsf *strf, int minus, int lenstr);
void			parsespbef(t_parsf *strf, int minus, int lenstr);
void			*ft_memset(void *destination, int c, size_t amount);
int				spec_s(t_parsf *strf, va_list parametr);
int				spec_d(t_parsf *strf, va_list parametr);
int				spec_u(t_parsf *strf, va_list parametr);
int				spec_percent(t_parsf *strf);
int				spec_p(t_parsf *strf, va_list parametr);
int				spec_x(t_parsf *strf, va_list parametr);
int				spec_c(t_parsf *strf, va_list parametr);
void			ft_spam(int len, char sym);
const char		*ft_parsewidth(const char *s, t_parsf *strf, va_list parametr);
const char		*ft_parsespec(const char *s, t_parsf *strf);
const char		*ft_parseaccuracy(const char *s, t_parsf *strf,
					va_list parametr);
const char		*ft_parseflag(const char *s, t_parsf *strf);
int				ft_printf(const char *line, ...);

#endif
