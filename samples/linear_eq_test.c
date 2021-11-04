#include "../sstring/sstring.h"

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
    if (e && (*(__str__ *)e->str).src && (*(__str__ *)e->str).init == true)
    {
        e->remove_char(e, ' ');
        short valid = false;
        for (SIZE_T i = 0; (*(__str__ *)e->str).src[i] != '\0'; i++)
        {
            switch ((*(__str__ *)e->str).src[i])
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
            for (SIZE_T i = 0, k = 0; (*(__str__ *)e->str).src[i] != '\0'; i++)
            {
                if ((*(__str__ *)e->str).src[i] == ' ')
                    continue;
                if (isDigit((*(__str__ *)e->str).src[i]) == true)
                    format[k++] = (*(__str__ *)e->str).src[i];
                else if ((*(__str__ *)e->str).src[i] == 'x' || (*(__str__ *)e->str).src[i] == 'y' || (*(__str__ *)e->str).src[i] == '=')
                {
                    format[k++] = (*(__str__ *)e->str).src[i];
                    format[k++] = ' ';
                }
                else if ((*(__str__ *)e->str).src[i] == '+' || (*(__str__ *)e->str).src[i] == '-')
                {
                    if (isDigit((*(__str__ *)e->str).src[i + 1]) == true)
                        format[k++] = (*(__str__ *)e->str).src[i];
                    else
                    {
                        format[k++] = (*(__str__ *)e->str).src[i];
                        format[k++] = ' ';
                    }
                }
                else
                    format[k++] = (*(__str__ *)e->str).src[i];
            }
            e->destructor(e);
            init_sstr(e, 1);
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
    if (a && (*(__str__ *)a->str).src && (*(__str__ *)a->str).init == true)
    {
        sstring buff_x = new_sstring(1, NULL), buff_y = new_sstring(1, NULL), buff_c = new_sstring(1, NULL);
        SIZE_T i = 0, k = 0, j = 0;
        for (; (*(__str__ *)a->str).src[i] != 'x' && (*(__str__ *)a->str).src[i] != '\0'; i++)
            buff_x.append_char(&buff_x, (*(__str__ *)a->str).src[i]);
        while (isDigit((*(__str__ *)a->str).src[i]) != true && (*(__str__ *)a->str).src[i] != '-' && (*(__str__ *)a->str).src[i] != '+')
            i++;
        for (; (*(__str__ *)a->str).src[i] != 'y' && (*(__str__ *)a->str).src[i] != '\0'; k++)
            buff_y.append_char(&buff_y, (*(__str__ *)a->str).src[i++]);
        while (isDigit((*(__str__ *)a->str).src[i]) != true && (*(__str__ *)a->str).src[i] != '-' && (*(__str__ *)a->str).src[i] != '+')
            i++;
        for (; (*(__str__ *)a->str).src[i] != '\0'; j++)
            buff_c.append_char(&buff_c, (*(__str__ *)a->str).src[i++]);
        x.X = strtold(buff_x.c_str(&buff_x), (char **)NULL);
        x.Y = strtold(buff_y.c_str(&buff_y), (char **)NULL);
        x.C = strtold(buff_c.c_str(&buff_c), (char **)NULL);
        if (x.X == 0 && a->contains(a, "- x") == true)
            x.X = -1.0L;
        else if (x.X == 0 && a->char_get(a, 0) == 'x')
            x.X = 1;

        if (x.Y == 0 && a->contains(a, "- y") == true)
            x.Y = -1.0L;
        else if (x.Y == 0 && a->contains(a, "+ y") == true)
            x.Y = 1;
        buff_c.destructor(&buff_c);
        buff_y.destructor(&buff_y);
        buff_x.destructor(&buff_x);
        return x;
    }
    return x;
}

struct sol solve(struct coefficient *m1, struct coefficient *m2, int showSetps);
struct sol solve(struct coefficient *m1, struct coefficient *m2, int showSetps)
{
    struct sol ans = (struct sol){.X = (long double)INFINITY, .Y = (long double)INFINITY};
    if (m1 && m2 && (m1->X / m2->X != m1->Y / m2->Y))
    {
        // elimination method
        long double temp_m1_x = ABS(m1->X); // not to change sign
        long double temp_m2_x = ABS(m2->X); // not to change sign
        m1->X *= temp_m2_x, m1->Y *= temp_m2_x, m1->C *= temp_m2_x;
        m2->X *= temp_m1_x, m2->Y *= temp_m1_x, m2->C *= temp_m1_x;
        if (showSetps == true)
        {
            printf("\nSTEP: 1 => multiplying eq1 with %.2Lf and eq2 with %.2Lf, to eliminate `x`.\n", temp_m2_x, temp_m1_x);
            printf("eq1:\t%.2Lfx%s%.2Lfy = %.2Lf\n", m1->X, (m1->Y < 0) ? " " : " + ", m1->Y, m1->C);
            printf("eq2:\t%.2Lfx%s%.2Lfy = %.2Lf\n", m2->X, (m2->Y < 0) ? " " : " + ", m2->Y, m2->C);
        }
        if (m1->X + m2->X == 0 || m1->X - m2->X == 0)
        {
            // now x is eliminated, now change sign
            m2->Y *= -1;
            m2->C *= -1;
            if (showSetps == true)
            {
                printf("\nSTEP: 2 => now `x` is eliminated, so now substract eq2 from eq1.\n");
                int delta1 = printf("eq1:\t%.2Lfy = %.2Lf\n", m1->Y, m1->C);
                int delta2 = printf("eq2:\t%.2Lfy = %.2Lf\n", m2->Y, m2->C);
                if (delta1 >= delta2)
                    for (int i = 0; i < delta1 + 3; i++)
                        printf("-");
                else
                    for (int i = 0; i < delta2 + 3; i++)
                        printf("-");
                printf("\neq2 - eq1 => %.2Lfy = %.2Lf\n", m1->Y + m2->Y, m1->C + m2->C);
            }
            ans.Y = (m1->C + m2->C) / (m1->Y + m2->Y);
            if (showSetps == true)
            {
                printf("\nSTEP: 3 => now divide constant `c` with coefficient of `y`, to get the value of `y`.\n");
                printf("y = %.2Lf / %.2Lf\t=> y = %.2Lf\n", (m1->C + m2->C), (m1->Y + m2->Y), ans.Y);
            }
            ans.X = (m1->C - (m1->Y * ans.Y)) / m1->X;
            if (showSetps == true)
            {
                printf("\nSTEP: 4 => we got our value of `y`, now just put the value of `y` in eq1. So,\n");
                printf("x = (%.2Lf - (%.2Lf * %.2Lf)) / %.2Lf\t=> x = %.2Lf\n", m1->C, m1->Y, ans.Y, m1->X, ans.X);
            }
        }
        return ans;
    }
    return ans;
}

int main(int argc, char const **argv)
{
    sstring eq1 = new_sstring(1, NULL);
    sstring eq2 = new_sstring(1, NULL);
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
        int steps = false;
        if (argc == 2)
            if (strcmp(argv[1], "true") == 0)
                steps = true;
        struct sol result = solve(&ans, &ans2, steps);

        printf("[X: %.2Lf, Y: %.2Lf]\n", result.X, result.Y);
        eq1.destructor(&eq1);
        eq2.destructor(&eq2);
        return 0;
    }
    printf("could not format the equation `%s`.\n", (format_eq(&eq1) == false) ? eq1.c_str(&eq1) : eq2.c_str(&eq2));
    eq1.destructor(&eq1);
    eq2.destructor(&eq2);
    return -1;
}