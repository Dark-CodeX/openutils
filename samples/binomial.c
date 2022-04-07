#include "../sstring/sstring.h"

typedef long double ld;

ld factorial(ld n);
ld factorial(ld n)
{
	if (n == 0)
		return 1;
	return n * factorial(n - 1);
}

ld combination(ld n, ld r);
ld combination(ld n, ld r)
{
	return factorial(n) / (factorial(r) * factorial(n - r));
}

typedef struct expr_storage
{
	char x;
	int sign;
	char y;
	size_t power;
} expr_t;

#define err_expr (expr_t){.x = '\0', .sign = -1, .y = '\0', .power = (size_t)-1};

expr_t format(parse_t *parse);
expr_t format(parse_t *parse)
{
	size_t i = 0, power;
	char x, y;
	int sign;
	while (parse->type[i] == WHITESPACE && i < parse->length)
		i++;
	while (parse->type[i] != NULL_END && i < parse->length)
	{
		if (strcmp(parse->src[i++], "(") == 0)
		{
			while (parse->type[i] == WHITESPACE && i < parse->length)
				i++;
			while (parse->type[i] != WORD && i < parse->length)
				i++;
			if (i < parse->length)
			{
				x = *parse->src[i++];
				while (parse->type[i] == WHITESPACE && i < parse->length)
					i++;
				while (parse->type[i] != SPECIAL_CHAR && i < parse->length)
					i++;
				if (*parse->src[i] == '+')
					sign = true;
				else if (*parse->src[i] == '-')
					sign = false;
				else
					return err_expr;
				while (parse->type[i] != WORD && i < parse->length)
					i++;
				if (i < parse->length)
				{
					y = *parse->src[i++];
					while (strcmp(parse->src[i], ")") != 0 && i < parse->length)
						i++;
					while (strcmp(parse->src[i], "^") != 0 && i < parse->length)
						i++;
					while (parse->type[i] != INTEGER && i < parse->length)
						i++;
					power = strtoul(parse->src[i++], (char **)NULL, 10);
					return (expr_t){.x = x, .sign = sign, .y = y, .power = power};
				}
				else
					return err_expr;
			}
			else
				return err_expr;
		}
		else
			return err_expr;
	}
	return err_expr;
}

sstring solve(expr_t e);
sstring solve(expr_t e)
{
	sstring Q = new_sstring(1, "");
	if (e.x == '\0' || e.y == '\0' || e.sign == -1 || e.power == (size_t)-1)
		return Q;
	short is_odd_term = true;
	for (size_t r = 0; r <= e.power; r++)
	{
		ld comb = combination(e.power, r);
		ld xs_power = e.power - r;
		Q.append_formatted(&Q, 0x3C00, "%.0Lf.%c^(%.0Lf).%c^(%.0Lf) %s", comb, e.x, xs_power, e.y, (ld)r,
						   (e.sign == true && r <= e.power - 1) ? "+ " : ((e.sign == false && r <= e.power - 1) ? ((is_odd_term == true) ? "- " : "+ ") : ""));
		if (!is_odd_term)
			is_odd_term = true;
		else
			is_odd_term = false;
	}
	return Q;
}

int main(void)
{
	sstring exp = new_sstring(1, NULL);
	exp.in(&exp, true, 512);

	parse_t parse = exp.parse(&exp);

	expr_t p = format(&parse);

	sstring q = solve(p);
	q.print(&q, true, "");
	q.destructor(&q);

	exp.destructor(&exp);
	free_parse(&parse);
	return 0;
}