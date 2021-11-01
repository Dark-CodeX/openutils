#include "../sstring/sstring.h"

static const char *tokens[] =
    {
        "WORD",
        "INTEGER",
        "ESC_SEQ",
        "SPECIAL_CHAR",
        "WHITESPACE}"};

int main(void)
{
    sstring x = new_sstring(0, NULL);
    x.open(&x, "linear_eq_test.c");
    parse_t p = x.parse(&x);
    for (SIZE_T i = 0; i < p.length; i++)
        printf("[STR = `%s`, TYPE = `%s`] => %llu of %llu\n", p.src[i], tokens[p.type[i]], i + 1, p.length);
    free_parse(&p);
    x.destructor(&x);
    return 0;
}