#include <cstdio>

using namespace std;

#define LOCAL
#define MAXN 10000

char isign, esign;
char integer, frac[MAXN];
int exp, fraclen;
bool zero = true;

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    int i = 0;
    char t;
    scanf("%c%c.", &isign, &integer);
    if (integer != '0')
        zero = false;
    while (scanf("%c", &t) != EOF)
    {
        if (t == 'E')
            break;
        if (t != '0')
            zero = false;
        frac[i++] = t;
    }
    frac[i] = '\0';
    fraclen = i;
    scanf("%c%d\n", &esign, &exp);

    if (zero)
    {
        printf("0.%s\n", frac);
        return 0;
    }
    if (isign == '-')
        printf("-");
    if (exp == 0)
    {
        printf("%c.%s\n", integer, frac);
    }
    else
    {
        if (esign == '-')
        {
            printf("0.");
            for (i=0; i<exp-1; i++)
            {
                printf("0");
            }
            printf("%c%s", integer, frac);
        }
        else
        {
            bool prezero = true;
            if (integer != '0')
            {
                printf("%c", integer);
                prezero = false;
            }
            for (i=0; i<exp && i<fraclen; i++)
            {
                if (prezero && frac[i] == '0')
                    continue;
                prezero = false;
                printf("%c", frac[i]);
            }
            if (i < exp)
            {
                for (i; i<exp; i++)
                {
                    printf("0");
                }
            }
            if (i < fraclen)
            {
                printf(".");
                for (i; i< fraclen; i++)
                {
                    printf("%c", frac[i]);
                }
            }
        }
    }
    printf("\n");

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}
