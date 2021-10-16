#include "sstring/sstring.h"

/** KIND OF TUPLE */
struct coefficient
{
    long double X;
    long double Y;
    long double C;
};

/** KIND OF TUPLE */
struct sol
{
    long double X;
    long double Y;
};

long double ABS(long double __x);
long double ABS(long double __x) // just for long double, otherwise use in-built `abs()` function
{
    if (__x < 0)
        return __x * (-1.0L);
    return __x;
}

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
        for (SIZE_T i = 0; e->str.src[i] != '\0'; i++)
        {
            switch (e->str.src[i])
            {
            case 'x':
            case 'y':
            case 'X':
            case 'Y':
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
            SIZE_T len = e->length(e);
            e->to_lower(e);
            char *format = (char *)calloc(sizeof(char) * (len * 2) + 1, sizeof(char));
            for (SIZE_T i = 0, k = 0; e->str.src[i] != '\0'; i++)
            {
                if (e->str.src[i] == ' ')
                    continue;
                if (isDigit(e->str.src[i]) == true)
                    format[k++] = e->str.src[i];
                else if (e->str.src[i] == 'x' || e->str.src[i] == 'y' || e->str.src[i] == '=')
                {
                    format[k++] = e->str.src[i];
                    format[k++] = ' ';
                }
                else if (e->str.src[i] == '+' || e->str.src[i] == '-')
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
    struct coefficient x = (struct coefficient){.C = 0, .X = 0, .Y = 0};
    if (a && a->str.src && a->str.init == true)
    {
        char *buff_x = (char *)calloc(sizeof(char) * 64, sizeof(char)), *buff_y = (char *)calloc(sizeof(char) * 64, sizeof(char)), *buff_c = (char *)calloc(sizeof(char) * 64, sizeof(char));
        SIZE_T i = 0, k = 0, j = 0;
        for (; a->str.src[i] != 'x'; i++)
            buff_x[i] = a->str.src[i];
        while (isDigit(a->str.src[i]) != true && a->str.src[i] != '-' && a->str.src[i] != '+')
            i++;
        for (; a->str.src[i] != 'y'; k++)
            buff_y[k] = a->str.src[i++];
        while (isDigit(a->str.src[i]) != true && a->str.src[i] != '-' && a->str.src[i] != '+')
            i++;
        for (; a->str.src[i] != '\0'; j++)
            buff_c[j] = a->str.src[i++];
        x.X = strtold((const char *)buff_x, (char **)NULL);
        x.Y = strtold((const char *)buff_y, (char **)NULL);
        x.C = strtold((const char *)buff_c, (char **)NULL);
        if (x.X == 0 && a->contains(a, "- x") == true)
            x.X = -1.0L;
        else if (x.X == 0 && a->char_get(a, 0) == 'x')
            x.X = 1;

        if (x.Y == 0 && a->contains(a, "- y") == true)
            x.Y = -1.0L;
        else if (x.Y == 0 && a->contains(a, "+ y") == true)
            x.Y = 1;
        free(buff_c);
        free(buff_y);
        free(buff_x);
        return x;
    }
    return x;
}

struct sol solve(struct coefficient *m1, struct coefficient *m2);
struct sol solve(struct coefficient *m1, struct coefficient *m2)
{
    struct sol ans = (struct sol){.X = (long double)INFINITY, .Y = (long double)INFINITY};
    if (m1 && m2 && (m1->X / m2->X != m1->Y / m2->Y))
    {
        // elimination method
        long double temp_m1_x = ABS(m1->X); // not to change sign
        long double temp_m2_x = ABS(m2->X); // not to change sign
        m1->X *= temp_m2_x, m1->Y *= temp_m2_x, m1->C *= temp_m2_x;
        m2->X *= temp_m1_x, m2->Y *= temp_m1_x, m2->C *= temp_m1_x;
        if (m1->X + m2->X == 0 || m1->X - m2->X == 0)
        {
            // now x is eliminated, now change sign
            m2->Y *= -1;
            m2->C *= -1;
            ans.Y = (m1->C + m2->C) / (m1->Y + m2->Y);
            ans.X = (m1->C - (m1->Y * ans.Y)) / m1->X;
        }
        return ans;
    }
    return ans;
}

int main(void)
{
    sstring eq1 = new_sstring(NULL);
    sstring eq2 = new_sstring(NULL);
    printf("Eq. 1:\n");
    eq1.in(&eq1, true, 512);
    printf("Eq. 2:\n");
    eq2.in(&eq2, true, 512);
    if (format_eq(&eq1) == true && format_eq(&eq2) == true)
    {
        if (eq1.compare(&eq1, eq2.c_str(&eq2)) == true)
        {
            printf("both eqations are same, having infinitely many solutions.\n");
            eq1.destructor(&eq1);
            eq2.destructor(&eq2);
            return -1;
        }
        struct coefficient ans = parse_eq(&eq1);
        struct coefficient ans2 = parse_eq(&eq2);
        struct sol result = solve(&ans, &ans2);

        printf("[X: %Lf, Y: %Lf]\n", result.X, result.Y);
        eq1.destructor(&eq1);
        eq2.destructor(&eq2);
        return 0;
    }
    printf("could not format the equation `%s`.\n", (format_eq(&eq1) == false) ? eq1.c_str(&eq1) : eq2.c_str(&eq2));
    eq1.destructor(&eq1);
    eq2.destructor(&eq2);
    return -1;
}