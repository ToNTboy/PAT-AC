#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define lli long long int

lli gcd(lli a, lli b);
lli lcm(lli a, lli b);

typedef struct rnum
{
    lli numerator;
    lli denominator;
    rnum operator+(rnum& b)
    {
        rnum t;
        if (numerator == 0)
            return b;
        if (b.numerator == 0)
            return *this;
        lli tg = gcd(denominator, b.denominator);
        lli tl = denominator*b.denominator/tg;
        t.numerator = numerator*b.denominator/tg + b.numerator*denominator/tg;
        t.denominator = tl;
        if (t.numerator != 0 && (tg = gcd(abs(t.numerator), t.denominator)) != 1)
        {
            t.numerator /= tg;
            t.denominator /= tg;
        }
        return t;
    }
} rnum;

lli gcd(lli a, lli b)
{
    lli t;
    if (a < b)
    {
        t = a;
        a = b;
        b = t;
    }
    if (a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}

int n;
rnum rs[101];

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%lld/%lld", &rs[i].numerator, &rs[i].denominator);
    }
    rnum sum = {0, 0};
    for (int i=0; i<n; i++)
    {
        sum = sum + rs[i];
    }
    if (sum.numerator == 0)
    {
        printf("0\n");
    }
    else
    {
        if (sum.numerator < 0)
            printf("-");
        if (abs(sum.numerator) >= sum.denominator)
        {
            printf("%lld", abs(sum.numerator) / sum.denominator);
        }
        if (abs(sum.numerator) % sum.denominator != 0)
        {
            if (abs(sum.numerator) > sum.denominator)
                printf(" ");
            printf("%lld/%lld", abs(sum.numerator) % sum.denominator, sum.denominator);
        }
        printf("\n");
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}
