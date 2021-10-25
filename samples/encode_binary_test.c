#include "../sstring/sstring.h"

int main(int argc, char const *argv[])
{
    if (argc == 4)
    {
        SSTRING(x);
        SIZE_T len = 0;
        if ((len = x.open_binary(&x, argv[1])) == 0)
        {
            printf("could not find `%s`.\n", argv[1]);
            x.destructor(&x);
            return -1;
        }
        if (strcmp(argv[2], "-o") != true)
        {
            printf("not found `-o` instead found `%s`.\n", argv[2]);
            x.destructor(&x);
            return -1;
        }
        SSTRING(y);
        printf("message:\n");
        y.in(&y, true, 0x100000ULL);
        len += x.add_binary(&x, y.c_str(&y), len);
        if (x.save_binary(&x, argv[3], len) != true)
        {
            printf("`%s` was not found or could not save the file.\n", argv[3]);
            x.destructor(&x);
            y.destructor(&y);
            return -1;
        }
        printf("File saved at `%s`.\n", argv[3]);
        x.destructor(&x);
        y.destructor(&y);
        return 0;
    }
    printf("invalid or empty input\n");
    return -1;
}