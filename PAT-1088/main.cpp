#include <bits/stdc++.h>

using namespace std;

#define LOCAL
#define lli long long int

char INF[4] = "Inf";
char ZERO[2] = "0";

lli gcd(lli a, lli b);

typedef struct rnum
{
    lli numerator;
    lli denominator;
    rnum operator+(rnum b)
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
    rnum operator-(rnum b)
    {
        b.numerator = -b.numerator;
        return (*this) + b;
    }
    rnum operator*(rnum b)
    {
        rnum t;
        if (numerator == 0)
            return *this;
        if (b.numerator == 0)
            return b;
        t.numerator = numerator * b.numerator;
        t.denominator = denominator * b.denominator;
        lli tg = gcd(abs(t.numerator), t.denominator);
        if (tg != 1)
        {
            t.numerator /= tg;
            t.denominator /= tg;
        }
        return t;
    }
    rnum operator/(rnum b)
    {
        rnum t;
        if (b.numerator == 0 || b.denominator == 0)
        {
            t.denominator = 0;
            return t;
        }
        if (numerator == 0)
            return *this;
        lli tmp = b.numerator;
        b.numerator = b.denominator;
        b.denominator = tmp;
        if (tmp < 0)
        {
            b.numerator = -b.numerator;
            b.denominator = -b.denominator;
        }
        return (*this)*b;
    }
} rnum;

void simple(rnum& r)
{
    if (r.numerator == 0)
        return;
    lli tg = gcd(abs(r.numerator), r.denominator);
    if (tg != 1)
    {
        r.numerator /= tg;
        r.denominator /= tg;
    }
}

char * str(rnum& r)
{
    if (r.denominator == 0)
        return INF;
    if (r.numerator == 0)
        return ZERO;

    char *s = new char[100];
    char *c = s;
    if (r.numerator < 0)
    {
        c[0] = '(';
        c[1] = '-';
        c += 2;
    }
    if (abs(r.numerator) >= r.denominator)
    {
        c += sprintf(c, "%lld", abs(r.numerator) / r.denominator);
    }
    if (abs(r.numerator) % r.denominator != 0)
    {
        if (abs(r.numerator) > r.denominator)
        {
            c[0] = ' ';
            c++;
        }
        c += sprintf(c, "%lld/%lld", abs(r.numerator) % r.denominator, r.denominator);
    }
    if (r.numerator < 0)
    {
        c[0] = ')';
        c++;
    }
    c[0] = '\0';
    return s;
}

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


int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    rnum a, b;
    scanf("%lld/%lld", &a.numerator, &a.denominator);
    scanf("%lld/%lld", &b.numerator, &b.denominator);
    simple(a);
    simple(b);
    rnum r1 = a+b;
    rnum r2 = a-b;
    rnum r3 = a*b;
    rnum r4 = a/b;
    printf("%s + %s = %s\n", str(a), str(b), str(r1));
    printf("%s - %s = %s\n", str(a), str(b), str(r2));
    printf("%s * %s = %s\n", str(a), str(b), str(r3));
    printf("%s / %s = %s\n", str(a), str(b), str(r4));

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}
