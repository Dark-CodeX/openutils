#include "../sstring/sstring.h"

/** KIND OF TUPLE */
struct coefficient
{
	long double X;
	long double X2;
	long double C;
};

/** KIND OF TUPLE */
struct sol
{
	long double X;
	long double Y;
	short is_complex;
	long double complex_X;
	long double complex_Y;
};

int isDigit(char c);
int isDigit(char c)
{
	if ((c >= 48 && c <= 57) || c == 46)
		return true;
	return false;
}

int format_eq(sstring *e);
int format_eq(sstring *e)
{
	if (e && e->str.src && e->str.init == true)
	{
		e->remove_char(e, ' ');
		short valid = false;
		for (size_t i = 0; e->str.src[i] != '\0'; i++)
		{
			switch (e->str.src[i])
			{
			case 'x':
			case 'X':
			case '^':
			case '=':
			case '+':
			case '-':
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case '.':
				valid = true;
				break;

			default:
				valid = false;
				break;
			}
			if (valid == false)
				break;
		}
		if (valid == true)
		{
			size_t len = e->length(e);
			e->to_lower(e);
			char *format = (char *)calloc(sizeof(char) * (len * 2) + 1, sizeof(char));
			for (size_t i = 0, k = 0; e->str.src[i] != '\0'; i++)
			{
				if (e->str.src[i] == ' ')
					continue;
				if (isDigit(e->str.src[i]) == true)
					format[k++] = e->str.src[i];
				else if (e->str.src[i] == 'x' || e->str.src[i] == '=')
				{
					format[k++] = e->str.src[i];
					if (e->str.src[i + 1] != '^')
						format[k++] = ' ';
				}
				else if (e->str.src[i] == '+' || e->str.src[i] == '-' || e->str.src[i] == '^')
				{
					if (isDigit(e->str.src[i + 1]) == true)
						format[k++] = e->str.src[i];
					else
					{
						format[k++] = e->str.src[i];
						format[k++] = ' ';
					}
				}
				else
					format[k++] = e->str.src[i];
			}
			e->destructor(e);
			init_sstr(e);
			e->set(e, (const char *)format);
			free(format);
			return true;
		}
	}
	return false;
}

struct coefficient parse_eq(sstring *a);
struct coefficient parse_eq(sstring *a)
{
	struct coefficient x = (struct coefficient){.C = INFINITY, .X = INFINITY, .X2 = INFINITY};
	if (a && a->str.src && a->str.init == true)
	{
		sstring buff_x = new_sstring(NULL), buff_y = new_sstring(NULL), buff_c = new_sstring(NULL);
		size_t i = 0, k = 0, j = 0;
		for (; a->str.src[i] != 'x' && a->str.src[i] != '\0'; i++)
			buff_x.append_char(&buff_x, a->str.src[i]);
		while (isDigit(a->str.src[i]) != true && a->str.src[i] != '-' && a->str.src[i] != '+')
			i++;
		for (; a->str.src[i] != '+' && a->str.src[i] != '-' && a->str.src[i] != '\0'; k++)
			buff_y.append_char(&buff_y, a->str.src[i++]);
		if (strtold(buff_y.c_str(&buff_y), (char **)NULL) != 2.0L)
		{
			buff_c.destructor(&buff_c);
			buff_y.destructor(&buff_y);
			buff_x.destructor(&buff_x);
			return x;
		}
		buff_y.clear(&buff_y);
		for (; a->str.src[i] != 'x' && a->str.src[i] != '\0'; k++)
			buff_y.append_char(&buff_y, a->str.src[i++]);
		while (isDigit(a->str.src[i]) != true && a->str.src[i] != '-' && a->str.src[i] != '+')
			i++;
		for (; a->str.src[i] != '\0'; j++)
			buff_c.append_char(&buff_c, a->str.src[i++]);
		x.X = strtold(buff_x.c_str(&buff_x), (char **)NULL);
		x.X2 = strtold(buff_y.c_str(&buff_y), (char **)NULL);
		x.C = strtold(buff_c.c_str(&buff_c), (char **)NULL);
		if (x.X == 0 && a->contains(a, "- x") == true)
			x.X = -1.0L;
		else if (x.X == 0 && a->char_get(a, 0) == 'x')
			x.X = 1;

		if (x.X2 == 0 && a->contains(a, "- x") == true)
			x.X2 = -1.0L;
		else if (x.X2 == 0 && a->contains(a, "+ x") == true)
			x.X2 = 1;
		buff_c.destructor(&buff_c);
		buff_y.destructor(&buff_y);
		buff_x.destructor(&buff_x);
		return x;
	}
	return x;
}

struct sol solve(struct coefficient *x);
struct sol solve(struct coefficient *x)
{
	if (x && x->X != 0.0L)
	{
		struct sol res;
		long double discriminant = ((x->X2 * x->X2) - (4.0L * x->X * x->C));
		if (discriminant < 0)
		{
			res = (struct sol){.X = INFINITY, .Y = INFINITY, .complex_X = INFINITY, .complex_Y = INFINITY, .is_complex = true};
			res.X = -x->X2 / (2 * x->X);
			res.Y = res.X;
			res.complex_X = sqrtl(-discriminant) / (2 * x->X);
			res.complex_Y = -res.complex_X;
			return res;
		}
		else
		{
			res = (struct sol){.X = INFINITY, .Y = INFINITY, .complex_X = 0, .complex_Y = 0, .is_complex = false};
			res.X = ((-1.0L * x->X2) + sqrtl(discriminant)) / (2.0L * x->X);
			res.Y = ((-1.0L * x->X2) - sqrtl(discriminant)) / (2.0L * x->X);
			return res;
		}
	}
	return (struct sol){.X = INFINITY, .Y = INFINITY, .is_complex = true, .complex_X = INFINITY, .complex_Y = INFINITY};
}

int main(void)
{
	sstring eq = new_sstring(NULL);
	printf("Eq. 1\n");
	eq.in(&eq);
	if (format_eq(&eq) == true)
	{
		struct coefficient ans = parse_eq(&eq);
		struct sol res = solve(&ans);
		if (res.is_complex == false)
			printf("[%.2Lf, %.2Lf]\n", res.X, res.Y);
		else
			printf("[(%.2Lf + %.2Lfi), (%.2Lf %.2Lfi)]\n", res.X, res.complex_X, res.Y, res.complex_Y);
		eq.destructor(&eq);
		return 0;
	}
	else
	{
		eq.destructor(&eq);
		return -1;
	}
}