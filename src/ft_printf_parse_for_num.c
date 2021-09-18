#include "libftprintf.h"

void			parsespbef(t_parsf *strf, int minus, int lenstr)
{
	if (!strf->flagzero && !strf->flagminus)
	{
		if (strf->width > strf->accuracy && strf->accuracy >= lenstr)
			strf->spasebefore = strf->width - strf->accuracy + minus;
		if (strf->width > lenstr && strf->accuracy <= lenstr)
			strf->spasebefore = strf->width - lenstr + minus;
	}
}

void			parsespaft(t_parsf *strf, int minus, int lenstr)
{
	if (strf->flagminus)
	{
		if (strf->width > strf->accuracy && strf->accuracy >= lenstr)
			strf->spaseafter = strf->width - strf->accuracy + minus;
		if (strf->width > lenstr && strf->accuracy <= lenstr)
			strf->spaseafter = strf->width - lenstr + minus;
	}
}

void			parsenumzero(t_parsf *strf, int minus, int lenstr)
{
	if (strf->flagaccuracy)
		strf->flagzero = 0;
	if (strf->flagzero && !strf->flagminus)
	{
		if (strf->width > strf->accuracy && strf->accuracy >= lenstr)
			strf->numzero = strf->width - strf->accuracy + minus;
		if (strf->width > lenstr && strf->accuracy <= lenstr)
			strf->numzero = strf->width - lenstr + minus;
	}
	if (strf->accuracy > lenstr)
		strf->numzero += strf->accuracy - lenstr;
}
