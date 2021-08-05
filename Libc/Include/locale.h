#ifndef LOCALE_H
#define LOCALE_H

#ifdef __cplusplus
extern "C"
{
#endif

#define LC_ALL 0x0
#define LC_COLLATE 0x1
#define LC_CTYPE 0x2
#define LC_MONETARY 0x3
#define LC_NUMERIC 0x4
#define LC_TIME 0x5

typedef struct
{
	char *decimal_point;
	char *thousands_sep;
	char *grouping;
	char *int_curr_symbol;
	char *currency_symbol;
	char *mon_decimal_point;
	char *mon_thousands_sep;
	char *mon_grouping;
	char *positive_sign;
	char *negative_sign;
	char int_frac_digits;
	char frac_digits;
	char p_cs_precedes;
	char p_sep_by_space;
	char n_cs_precedes;
	char n_sep_by_space;
	char p_sign_posn;
	char n_sign_posn;
} lconv;

static lconv currloc;

char *setlocale(int category, const char *locale);
struct lconv *localeconv(void);

#ifdef __cplusplus
}
#endif

#endif // LOCALE_H
