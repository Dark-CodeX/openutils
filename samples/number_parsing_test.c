#include "../sstring/sstring.h"

int main(int argc, char const **argv)
{
    sstring x = new_sstring(1, NULL), num = new_sstring(1, NULL);
    x.set_array(&x, argv, ' ', 1, argc, argc);
    short decimal = 0;
    parse_t parse = x.parse(&x);
    if (parse.type[0] == NULL_END)
    {
        free_parse(&parse);
        x.destructor(&x);
        num.destructor(&num);
        return -1;
    }
    if (parse.type[0] == SPECIAL_CHAR || parse.type[0] == INTEGER)
    {
        for (size_t i = 0; parse.type[i] != NULL_END; i++)
        {
            if (parse.type[i] == SPECIAL_CHAR && strcmp(parse.src[i], ".") == 0)
            {
                decimal++;
                num.append(&num, parse.src[i]);
            }
            if (parse.type[i] == INTEGER || strcmp(parse.src[i], "-") == 0 || strcmp(parse.src[i], "+") == 0)
                num.append(&num, parse.src[i]);
            if (decimal > 1)
            {
                free_parse(&parse);
                x.destructor(&x);
                num.destructor(&num);
                return -1;
            }
        }
    }
    if (decimal == 1)
    {
        long double ans = strtold(num.c_str(&num), (char **)NULL);
        printf("FLOAT: %Lf\n", ans);
    }
    else
    {
        signed long long int ans = strtoll(num.c_str(&num), (char **)NULL, 0xA);
        printf("INTEGER: %lld\n", ans);
    }
    free_parse(&parse);
    x.destructor(&x);
    num.destructor(&num);
    return 0;
}